#include <cstdio>
#define eps 1e-6
int a[1005],b[1005];
int n;
double m;
int main(){
    scanf("%d%lf",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1]=a[1];
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    b[n+1]=b[1];
    double ans=0.0;
    for(int i=n+1;i>1;i--){
        ans=(b[i]*ans+m)/(b[i]-1);
        ans=(a[i-1]*ans+m)/(a[i-1]-1);
    }
    if(ans-1000000000.0>eps){
        return puts("-1"),0;
    }
    printf("%.10lf\n",ans);
    return 0;
}
/*
x=x_last-(x_last+m)/a
a*x=(a-1)*x_last-m
x_last=(a*x+m)/(a-1)
*/