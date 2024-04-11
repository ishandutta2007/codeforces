#include<stdio.h>
#include<cstring>
#define MAXN 5005
using namespace std;
typedef long long LL;
int n,m,k;
LL sum[MAXN];
LL f[MAXN][2];
LL mm[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){scanf("%I64d",&sum[i]);sum[i]+=sum[i-1];}
    int now=0;
    for(int i=1;i<=k;i++)
    {
            now^=1;for(int j=1;j<=n;j++)f[j][now]=-(1e15);
            for(int j=m;j<=n;j++)
            f[j][now]=mm[j-m]+sum[j]-sum[j-m];
            mm[1]=f[1][now];
            for(int j=2;j<=n;j++)
            if(f[j][now]>mm[j-1])mm[j]=f[j][now];else mm[j]=mm[j-1];
            }
    LL ans=-1;
    for(int i=1;i<=n;i++)
    if(f[i][now]>ans)ans=f[i][now];
    printf("%I64d\n",ans);
    return 0;
}