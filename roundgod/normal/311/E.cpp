#include<bits/stdc++.h>
#define MAXN 10005
#define MAXV 20005
#define MAXE 50000
#define INF 1000000000
using namespace std;
struct edge{int to,cap,rev;};
int V,n,m,g;
vector<edge> G[MAXV];
int level[MAXV];
int iter[MAXV];
int gender[MAXN],v[MAXN];
void add_edge(int from,int to,int cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        int v=que.front(); que.pop();
        for(int i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v,int t,int f)
{
    if(v==t) return f;
    for(int &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t)
{
    int flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&g);
    V=n+m+2;
    int s=V-1,t=V,ans=0;
    for(int i=1;i<=n;i++) scanf("%d",&gender[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        if(gender[i]) add_edge(s,i,v[i]);
        else add_edge(i,t,v[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int sx,isfriend,w,k;
        scanf("%d%d%d",&sx,&w,&k);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            if(sx) add_edge(n+i,x,INF);
            else add_edge(x,n+i,INF);
        }
        scanf("%d",&isfriend);
        if(isfriend) {ans-=g; w+=g;}
        ans+=w;
        if(sx) add_edge(s,n+i,w); else add_edge(n+i,t,w);
    }
    ans-=max_flow(s,t);
    printf("%d\n",ans);
    return 0;
}