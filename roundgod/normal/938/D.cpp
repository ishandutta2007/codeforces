#include<bits/stdc++.h>
#define MAXV 300005
#define INF 1000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
struct edge{ll to,cost;};
typedef pair<ll,ll> P;
ll V,E;
vector<edge> G[MAXV];
ll ans[MAXV];
void dijkstra()
{
    priority_queue<P,vector<P>,greater<P> > que;
    for(ll i=0;i<V;i++)
    	que.push(P(ans[i],i));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        ll v=p.S,cost=p.F;
        if(ans[v]<cost) continue;
        ans[v]=cost;
        for(ll i=0;i<G[v].size();i++)
        {
            ll to=G[v][i].to,tcost=G[v][i].cost;
            if(cost+tcost*2<ans[to]) 
            {
            	ans[to]=cost+tcost*2;
            	que.push(P(cost+tcost*2,to));
            }
        }
    }
}
int main()
{
	scanf("%I64d%I64d",&V,&E);
	for(ll i=0;i<E;i++)
	{
		ll u,v,w;
		scanf("%I64d%I64d%I64d",&u,&v,&w);
		u--;v--;
		G[v].push_back((edge){u,w});
		G[u].push_back((edge){v,w});
	}
	for(ll i=0;i<V;i++)
		scanf("%I64d",&ans[i]);
	dijkstra();
	for(ll i=0;i<V;i++)
		printf("%I64d ",ans[i]);
	return 0;
}