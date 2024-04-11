#include<cstdio>
#include<algorithm>

using namespace std;

int n,i,j,k,ans,f[5010][5010],a[5010];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]=0x3f3f3f3f;
    f[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        k=min(a[i],n);
        for(int j=0;j<=k;j++)
            f[i][j]=f[i-1][j];
        for(int j=1;j<=k;j++)
            f[i][j]=min(f[i][j],f[i][j-1]+1);
        for(int j=0;j<=k;j++)
            f[i][j]+=j!=a[i];
        for(int j=k-1;j>=0;j--)
            f[i][j]=min(f[i][j],f[i][j+1]);
    }
    ans=0x7f7f7f7f;
    for(int i=0;i<=n;i++)
        ans=min(ans,f[n][i]);
    printf("%d\n",ans);
}