#include<stdio.h>
#include<cstring>
#define MAXN 160005
using namespace std;
typedef long long LL;
int head[MAXN],next[MAXN],p[MAXN],fa[MAXN];
int size[MAXN];int tot=0;
int n;LL ans=0;
void l(int a,int b)
{
     tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;
}
void dfs(int x)
{
     size[x]=1;LL inpath=0;
     for(int u=head[x];u;u=next[u])
     if(p[u]!=fa[x])
     {
                    fa[p[u]]=x;dfs(p[u]);
                    inpath+=size[x]*size[p[u]];
                    size[x]+=size[p[u]];
                    }
     ans-=inpath*(inpath+2ll*size[x]*1ll*(n-size[x]));
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
            int a,b;scanf("%d%d",&a,&b);
            l(a,b);l(b,a);
            }
    ans=n*1ll*(n-1)/2;ans*=ans;
    dfs(1);
    printf("%I64d\n",ans);
    return 0;
}