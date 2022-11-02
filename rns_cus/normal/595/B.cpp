#include <stdio.h>
#include <string.h>

#define M 100000
#define mod 1000000007

int a[M],b[M],c[M],d[M],p[M];
int n,k;

int f(int x) {
    int bf=0;
    while(x) {
        bf = x%10;
        x/=10;
    }
    return bf;
}


main(){
    p[0] = 1;
    for(int i=1;i<M;i++)p[i] =p[i-1] * 10;
    ///freopen("1.in","r",stdin);
    scanf("%d %d",&n,&k);
    int  m = n/k;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&b[i]);
    int ans = 1;
    for(int i=1;i<=m;i++) {
        int tp = 0;
        if(k == 1) {
            for(int j=0;j<=9;j++) if(j!=b[i]&&j%a[i]==0) tp++;
        }
        else {
            tp = (p[k]-1)/ a[i] + 1;
            int x = 1ll * b[i] * p[k-1] % a[i];
            x = (a[i] -x) % a[i];
            if(p[k-1] - 1 >= x) tp -= (p[k-1]-1-x)/a[i] + 1;
        }
        ans = 1ll * ans * tp % mod;
    }
    printf("%d\n",ans);
}