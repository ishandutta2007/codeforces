/*
ID: Sfiction
OJ: CF
PROB: 452C
*/
#include <cstdio>

int main(){
    int n,m;
    int i,j;
    double ans,t;
    scanf("%d%d",&n,&m);
    ans=0;
    for (i=1;i<=n && i<=m;++i){
        t=(double)(i*i);
        for (j=0;j<i;++j){
            t*=(double)(m-j);
            t/=(double)(n*m-j);
        }
        for (j=i;j<n;++j){
            t*=(double)((n-1)*m-j+i);
            t/=(double)(j-i+1);
            t*=(double)(j+1);
            t/=(double)(n*m-j);
        }
        ans+=t;
    }
    ans/=(double)n;
    printf("%.18lf",ans);
    return 0;
}