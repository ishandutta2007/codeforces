#include<bits/stdc++.h>
using namespace std;
vector<int> adj[212345];
int vis[212345];
int col[212345];
void dfs(int x, int c)
{
	vis[x] = 1;
	col[x] = c;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(!vis[y])
		{
			dfs(y, 1 - c);
		}		
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1, 0);
	int od = 0;
	for(int i = 1; i <= n; i++)
	{
		if(col[i]) od++;
	}
	printf("%d\n", min(od, n - od) - 1);
	return 0;
}