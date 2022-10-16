#include <stdio.h>
#include <string.h> 
#include <queue>
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
	int v,nxt;
}e[2000005];
int h[200005],cnt=2;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int d[200005];
inline int min(int a,int b)
{
    return a<b?a:b;
}
int G[200005];
int dfs(int u)
{
    if(G[u])return G[u];
    int ans=d[u];
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(d[v]>d[u])ans=min(ans,dfs(v));
        else ans=min(ans,d[v]);
    }
    return G[u]=ans;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read(),m=read(),s=1;
        cnt=1;
        memset(h,0,sizeof(int)*(n+3));
        memset(G,0,sizeof(int)*(n+3));
        memset(d,0,sizeof(int)*(n+3));
        while(m--)
        {
            int x=read(),y=read();
            addedge(x,y);
        }
        std::queue<int> q;
        q.push(s);
        d[s]=1;
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=h[u];i;i=e[i].nxt)
            {
                int v=e[i].v;
                if(d[v])continue;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
        for(int i=1;i<=n;i++)printf("%d ",dfs(i)-1);
        puts("");
    }
}