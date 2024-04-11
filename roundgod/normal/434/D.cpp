#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 15005
#define INF 1000000000
using namespace std;
typedef long long ll;
struct edge{ll to,cap,rev;};
ll n,m;
ll a[MAXN],b[MAXN],c[MAXN],l[MAXN],r[MAXN];
ll u[MAXN],v[MAXN],d[MAXN];
vector<edge> G[MAXM];
ll level[MAXM];
ll iter[MAXM];
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
ll get_id(ll x,ll y)
{
    return (x-1)*202+(y-l[x])+2;
}
ll offset=300000;
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&l[i],&r[i]);
    for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&u[i],&v[i],&d[i]);
    ll s=n*202+1,t=n*202+2;
    for(ll i=1;i<=n;i++)
    {
        add_edge(s,get_id(i,l[i]-1),INF);
        add_edge(get_id(i,r[i]),t,INF);
        for(ll j=l[i];j<=r[i];j++)
        {
            ll id=get_id(i,j);
            ll val=a[i]*j*j+b[i]*j+c[i];
            add_edge(id-1,id,offset-val);
        }
    }
    for(ll i=1;i<=m;i++)
    {
        for(ll j=l[u[i]]-1;j<=r[u[i]];j++)
        {
            ll k=j-d[i];
            if(k<l[v[i]]-1||k>r[v[i]]) continue;
            add_edge(get_id(u[i],j),get_id(v[i],k),INF);
        }
    }
    printf("%lld\n",n*offset-max_flow(s,t));
    return 0;
}