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

#define N 157

int n, k, s;

int q[N];

int dp[2][N][N*N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s;

	for(int i = 1; i <= n; ++i)
	{
		cin >> q[i];
	}

	for(int j = 0; j <= n; ++j)
	{
		memset(dp[0][j], inf16, sizeof dp[0][j]);
		memset(dp[1][j], inf16, sizeof dp[1][j]);
	}

	dp[0][0][0] = 0;

	for(int i = 0; i <= n; ++i)
	{
		int ind = i%2;

		for(int j = 0; j <= n; ++j)
		{
			memset(dp[ind^1][j], inf16, sizeof dp[ind^1][j]);
		}

		for(int j = 0; j <= i; ++j)
		{
			for(int l = 0; l <= i*n; ++l)
			{
				dp[ind^1][j+1][l+(i+1)-(j+1)] = min(dp[ind^1][j+1][l+(i+1)-(j+1)], dp[ind][j][l]+q[i+1]);
				dp[ind^1][j][l] = min(dp[ind^1][j][l], dp[ind][j][l]);
			}
		}
	}

	int res = inf16, ind = n%2;

	for(int i = 0; i <= min(s, n*n); ++i)
	{
		res = min(res, dp[ind][k][i]);
	}

	cout << res;
}