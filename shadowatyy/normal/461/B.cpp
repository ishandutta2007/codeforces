#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 100007
#define M inf

int n, a;

ll dp[2][N];
int c[N];

VI G[N];
bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;

	++dp[c[v]][v];

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);
			dp[1][v] = (dp[1][v]*dp[0][it]+dp[0][v]*dp[1][it])%M;
			dp[0][v] = (dp[0][v]*dp[0][it])%M;
		}
	}

	dp[0][v] = (dp[0][v]+dp[1][v])%M;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 2; i <= n; ++i)
	{
		cin >> a;
		G[++a].pb(i);
		G[i].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	dfs(1);

	cout << dp[1][1];
}