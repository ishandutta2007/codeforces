#include <iostream>
#include <vector>
using namespace std;

typedef long long intl;
const int N = 101111;

vector <int> edges[N];

int degree[N];
int dp[N];

int main()
{
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		degree[u] ++;
		degree[v] ++;
	}
	intl ans = 0;
	for(int i = 1; i <= n; i ++)
	{
		dp[i] = 1;
		for(auto &v : edges[i])
			if(v < i)
				dp[i] = max(dp[i], dp[v] + 1);
		ans = max(ans, (intl)dp[i] * degree[i]);
	}
	cout << ans << '\n';
	return 0;
}