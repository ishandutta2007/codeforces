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
using namespace std;

const int N = 507;
const int MOD = 1e9+7;

int n;

int ok[N][N];
ll dp[N][N];
ll ilo[N][N];

void iloczyn(int a, int b);

int solve(int a, int b)
{
	if(dp[a][b]!=-1)
		return dp[a][b];

	if(a==b)
		return dp[a][b] = 1;

	dp[a][b] = 0;

	for(int i = a+1; i < b; ++i)
	{
		if(ok[a][i])
		{
			if(ok[a][b])
			{
				// lacze a z b
				
				iloczyn(a, i);
				iloczyn(i, b);
				dp[a][b] += ilo[a][i]*ilo[i][b]%MOD;
				dp[a][b] %= MOD;
			}

			// nie lacze a z b

			iloczyn(a, i);
			solve(i, b);
			dp[a][b] += ilo[a][i]*dp[i][b]%MOD;
			dp[a][b] %= MOD;
		}
	}

	// lacze a tylko z b

	if(ok[a][b])
	{
		solve(a+1, b);
		dp[a][b] += dp[a+1][b];
		dp[a][b] %= MOD;
	}

	return dp[a][b];
}

void iloczyn(int a, int b)
{
	if(ilo[a][b]!=-1)
		return;

	ilo[a][b] = 0;

	for(int i = a; i < b; ++i)
	{
		solve(a, i);
		solve(i+1, b);
		ilo[a][b] += dp[a][i]*dp[i+1][b]%MOD;
		ilo[a][b] %= MOD;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			cin >> ok[i][j];
			dp[i][j] = ilo[i][j] = -1;
		}
	}

	cout << solve(0, n-1);
}