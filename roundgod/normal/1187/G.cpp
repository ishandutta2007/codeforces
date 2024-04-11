#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 55
#define MAXV 20005
#define MAXE 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,k,c,d,a[MAXN],cnt[MAXN];
ll x[MAXN],y[MAXN];
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V;
vector<edge> G[MAXV];
void add_edge(ll from,ll to,ll cap,ll cost)
{
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
            for(ll i=0;i<(int)G[v].size();i++)
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
ll s,t;
//101 layers
//xn+1..x(n+1)
int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&m,&k,&c,&d);
    for(ll i=1;i<=k;i++) 
    {
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(ll i=0;i<m;i++) scanf("%lld%lld",&x[i],&y[i]);
    ll s=101*n+1,t=101*n+2;
    V=t;
    for(ll i=1;i<=n;i++) add_edge(s,i,cnt[i],0);
    for(ll i=0;i<100;i++)
    {
        for(ll j=1;j<=n;j++) add_edge(i*n+j,(i+1)*n+j,INF,0);
        for(ll j=0;j<m;j++)
        {
            for(ll ii=1;ii<=k;ii++)
            {
                add_edge(i*n+x[j],(i+1)*n+y[j],1,(2*ii-1)*d);
                add_edge(i*n+y[j],(i+1)*n+x[j],1,(2*ii-1)*d);
            }
        }
        add_edge(i*n+1,t,INF,i*c);
    }
    add_edge(100*n+1,t,INF,100*c);
    printf("%lld\n",min_cost_flow(s,t,k));
    return 0;
}