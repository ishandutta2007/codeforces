#include<bits/stdc++.h>
using namespace std;
int vis[112345];
int deg[112345];
vector<int> adj[112345];
void dfs(int x, int c)
{
	if(vis[x] != 0) return;
	vis[x] = c;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		dfs(y, -c);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			vis[i] = 0;
			deg[i] = 0;
			adj[i].clear();
		}
		for(int i = 0; i < n - 1; i++)
		{	
			int x, y;
			scanf("%d %d", &x, &y);
			x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		dfs(0, 1);
		for(int i = 0; i < n; i++)
		{
			printf("%d ", deg[i] * vis[i]);
		}
		printf("\n");
	}
	return 0;
}