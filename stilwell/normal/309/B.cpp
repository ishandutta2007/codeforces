#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n,r,c,i,j,k,ans;
int l[1000005],len[1000005],sum[1000005];
int f[1000005],g[1000005],gg[1000005];
char s[10000005];

void dfs(int x,int y)
{
    if(!x)return;
    if(!f[y])return;
    dfs(x-1,f[y]-1);
    for(int i=f[y];i<=y;++i)
    {
        printf("%s",s+l[i]);
        if(i!=y)printf(" ");
        else printf("\n");
    }
}

int main()
{
    scanf("%d%d%d",&n,&r,&c);
    for(i=1;i<=n;++i)
    {
        k+=2;
        scanf("%s",s+k);
        l[i]=k;len[i]=strlen(s+k);
        k+=len[i];
    }
    for(i=1;i<=n;++i)sum[i]=sum[i-1]+len[i];
    for(i=1;i<=n;++i)
    if(len[i]<=c)
    {
        if(f[i-1])
        {
            f[i]=f[i-1];
            for(;sum[i]-sum[f[i]-1]+i-f[i]>c;++f[i]);
        }else f[i]=i;
    }
    for(i=1;i<=n;++i)g[i]=gg[i]=f[i];
    for(i=r-1;i;i>>=1)
    {
        if(i&1)
        {
            for(j=n;j>=1;--j)
            if(g[j]&&gg[g[j]-1])g[j]=gg[g[j]-1];
        }
        for(j=n;j>=1;--j)
        if(gg[j]&&gg[gg[j]-1])gg[j]=gg[gg[j]-1];
    }
    for(i=1;i<=n;++i)
    if(g[i]&&i-g[i]+1>ans)
    ans=i-g[i]+1;
    for(i=1;i<=n;++i)
    if(g[i]&&i-g[i]+1==ans)
    break;
    dfs(r,i);
}