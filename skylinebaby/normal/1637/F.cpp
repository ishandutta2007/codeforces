#include<bits/stdc++.h>
using namespace std;
int h[212345];
vector<int> adj[212345];
long long sum[212345];
int cone[212345];
long long ans;
void dfs(int x, int y)
{
	cone[x] = 0;
	sum[x] = 0;
	for(int i = 0; i < adj[x].size(); i++)
	{
		if(adj[x][i] == y) continue;
		dfs(adj[x][i], x);
		sum[x] += sum[adj[x][i]];
		cone[x] = max(cone[x], cone[adj[x][i]]);
	}
	if(y != -1) 
	{
		sum[x] += max(cone[x], h[x]) - cone[x];
		cone[x] = max(cone[x], h[x]);
	}
	else if (adj[x].size() == 1)
	{
		sum[x] += max(cone[x], h[x]) - cone[x];
		cone[x] = max(cone[x], h[x]);
		ans = sum[x] + h[x];		
	}
	else 
	{
		vector<int> a;
		for(int i = 0; i < adj[x].size(); i++)
		{
			a.push_back(h[x] - cone[adj[x][i]]);
		}
		sort(a.begin(), a.end());
		//reverse(a.begin(), a.end());
		ans = sum[x] + a[0] + a[1];
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	int mx = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &h[i]);
		mx = max(mx, h[i]);
	}
	int root = 0;
	for(int i = 0; i < n; i++)
	{
		if(mx == h[i]) root = i;		
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x --, y --;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(root, -1);
	printf("%lld\n", ans);
	return 0;
}