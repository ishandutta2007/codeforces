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

#define N 5007
#define int long long
#define M inf

int n, a, b, k, res;

int dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b >> k;

	++dp[0][a];
	--dp[0][a+1];

	for(int i = 0; i <= k; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i][j-1];
			dp[i][j] %= M;
		}

		for(int j = 1; j <= n; ++j)
		{
			int d = max(j-b, b-j);
			--d;

			if(max(1ll, j-d)<=j-1)
			{
				dp[i+1][max(1ll, j-d)] += dp[i][j];
				dp[i+1][j-1+1] -= dp[i][j];
				dp[i+1][max(1ll, j-d)] %= M;
				dp[i+1][j-1+1] += M;
				dp[i+1][j-1+1] %= M;
			}

			if(j+1<=min(n, j+d))
			{
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][min(n, j+d)+1] -= dp[i][j];
				dp[i+1][j+1] %= M;
				dp[i+1][min(n, j+d)+1] += M;
				dp[i+1][min(n, j+d)+1] %= M;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		res += dp[k][i];
		res %= M;
	}

	cout << res;
}