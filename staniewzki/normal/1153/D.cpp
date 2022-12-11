#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define V vector
#define EB emplace_back
#define ST first
#define ND second

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

VI m;
VI par;
VVI graph;
VI dp;
VI s;

void DFS(int v)
{
	if(graph[v].size() == 0)
	{
		s[v] = 1, dp[v] = 1;
		return;
	}

	for(int u : graph[v])
	{
		DFS(u);
		s[v] += s[u];
	}

	if(m[v] == 1)
	{
		for(int u : graph[v])
			dp[v] = max(dp[v], dp[u] + s[v] - s[u]);
	}
	else
	{
		dp[v] = 1;
		for(int u : graph[v])
			dp[v] += dp[u] - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n;
	cin >> n;

	graph.resize(n);
	par.resize(n);
	m.resize(n);
	s.resize(n);
	dp.resize(n);

	REP(i, n)
		cin >> m[i];
	
	for(int i = 1; i < n; i++)
	{
		cin >> par[i];
		par[i]--;
		graph[par[i]].EB(i);
	}

	DFS(0);

	cout << dp[0] << "\n";
}