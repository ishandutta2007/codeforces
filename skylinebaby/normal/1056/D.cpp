#include<bits/stdc++.h>
using namespace std;
int papa[123456];
int need[123456];
vector<int> adj[123456];
void dfs(int x)
{
	for(int i = 0;i<adj[x].size();i++)
	{
		int y = adj[x][i];
		if(y==papa[x]) continue;
		dfs(y);
		need[x] += need[y];
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		printf("1\n");
		return 0;
	}
	for(int i = 2;i<=n;i++)
	{
		scanf("%d",&papa[i]);
		adj[i].push_back(papa[i]);
		adj[papa[i]].push_back(i);
	}
	papa[1] = 1;
	for(int i = 2;i<=n;i++)
	{
		if(adj[i].size()==1) need[i] = 1;
		else need[i] = 0;
	}
	dfs(1);
	sort(need+1,need+n+1);
	for(int i = 1;i<=n;i++)
	{
		printf("%d ",need[i]);
	}
	printf("\n");
	return 0;
}