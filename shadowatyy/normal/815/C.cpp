#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define flush fflush(stdout)
using namespace std;

#define N 5007

int n, b, x, res = 0;

int c[N];
int d[N];

VI G[N];

int dp[2][N][N];
int sub[N];

void dfs(int v)
{
	sub[v] = 1;
	memset(dp[0][v], inf16, sizeof dp[0][v]);
	memset(dp[1][v], inf16, sizeof dp[1][v]);

	dp[0][v][0] = 0;
	dp[1][v][1] = c[v]-d[v];
	dp[0][v][1] = c[v];

	for(auto it:G[v])
	{
		dfs(it);

		for(int i = sub[v]; i >= 0; --i)
		{
			for(int j = sub[it]; j >= 0; --j)
			{
				dp[1][v][i+j] = min(dp[1][v][i+j], dp[1][v][i]+dp[1][it][j]);
				dp[1][v][i+j] = min(dp[1][v][i+j], dp[1][v][i]+dp[0][it][j]);
				dp[0][v][i+j] = min(dp[0][v][i+j], dp[0][v][i]+dp[0][it][j]);
			}
		}

		sub[v] += sub[it];
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> b >> c[1] >> d[1];

	for(int i = 2; i <= n; ++i)
	{
		cin >> c[i] >> d[i] >> x;
		G[x].pb(i);
	}

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		if(dp[0][1][i]<=b || dp[1][1][i]<=b)
			res = i;
	}

	cout << res;
}