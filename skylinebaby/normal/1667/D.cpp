#include<bits/stdc++.h>
using namespace std;
vector<int> adj[212345];
int dp[2][212345];
int pa[212345];
int pp[212345];
int zz[212345];
int deg[212345];
int vis[212345];
int l[212345];
int r[212345];
void dfs(int x, int p, int c)
{
	vis[x] = c;
	pa[x] = p;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(y == p) continue;
		dfs(y, x, c ^ 1);
	}
}
void dfs1(int x, int p)
{
	if(deg[x]) dp[vis[x]][x] = 1;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(y == p) continue;
		dfs1(y, x);
		dp[0][x] += dp[0][y];
		dp[1][x] += dp[1][y];
	}
	pp[x] = dp[1][x] - dp[0][x];
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) adj[i].clear();
		for(int i = 0; i < n; i++) dp[0][i] = dp[1][i] = 0;
		for(int i = 0; i < n; i++) deg[i] = 0;
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
			deg[x] ^= 1;
			deg[y] ^= 1;
		}
		dfs(0, 0, 0);
		dfs1(0, 0);
		int flag = 0;
		if(pp[0] != 0) flag = 1;
		for(int i = 1; i < n; i++) if(pp[i] != 1 && pp[i] != -1) flag = 1;
		if(flag)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(int i = 1; i < n; i++)
		{
			if(vis[i] == (pp[i] + 1) / 2) zz[i] = 1;
			else zz[i] = 0;
		}

		for(int i = 1; i < n; i++) l[i] = i - 1;
		for(int i = 1; i < n; i++) r[i] = i + 1;
		l[1] = n - 1;
		r[n - 1] = 1;
		int z = n - 1;
		int i = 1;
		while(z)
		{
			if(deg[i] == deg[pa[i]] && deg[i] == zz[i]) 
			{
				printf("%d %d\n", i + 1, pa[i] + 1);
				deg[i] ^= 1;
				deg[pa[i]] ^= 1;
				r[l[i]] = r[i];
				l[r[i]] = l[i];
				z--;
			}
			i = r[i];			
		}
	}
	return 0;
}