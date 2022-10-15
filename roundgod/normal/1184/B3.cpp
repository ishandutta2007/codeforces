#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 105
#define MAXK 200005
#define MAXV 200005
#define INF 100000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
ll n,m;
ll d[MAXN][MAXN];
ll s,b,k;
ll sx[MAXK],sa[MAXK],sf[MAXK],sp[MAXK];
ll bx[MAXK],bd[MAXK],bg[MAXK];
void floyd_warshall()
{
    for(ll k=1;k<=n;k++)
        for(ll i=1;i<=n;i++)
          for(ll j=1;j<=n;j++) 
              d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
struct edge{ll to,cap,rev;};
vector<edge> G[MAXV];
ll level[MAXV];
ll iter[MAXV];
vector<ll> dis[MAXN],res[MAXN];
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
ll val[MAXK];
int main()
{
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(ll i=0;i<m;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        d[u][v]=d[v][u]=1;
    }
    floyd_warshall();
    scanf("%lld%lld%lld",&s,&b,&k);
    for(ll i=1;i<=s;i++) scanf("%lld%lld%lld%lld",&sx[i],&sa[i],&sf[i],&sp[i]);
    for(ll i=1;i<=b;i++) scanf("%lld%lld%lld",&bx[i],&bd[i],&bg[i]);
    for(ll i=1;i<=b;i++)
    {
        dis[bx[i]].push_back(bd[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        sort(dis[i].begin(),dis[i].end());
        dis[i].erase(unique(dis[i].begin(),dis[i].end()),dis[i].end());
        res[i].resize(dis[i].size());
    }
    for(ll i=1;i<=b;i++)
    {
        ll id=lower_bound(dis[bx[i]].begin(),dis[bx[i]].end(),bd[i])-dis[bx[i]].begin();
        res[bx[i]][id]=max(res[bx[i]][id],bg[i]);
    }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<(int)res[i].size();j++) 
            res[i][j]=max(res[i][j],res[i][j-1]);
    for(ll i=1;i<=s;i++) val[i]=-INF;
    for(ll i=1;i<=s;i++)
        for(ll j=1;j<=n;j++)
        {
            if(sf[i]<d[sx[i]][j]) continue;
            if(dis[j].size()==0) continue;
            ll id=upper_bound(dis[j].begin(),dis[j].end(),sa[i])-dis[j].begin()-1;
            if(id<0) continue;
            id=min(id,(ll)res[j].size()-1);
            val[i]=max(val[i],res[j][id]-sp[i]);
        }
    ll ans=0;
    for(ll i=0;i<k;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        add_edge(u,v,INF);
    }
    ll src=s+1,dest=s+2;
    for(ll i=1;i<=s;i++) 
    {
        if(val[i]>0)
        {
            add_edge(src,i,val[i]);
            ans+=val[i];
        }
        else
        {
            add_edge(i,dest,-val[i]);
        }
    }
    ans-=max_flow(src,dest);
    printf("%lld\n",ans);
    return 0;
}