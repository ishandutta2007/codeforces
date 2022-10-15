#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge
{
	ll to,cost;
};
ll base[32];
vector<edge> G[MAXN];
ll n,m,dp[MAXN];
bool vis[MAXN];
void _insert(ll x)
{
	for(ll i=31;i>=0;i--)
	{
		if(x&(1LL<<i))
		{
			if(base[i]!=0) x^=base[i];
			else
			{
				base[i]=x;
				return;
			}
		}
	}
}
void dfs(ll v,ll p,ll d)
{
	vis[v]=true;
	dp[v]=d;
	for(ll i=0;i<G[v].size();i++)
	{
		if(G[v][i].to==p) continue;
		if(vis[G[v][i].to]) _insert(dp[v]^dp[G[v][i].to]^G[v][i].cost);
		else dfs(G[v][i].to,v,d^G[v][i].cost); 
	}
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(ll i=0;i<m;i++)
	{
		ll x,y,z;
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		G[x].push_back((edge){y,z});
		G[y].push_back((edge){x,z});
	}
	memset(vis,false,sizeof(vis));
	memset(dp,0,sizeof(dp));
	memset(base,0,sizeof(base));
	dfs(1,-1,0);
	ll ans=dp[1]^dp[n];
	for(ll i=31;i>=0;i--)
		ans=min(ans,ans^base[i]);
	printf("%I64d\n",ans);
	return 0;
}