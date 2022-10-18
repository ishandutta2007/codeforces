#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> adj[5010];
int sz[5010];
int pa[5010];
int dp[5010];
int ans[5010];
void dfs(int x,int p)
{
	pa[x] = p;
	sz[x] = 1;
	for(int i = 0;i<adj[x].size();i++)
	{
		int y = adj[x][i];
		if(y==p) continue;
		dfs(y,x);
		sz[x] += sz[y];
	}
	memset(dp,0,sizeof(dp));
	dp[0] = 1;
	for(int i = 0;i<adj[x].size();i++)
	{
		int y = adj[x][i];
		int z = sz[y];
		if(y==p) z = n - sz[x];
		for(int j = n;j>=z;j--) dp[j] |= dp[j-z];
	}
	for(int i = 0;i<n;i++) ans[i] |= dp[i]; 
}
int main()
{
	scanf("%d",&n);
	for(int i = 0;i<n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	int cnt = 0;
	for(int i = 1;i<=n-2;i++) if(ans[i]) cnt++;
	printf("%d\n",cnt);
	for(int i = 1;i<=n-2;i++) if(ans[i]) printf("%d %d\n",i,n-1-i); 
	return 0;
 }