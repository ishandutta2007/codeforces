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

#define S 70
#define N 1007
#define MOD inf

int n, k, t;

int dp[S][N];
int ans[N][N];
int dwu[N][N];
ll fact[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
	}

	dp[0][0] = 1;

	for(int i = 0; i < N; ++i)
	{
		for(int j = S-2; j >= 0; --j)
		{
			for(int k = N-1-i; k >= 0; --k)
			{
				dp[j+1][k+i] += dp[j][k];
				dp[j+1][k+i] %= MOD;
			}
		}
	}

	for(int i = 0; i < N; ++i)
	{
		dwu[i][0] = 1;
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j < N; ++j)
		{
			dwu[i][j] = (dwu[i-1][j-1]+dwu[i-1][j])%MOD;
		}
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < S; ++j)
		{
			for(int k = 0; j+k <= i; ++k)
			{
				ans[i][j] += dp[j][k]*fact[j]%MOD*dwu[j+(i-j-k)][i-j-k]%MOD;
				ans[i][j] %= MOD;
			}
		}
	}

	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		cout << ans[n][k] << endl;
	}
}