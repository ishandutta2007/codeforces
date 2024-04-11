#include<bits/stdc++.h>
using namespace std;
int dp[212345];
vector<int> adj[212345];
int l[212345];
int r[212345];
int ans;
void dfs(int x)
{
	long long z = 0;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		dfs(y);
		z += dp[y];
	}
	if(z < l[x]) 
	{
		//printf("add %d %d\n", x, z);
		ans ++;
		dp[x] = r[x];	
	}
	else if (z > r[x])
	{
		dp[x] = r[x];
	}
	else dp[x] = z;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		ans = 0;
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n - 1; i++) 
		{
			int v;
			scanf("%d", &v);
			adj[v - 1].push_back(i + 1);
		}
		for(int i = 0; i < n; i++) scanf("%d %d", &l[i], &r[i]);
		for(int i = 0; i < n; i++) dp[i] = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}