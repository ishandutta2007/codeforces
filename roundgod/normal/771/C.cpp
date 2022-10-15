#include<bits/stdc++.h>
#define MAXN 200005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,k,ans;
vector<int> G[MAXN];
ll sz[MAXN],dp[MAXN][5];
void dfs(ll v,ll p,ll depth)
{
	dp[v][depth%k]=sz[v]=1;
	for(ll a=0;a<G[v].size();a++)
	{
		ll to=G[v][a];
		if(to==p) continue;
		dfs(to,v,depth+1);
		for(ll i=0;i<k;i++)
			for(ll j=0;j<k;j++)
			{
				ll r=((i+j-2*depth)%k+k)%k;
				ll cost=(k-r)%k;
				ans+=cost*dp[v][i]*dp[to][j];
			}
		for(ll i=0;i<k;i++)
			dp[v][i]+=dp[to][i];
		sz[v]+=sz[to];
	}
	ans+=sz[v]*(n-sz[v]);
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(ll i=0;i<n-1;i++)
	{
		ll x,y;
		scanf("%I64d%I64d",&x,&y);
		G[x-1].push_back(y-1);
		G[y-1].push_back(x-1);
	}
	memset(sz,0,sizeof(sz));
	memset(dp,0,sizeof(dp));
	dfs(0,-1,0);
	printf("%I64d\n",ans/k);
	return 0;
}