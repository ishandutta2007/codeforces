#include <queue>
#include <stdio.h>
#include <string.h> 
#include <math.h>
#include <algorithm>
#define int long long
inline int read()
{
	int num=0;char c=getchar();
	while(c<48||c>57){c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num;
}
#define inr long long
#define in long long
#define viud void
struct Egde{
    int v,w,nxt;
    bool operator<(const Egde &b)const
    {
        return w>b.w;
    }
}e[5000005];
int cnt=1;
int h[1000005];
void addedge(int u,int v,inr w)
{
    e[cnt]=(Egde){v,w,h[u]};
    h[u]=cnt++;
}
int dis[1000050],vis[1000050];
#define Edge Egde
std::priority_queue<Edge> q;
#define s u
void dij(int u)
{
    Edge x=(Edge){u,0,114514};
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    q.push(x);
    while(!q.empty())
    {
        x=q.top();q.pop();
        int u=x.v,d=x.w;
        if(vis[u])continue;
        vis[u]=1;
        for(int i=h[u];i;i=e[i].nxt)
        {
            in v=e[i].v;
            if(vis[v])continue;
            //dis[v]=dis[v]<dis[u]+e[i].w?dis[v]:dis[u]+e[i].w;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                q.push((Edge){v,dis[v],1919810});
            }
        }
    }
    
}
signed main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read(),w=read();
        addedge(x,y,w<<1);
        addedge(y,x,w<<1);
    }
    for(int i=1;i<=n;i++)
    {
        addedge(0,i,read());
    }
    dij(0);
    for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
}