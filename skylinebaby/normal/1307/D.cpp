#include<bits/stdc++.h>
using namespace std;
vector<int> adj[212345];
int dp1[212345];
int dp2[212345];
int vis[212345];
int s[212345];
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &s[i]);
	}
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	queue<int> q1;
	q1.push(1);
	vis[1] = 1; 
	while(!q1.empty())
	{
		int x = q1.front();
		q1.pop();
		for(int i = 0; i < adj[x].size(); i++)
		{
			int y = adj[x][i];
			if(vis[y]) continue;
			q1.push(y);
			vis[y] = 1;
			dp1[y] = dp1[x] + 1;
		}
	}
	for(int i = 1; i <= n; i++) vis[i] = 0;
	queue<int> q2;
	q2.push(n);
	vis[n] = 1;
	while(!q2.empty())
	{
		int x = q2.front();
		q2.pop();
		for(int i = 0; i < adj[x].size(); i++)
		{
			int y = adj[x][i];
			if(vis[y]) continue;
			q2.push(y);
			vis[y] = 1;
			dp2[y] = dp2[x] + 1;
		}
	}	
	vector<pair<int, int > > v;
	for(int i = 0; i < k; i++) v.push_back(make_pair(dp1[s[i]], s[i]));
	sort(v.begin(), v.end());
	assert(dp2[1] == dp1[n]);
	int ans = 0;
	for(int i = 0; i < k - 1; i++)
	{
		int x = v[i].second;
		int y = v[i + 1].second;
		ans = max(ans, min(dp1[n], min(dp1[x] + 1 + dp2[y], dp1[y] + 1 + dp2[x])));
	}
	printf("%d\n", ans);
	return 0;
}