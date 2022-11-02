#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 201111;
typedef long long intl;
int dp[N][2];

int deg[N];
vector <int> edges[N];

void dfs(int cur, int last = -1)
{
	vector <int> vec;
	int sum = 0;
	for(auto &v : edges[cur])
		if(v != last)
		{
			dfs(v, cur);
			sum += dp[v][0];
			vec.push_back(dp[v][1] - dp[v][0]);
		}
	if(vec.size() == 0)
	{
		dp[cur][0] = 0;
		dp[cur][1] = 0;
		return;
	}
	sort(vec.begin(), vec.end(), greater<int>());
	dp[cur][1] = sum + 1 + vec[0];
	if(vec.size() >= 2)
		dp[cur][0] = sum + 2 + vec[0] + vec[1];
	dp[cur][0] = max(dp[cur][0], dp[cur][1]);
}

int main()
{
	ios :: sync_with_stdio(false);
	int n, x, y;
	cin >> n >> x >> y;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		deg[u] ++;
		deg[v] ++;
	}

	dfs(1);
	if(x < y)
	{
		int t = max(dp[1][0], dp[1][1]);
		cout << (intl)t * x + (intl)(n - t - 1) * y << '\n';
	}
	else
	{
		int cnt = 0;
		for(int i = 1; i <= n; i ++)
			if(deg[i] > 1)
				cnt ++;
		if(cnt <= 1)
			cout << x + (intl)(n - 2) * y << '\n';
		else
			cout << (intl)(n - 1) * y << '\n';
	}
	return 0;
}