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

#define int long long
const int MOD = 1e9+7;
const int N = 1007;

string s;

int k, l, ans;

int dp[2][N][N];

int licz(int x)
{
	int ans = 0;

	while(x!=1)
	{
		++ans;
		x = __builtin_popcount(x);
	}

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> k;

	if(k==0)
	{
		cout << 1;
		return 0;
	}

	reverse(ALL(s));

	l = s.size();

	dp[0][l][0] = 1;

	for(int i = l; i >= 1; --i)
	{
		for(int j = 0; j <= 1000; ++j)
		{
			if(s[i-1]=='1')
			{
				dp[0][i-1][j+1] += dp[0][i][j];
				dp[0][i-1][j+1] %= MOD;

				dp[1][i-1][j] += dp[0][i][j];
				dp[1][i-1][j] %= MOD;
			}
			else
			{
				dp[0][i-1][j] += dp[0][i][j];
				dp[0][i-1][j] %= MOD;
			}

			dp[1][i-1][j+1] += dp[1][i][j];
			dp[1][i-1][j+1] %= MOD;
				
			dp[1][i-1][j] += dp[1][i][j];
			dp[1][i-1][j] %= MOD;
		}
	}

	for(int j = 1; j <= 1000; ++j)
	{
		if(licz(j)==k-1)
		{
			ans += dp[0][0][j]+dp[1][0][j];
			ans %= MOD;
		}
	}

	if(k==1)
	{
		ans += MOD-1;
		ans %= MOD;
	}

	cout << ans;
}