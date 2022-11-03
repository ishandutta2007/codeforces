/*
ID: Sfiction
OJ: CF
PROB: 467C
*/
#include <cstdio>

const int MAXN=5000+10;

int n,m,k;
int num[MAXN];
long long sum[MAXN];

long long dp[2][MAXN];

void Init(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;++i)
        scanf("%d",&num[i]);
    for (int i=1;i<=m;++i)
        sum[m]+=num[i];
    for (int i=m+1;i<=n;++i)
        sum[i]=sum[i-1]+num[i]-num[i-m];
}

void Work(int start,long long (&a)[MAXN],long long (&b)[MAXN]){
    for (int i=0;i<start;++i)
        b[i]=0;
    for (int i=start;i<=n;++i)
        b[i]=a[i-m]+sum[i]>b[i-1] ? a[i-m]+sum[i] : b[i-1];
}

int main(){
    Init();
    for (int i=1;i<=k;++i)
        Work(i*m,dp[(i-1)&1],dp[i&1]);
    printf("%I64d",dp[k&1][n]);
    return 0;
}