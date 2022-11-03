#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,i,j,k,u,v;
int col[100005],son[100005],next[100005];
long long f[100005],g[100005];

void dfs(int x)
{
    if(col[x]==0)f[x]=1;else g[x]=1;
    for(int i=son[x];i;i=next[i])
    {
        dfs(i);
        g[x]=(g[x]*(f[i]+g[i])%p+f[x]*g[i]%p)%p;
        f[x]=f[x]*(f[i]+g[i])%p;
    }
}

int main()
{
    scanf("%d",&n);
    for(i=2;i<=n;++i)
    {
        scanf("%d",&u);++u;
        next[i]=son[u];son[u]=i;
    }
    for(i=1;i<=n;++i)scanf("%d",&col[i]);
    dfs(1);
    printf("%I64d\n",g[1]);
}