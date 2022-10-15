#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,q,s,cnt=0;
struct edge
{
	ll to,cost;
};
struct node
{
	ll l,r;
}seg[2][4*MAXN];
vector<edge> G[10*MAXN];
void add_edge(ll u,ll v,ll cost)
{
	G[u].push_back((edge){v,cost});
}
void build(ll num,ll k,ll l,ll r)
{
	seg[num][k].l=l;
	seg[num][k].r=r;
	if(l==r)
	{
		if(num==0)
		{
			add_edge(n+k,l,0);
			return;
		}
		else
		{
			add_edge(l,5*n+k,0);
			return;
		}
	}
	ll mid=(l+r)/2;
	build(num,k*2,l,mid);
	build(num,k*2+1,mid+1,r);
	if(num==0)
	{
		add_edge(n+k,n+k*2,0);
		add_edge(n+k,n+k*2+1,0);
	}
	else
	{
		add_edge(5*n+k*2,5*n+k,0);
		add_edge(5*n+k*2+1,5*n+k,0);
	}
}
void query(ll type,ll u,ll k,ll l,ll r,ll cost)
{
	if(l>seg[type][k].r||r<seg[type][k].l) return;
	if(seg[type][k].l>=l&&seg[type][k].r<=r)
	{
		if(type==0) add_edge(u,n+k,cost);
		else add_edge(5*n+k,u,cost);
		return;
	}
	query(type,u,k*2,l,r,cost);
	query(type,u,k*2+1,l,r,cost);
}
ll d[MAXN*10];
void dijkstra(ll s)
{
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d+1,d+9*n+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p=que.top(); que.pop();
        ll v=p.second;
        if(d[v]<p.first) continue;
        for(ll i=0;i<G[v].size();i++)
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&q,&s);
	build(0,1,1,n);
	build(1,1,1,n);
	for(ll i=0;i<q;i++)
	{
		ll type,u,v,l,r,cost;
		scanf("%I64d",&type);
		if(type==1)
		{
			scanf("%I64d%I64d%I64d",&u,&v,&cost);
			add_edge(u,v,cost);
		}
		else 
		{
			scanf("%I64d%I64d%I64d%I64d",&u,&l,&r,&cost);
			query(type-2,u,1,l,r,cost);
		}
	}
	dijkstra(s);
	for(ll i=1;i<=n;i++)
		printf("%I64d ",d[i]==INF?-1:d[i]);
	return 0;
}