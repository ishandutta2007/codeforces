#include<bits/stdc++.h>
using namespace std;
int dp[212345];
int deg[212345];
vector<int> rev[212345];
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		//adj[x].push_back(y);
		deg[x]++;
		rev[y].push_back(x);
	}
	for(int i = 0; i < n; i++) dp[i] = m + 1;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, n - 1));
	while(!pq.empty())
	{
	 	pair<int, int> z = pq.top();
	 	int x = z.first;
	 	int y = z.second;
	 	pq.pop();
	 	if(dp[y] <= m) continue;
	 	dp[y] = x;
	 	for(int i = 0; i < rev[y].size(); i++)
	 	{
	 		int to = rev[y][i];
	 		pq.push(make_pair(dp[y] + deg[to], to));
	 		deg[to]--;
		}
	}
	printf("%d\n", dp[0]);
	return 0;
}