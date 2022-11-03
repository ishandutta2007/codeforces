/*
ID: Sfiction
OJ: CF
PROB: 453A
*/
#include <cstdio>

int m,n;

double exp(double e,int n){
    double ret=1.0;
    e/=(double)m;
    for (;n;n>>=1){
        if (n&1)
            ret*=e;
        e*=e;
    }
    return ret;
}

int main(){
    int i;
    double ans;

    scanf("%d%d",&m,&n);
    ans=0;
    for (i=1;i<=m;++i)
        ans+=(double)i*(exp((double)i,n)-exp((double)(i-1),n));
    printf("%.12lf",ans);
    return 0;
}