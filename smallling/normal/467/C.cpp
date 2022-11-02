#include<stdio.h>
#include<algorithm>

using namespace std;

int n,m,k,a[5010];
long long ans,sum[5010],g[5010],f[5010][5010];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum[i]=sum[i-1]+1ll*a[i];
    for(int i=1;i<=k;i++)
    {
        for(int j=i*m;j<=n;j++)
            f[i][j]=g[j-m]+sum[j]-sum[j-m];
        for(int j=1;j<=n;j++)
            g[j]=max(g[j-1],f[i][j]);
    }
    for(int i=k*m;i<=n;i++)
        ans=max(ans,f[k][i]);
    printf("%I64d",ans);
}