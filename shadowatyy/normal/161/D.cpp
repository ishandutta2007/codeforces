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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 50007
#define K 507

int n, a, b, k;

VI G[N];

ll dp[N][K];

ll res;

bitset<N> vis;

void dfs(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dfs(it);

			for(int i = 1; i < k; ++i)
			{
				res += dp[v][i]*dp[it][k-i-1];
			}

			for(int i = 0; i < k; ++i)
			{
				dp[v][i+1] += dp[it][i];
			}
		}
	}

	res += dp[v][k];

	++dp[v][0];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i < n; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	cout << res;
}