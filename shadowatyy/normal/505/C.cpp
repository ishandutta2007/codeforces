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

#define N 30007
#define off (-d+250)

int n, d, res, a;

int dp[N][507];

int g[N];

int solve(int i, int j)
{
	dp[i][j+off] = g[i];

	if(j>1 && i+j-1<N)
	{
		if(dp[i+j-1][j-1+off]==-1)
			solve(i+j-1, j-1);

		dp[i][j+off] = max(dp[i][j+off], g[i]+dp[i+j-1][j-1+off]);
	}

	if(i+j<N)
	{
		if(dp[i+j][j+off]==-1)
			solve(i+j, j);

		dp[i][j+off] = max(dp[i][j+off], g[i]+dp[i+j][j+off]);
	}

	if(i+j+1<N)
	{
		if(dp[i+j+1][j+1+off]==-1)
			solve(i+j+1, j+1);

		dp[i][j+off] = max(dp[i][j+off], g[i]+dp[i+j+1][j+1+off]);
	}

	return dp[i][j+off];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < N; ++i)
	{
		memset(dp[i], -1, sizeof dp[i]);
	}

	cin >> n >> d;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a;

		++g[a];
	}

	cout << solve(d, d);
}