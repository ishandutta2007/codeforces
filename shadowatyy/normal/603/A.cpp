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
#define SIZE(x) (int)(x).size()
using namespace std;

#define N 100007

int n;

string s;

int dp[3][2][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	s = '#'+s;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k <= n; ++k)
			{
				dp[i][j][k] = -inf;
			}
		}
	}

	dp[0][0][0] = 0;
	dp[0][1][0] = 0;

	for(int i = 0; i <= n; ++i)
	{
		dp[2][0][i] = max(dp[2][0][i], dp[1][0][i]);
		dp[2][1][i] = max(dp[2][1][i], dp[1][1][i]);

		dp[0][0][i+1] = max(dp[0][0][i+1], dp[0][0][i]);
		dp[0][1][i+1] = max(dp[0][1][i+1], dp[0][1][i]);
		dp[1][0][i+1] = max(dp[1][0][i+1], dp[1][0][i]);
		dp[1][1][i+1] = max(dp[1][1][i+1], dp[1][1][i]);
		dp[2][0][i+1] = max(dp[2][0][i+1], dp[2][0][i]);
		dp[2][1][i+1] = max(dp[2][1][i+1], dp[2][1][i]);

		if(s[i+1]=='1')
		{
			dp[0][1][i+1] = max(dp[0][1][i+1], dp[0][0][i]+1);
			dp[1][0][i+1] = max(dp[1][0][i+1], dp[0][1][i]+1);
			dp[1][0][i+1] = max(dp[1][0][i+1], dp[1][1][i]+1);
			dp[2][1][i+1] = max(dp[2][1][i+1], dp[2][0][i]+1);
		}
		else
		{
			dp[0][0][i+1] = max(dp[0][0][i+1], dp[0][1][i]+1);
			dp[1][1][i+1] = max(dp[1][1][i+1], dp[0][0][i]+1);
			dp[1][1][i+1] = max(dp[1][1][i+1], dp[1][0][i]+1);
			dp[2][0][i+1] = max(dp[2][0][i+1], dp[2][1][i]+1);
		}
	}

	cout << max(dp[2][0][n], dp[2][1][n]);
}