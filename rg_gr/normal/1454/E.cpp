#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
struct Edge{
    int u,v,nxt;
}e[1000500];
int h[200005],cnt=1;
inline void addedge(int u,int v)
{
    e[cnt]=(Edge){u,v,h[u]};
    h[u]=cnt++;
}
 
int vis[200005],o[200005];
int c,a[200005],U;
int dfs(int u,int fa)
{
    a[++c]=u;o[u]=1;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==fa)continue;
        if(o[v]){vis[u]=1;U=v;return 1;}
        if(dfs(v,u)){vis[u]=1;return (U^u);}
    }
    //puts("hi");
    return 0;
}
int V[200005];
int dfs(int u)
{
    int p=1;V[u]=1;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!V[v]&&!vis[v])p+=dfs(v);
    }
    return p;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),m=n;
        memset(h,0,sizeof(int)*(n+3));
        memset(vis,0,sizeof(int)*(n+3));
        memset(V,0,sizeof(int)*(n+3));
        memset(o,0,sizeof(int)*(n+3));
        cnt=1;
        for(int i=1;i<=m;i++)
        {
            int x=read(),y=read();
            addedge(x,y);addedge(y,x);
        }
        dfs(1,-1);int ans=n*(n-1);
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                int p=dfs(i);
                //printf("%lld ppp\n",p);
                ans-=(p-1)*p/2;
            }
        }
        printf("%lld\n",ans);
    }
}