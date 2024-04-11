#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int MOD = 1e9+7;
const int N = 5007;

int n;

char t[N];

ll dp[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}

	dp[0][0] = 1;

	for(int i = 0; i <= n; ++i)
	{
		for(int j = n; j >= 0; --j)
		{
			dp[i][j] += dp[i][j+1];
			dp[i][j] %= MOD;
		}

		for(int j = 0; j <= n; ++j)
		{
			if(t[i+1]=='f')
			{
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1] %= MOD;
				dp[i+1][j] -= dp[i][j];
				dp[i+1][j] %= MOD;
			}
			else
			{
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= MOD;
			}
		}
	}

	dp[n][0] %= MOD;
	dp[n][0] += MOD;
	dp[n][0] %= MOD;

	cout << dp[n][0];
}