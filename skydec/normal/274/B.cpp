#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL data[MAXN],up[MAXN],down[MAXN];
int n;
int head[MAXN],next[MAXN*2],p[MAXN*2],fa[MAXN];int tot=0;
void line(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void dfs(int x)
{
     LL ups,downs;ups=0;downs=0;
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])
     {
                    fa[p[u]]=x;
                    dfs(p[u]);
                    if(up[p[u]]>ups)ups=up[p[u]];
                    if(down[p[u]]>downs)downs=down[p[u]];
                    }
     LL pk=data[x]+ups-downs;
     if(pk<0)up[x]=-pk;
     else down[x]=pk;
     up[x]+=ups;
     down[x]+=downs;
}
                    
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            line(a,b);line(b,a);
            }
    for(int i=1;i<=n;i++)scanf("%I64d",&data[i]);
    dfs(1);
    LL ans=0;
    ans=down[1]+up[1];
    printf("%I64d\n",ans);
    return 0;
}