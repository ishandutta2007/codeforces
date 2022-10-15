#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXV 3005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{ll to,cap,rev;};
ll n,m,V,a[MAXV],ans=0;
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
void add_edge(ll from,ll to,ll cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
}
void bfs(ll s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        ll v=que.front(); que.pop();
        for(ll i=0;i<(int)G[v].size();i++)
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
 
ll dfs(ll v,ll t,ll f)
{
    if(v==t) return f;
    for(ll &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
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
ll max_flow(ll s,ll t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0)
          flow+=f;
    }
}
//1~n: vertices
//n+1~n+m:edges
//n+m+1:source,n+m+2:sink
int main()
{
    scanf("%lld%lld",&n,&m);
    ll s=n+m+1,t=n+m+2;
    for(ll i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        add_edge(i,t,a[i]);
    }
    for(ll i=1;i<=m;i++)
    {
        ll u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
        ans+=w;
        add_edge(s,n+i,w);
        add_edge(n+i,u,INF);
        add_edge(n+i,v,INF);
    }
    ans-=max_flow(s,t);
    assert(ans!=INF);
    printf("%lld\n",ans);
    return 0;
}