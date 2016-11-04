#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    float a[100],p,q,e,b[100],c[100],r,s,d,x1,x2;
    int n,i,k;
    scanf("%d",&n);
    for(i=0;i<=n;i++)
        scanf("%f",&a[i]);
    while(n>2){
        scanf("%f%f%f",&p,&q,&e);
        do{
            b[0]=a[0];
            b[1]=a[1]-p*b[0];
            for(k=2;k<=n;k++)
                b[k]=a[k]-p*b[k-1]-q*b[k-2];
            c[0]=b[0];
            c[1]=b[1]-p*c[0];
            for(k=2;k<=n-1;k++)
                c[k]=b[k]-p*c[k-1]-q*c[k-2];
            d=c[n-2]*c[n-2]-c[n-1]*c[n-3]+b[n-1]*c[n-3];
            r=b[n]*c[n-3]-b[n-1]*c[n-2];
            s=b[n-1]*c[n-1]-b[n-1]*b[n-1]-b[n]*c[n-2];
            p=p-r/d;
            q=q-s/d;
        }while(fabs((r+s)/d)>e);
        printf("\np=%f q=%f ",p,q);
        if(p*p-4*q>=0){
            x1=(-p-sqrt(p*p-4*q))/2;
            x2=(-p+sqrt(p*p-4*q))/2;
            printf("\nx1=%f x2=%f",x1,x2);
        }else{
            printf("\nx1=%f-i%f",-p/2,sqrt(4*q-p*p)/2);
            printf("\nx1=%f+i%f",-p/2,sqrt(4*q-p*p)/2);
        }
        n=n-2;
        for(k=0;k<=n;k++)
            a[k]=b[k];
    }
    if(n==1){
        printf("\nSe obtine un factor liniar %fx+%f cu solutia x1=%f",b[0],b[1],-b[1]/b[0]);
    }else{
        printf("\nSe obtine un factor patratic %fx^2+%fx+%f",b[0],b[1],b[2]);
        if(b[1]*b[1]-4*b[0]*b[2]>=0){
            x1=-(-b[1]-sqrt(b[1]*b[1]-4*b[0]*b[2]))/2*b[0];
            x2=-(-b[1]+sqrt(b[1]*b[1]-4*b[0]*b[2]))/2*b[0];
            printf("\nx1=%f x2=%f",x1,x2);
        }else{
            printf("\nx1=%f-i%f",-b[1]/2*b[0],sqrt(4*b[0]*b[2]-b[1]*b[1])/2*b[0]);
            printf("\nx2=%f+i%f",-b[1]/2*b[0],sqrt(4*b[0]*b[2]-b[1]*b[1])/2*b[0]);
        }
    }
    return 0;
}
