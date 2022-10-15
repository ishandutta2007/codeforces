#include<bits/stdc++.h>
#define MAXV 105
#define MAXE 100005
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{ll to,cap,cost,rev;};
ll dist[MAXV],h[MAXV],prevv[MAXV],preve[MAXV];
ll V,n,m;
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
ll cnt[MAXV];
int main()
{
    scanf("%lld%lld",&n,&m);
    V=n+2;
    ll s=n+1,t=n+2,ans=0;
    for(ll i=0;i<m;i++)
    {
        ll u,v,c,f;
        scanf("%lld%lld%lld%lld",&u,&v,&c,&f);
        cnt[u]-=f; cnt[v]+=f;
        if(f<=c)
        {
            add_edge(u,v,c-f,1);
            add_edge(u,v,INF,2);
            add_edge(v,u,f,1);
        }
        else
        {
            ans+=f-c;
            add_edge(u,v,INF,2);
            add_edge(v,u,f-c,0);
            add_edge(v,u,c,1);
        }
    }
    add_edge(1,n,INF,0);
    add_edge(n,1,INF,0);
    ll sum=0;
    for(ll i=1;i<=n;i++)
    {
        if(cnt[i]>0)
        {
            add_edge(s,i,cnt[i],0);
            sum+=cnt[i];
        }else add_edge(i,t,-cnt[i],0);
    }
    ans+=min_cost_flow(s,t,sum);
    printf("%lld\n",ans);
    return 0;
}