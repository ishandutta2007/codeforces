#include<bits/stdc++.h>
#define MAXN 505
#define MAXV 1005
#define MAXE 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V,n,x,y,q1,q2;
ll a[MAXN];
vector<edge> G[MAXV];
vector<int> G1[MAXN],G2[MAXN];
ll dem1[MAXN],dem2[MAXN],sum1[MAXN],sum2[MAXN],fa1[MAXN],fa2[MAXN];
void add_edge(ll from,ll to,ll cap,ll cost)
{
    //printf("add edge %lld %lld %lld %lld\n",from,to,cap,cost);
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
ll min_cost_flow(ll s,ll t,ll f)
{
    ll res=0;
    fill(h+1,h+V+1,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,INF);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            ll v=p.second;
            if(dist[v]<p.first) continue;
            for(ll i=0;i<G[v].size();i++)
            {
                edge &e=G[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                {
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    que.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==INF)
        {
            return -1;
        }
        for(ll v=1;v<=V;v++) h[v]+=dist[v];
        ll d=f;
        for(ll v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(ll v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
void dfs1(ll v,ll p,ll d)
{
    fa1[v]=dem1[v]?v:d;
    for(auto to:G1[v])
    {
        if(to==p) continue;
        dfs1(to,v,fa1[v]);
        sum1[v]+=sum1[to];
    }
    if(dem1[v])
    {
        ll t=dem1[v];
        dem1[v]-=sum1[v];
        sum1[v]=t;
    }
}
void dfs2(ll v,ll p,ll d)
{
    fa2[v]=dem2[v]?v:d;
    for(auto to:G2[v])
    {
        if(to==p) continue;
        dfs2(to,v,fa2[v]);
        sum2[v]+=sum2[to];
    }
    if(dem2[v])
    {
        ll t=dem2[v];
        dem2[v]-=sum2[v];
        sum2[v]=t;
    }
}
ll offset=200000;
int main()
{
    scanf("%lld%lld%lld",&n,&x,&y);
    V=2*n+2;
    ll s=2*n+1,t=2*n+2;
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G1[u].push_back(v); G1[v].push_back(u);
    }
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        G2[u].push_back(v); G2[v].push_back(u);
    }
    ll asum=0,bsum=0;
    scanf("%lld",&q1);
    for(ll i=1;i<=q1;i++)
    {
        ll k,x;
        scanf("%lld%lld",&k,&x);
        dem1[k]+=x;
    }
    scanf("%lld",&q2);
    for(ll i=1;i<=q2;i++)
    {
        ll k,x;
        scanf("%lld%lld",&k,&x);
        dem2[k]+=x;
    }
    dfs1(x,0,0); dfs2(y,0,0);
    bool f=true;
    for(ll i=1;i<=n;i++)
    {
        if(dem1[i])
        {
            if(dem1[i]<0) f=false;
            else
            {
                add_edge(s,i,dem1[i],0);
                asum+=dem1[i];
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        if(dem2[i])
        {
            if(dem2[i]<0) f=false;
            else
            {
                add_edge(n+i,t,dem2[i],0);
                bsum+=dem2[i];
            }
        }
    }
    if(!f||(asum!=bsum)) {puts("-1"); return 0;}
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        assert(fa1[i]&&fa2[i]);
        add_edge(fa1[i],n+fa2[i],1,-a[i]);
    }
    ans=min_cost_flow(s,t,asum);
    if(ans==-1) puts("-1"); else printf("%lld\n",-ans);
    return 0;
}