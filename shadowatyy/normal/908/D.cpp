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
//#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define int long long
const int MOD = 1e9+7;
const int N = 1007;

int k, pa, pb;

int dp[N][N];

int ans;

int fpow(int a, int b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%MOD;

	if(b%2)
		return a*fpow(a, b-1)%MOD;
	else
	{
		int q = fpow(a, b/2);
		return q*q%MOD;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> k >> pa >> pb;

	ll mian = fpow(pa+pb, MOD-2);

	dp[0][0] = 1;

	for(int i = 0; i < k; ++i)
	{
		for(int j = 0; j < k; ++j)
		{
			if(j==0)
			{
				dp[i][j+1] += dp[i][j];
				dp[i][j+1] %= MOD;
			}
			else
			{
				dp[i][j+1] += dp[i][j]*pa%MOD*mian%MOD;
				dp[i][j+1] %= MOD;

				if(i+j<k)
				{
					dp[i+j][j] += dp[i][j]*pb%MOD*mian%MOD;
					dp[i+j][j] %= MOD;
				}
				else
				{
					ans += (i+j)*dp[i][j]%MOD*pb%MOD*mian%MOD;
					ans %= MOD;
				}
			}
		}
	}

	for(int i = 0; i < k; ++i)
	{
		ans += (k+i)*dp[i][k]%MOD;
		int a = dp[i][k]*pa%MOD*mian%MOD;
		int r = pa*mian%MOD;
		ans += a*fpow(1-r, MOD-2);
		ans %= MOD;
	}

	ans %= MOD;
	ans += MOD;
	ans %= MOD;

	cout << ans;
}