#include<bits/stdc++.h>
using namespace std;
vector<int> adj[200010];
long long dp[200010];
long long  hak[200010];
long long  ful[200010];
int wei[200010];
long long ans;
void dfs(int x,int y)
{
	for(int i = 0;i<adj[x].size();i++)
	{
		int t = adj[x][i];
		if(t==y) continue;
		dfs(t,x);
		long long dop = dp[t] + hak[t];
		long long foul= hak[t];
		long long hoak = ful[t];		
		//printf("%lld %d %d\n",ans,x,t);
		ans += (long long)wei[t]*(dp[x]);
		//printf("%lld %d %d\n",ans,x,t);
		ans += (long long)wei[x]*(dop+hoak);
		//printf("%lld %d %d\n",ans,x,t);
		ans += (long long)foul*hak[x];
		//printf("%lld %d %d\n",ans,x,t);
		//ans += (long long)wei[t]*wei[x];
		//printf("%lld %d %d\n",ans,x,t);
		wei[x] += wei[t];
		dp[x] += dop;
		ful[x] += foul;
		hak[x] += hoak;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1;i<=n;i++) 
	{
		wei[i] = 1;
		ful[i] = 1;
	}
	ans = 0;
	memset(dp,0,sizeof(dp));
	memset(hak,0,sizeof(hak));
	dfs(1,1);
	//for(int i = 1;i<=n;i++) printf("%lld %lld %lld %lld\n",dp[i],hak[i],wei[i],ful[i]);
	printf("%lld\n",ans);
	return 0;
}