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
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
using namespace std;

#define N 83

int n, k, m, a, b, c, res = inf;

int dp[N][N][N][N];

int cost[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cost[i][j] = inf;
		}
	}

	while(m--)
	{
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}

	for(int l = 0; l <= k+1; ++l)
	{
		for(int a = 0; a <= n+1; ++a)
		{	
			for(int b = 0; b <= n+1; ++b)
			{
				for(int v = 0; v <= n+1; ++v)
				{
					dp[l][a][b][v] = inf;
				}
			}
		}
	}

	for(int a = 1; a <= n; ++a)
	{
		for(int b = a; b <= n; ++b)
		{
			for(int v = a; v <= b; ++v)
			{
				dp[1][a][b][v] = 0;
			}
		}
	}	

	for(int l = 2; l <= k; ++l)
	{
		for(int d = 0; d < n; ++d)
		{
			for(int a = 1; a+d <= n; ++a)
			{	
				int b = a+d;

				for(int v = a; v <= b; ++v)
				{
					for(int u = a; u < v; ++u)
					{
						dp[l][a][b][v] = min(dp[l][a][b][v], dp[l-1][a][v-1][u]+cost[v][u]);
					}

					for(int u = v+1; u <= b; ++u)
					{
						dp[l][a][b][v] = min(dp[l][a][b][v], dp[l-1][v+1][b][u]+cost[v][u]);
					}

					dp[l][a][b][v] = min(dp[l][a][b][v], dp[l][a+1][b][v]);
					dp[l][a][b][v] = min(dp[l][a][b][v], dp[l][a][b-1][v]);
				}
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		res = min(res, dp[k][1][n][i]);
	}

	if(res==inf)
		cout << -1;
	else
		cout << res;
}