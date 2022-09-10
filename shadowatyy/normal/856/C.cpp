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

const int MOD = 998244353;
const int N = 2007;

int n, t;

int dp[N][N][11];
int wybor[N][N][11];

int a[N];
int b[N];
int c[N];

ll fact[N];
ll dwumian[N][N];

void clear()
{
	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			memset(dp[i][j], 0, sizeof dp[i][j]);
			memset(wybor[i][j], 0, sizeof wybor[i][j]);
		}
	}
}

void solve()
{
	cin >> n;

	int np = 0, p = 0;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		int len = 0, curr = a[i];

		while(curr)
		{
			++len;
			curr /= 10;
		}

		if(len%2==0)
			c[++p] = a[i]%11;
		else
			b[++np] = a[i]%11;
	}

	dp[0][0][0] = 1;

	for(int i = 1; i <= np; ++i)
	{
		for(int j = 0; j <= np/2; ++j)
		{
			for(int k = 0; k < 11; ++k)
			{
				dp[i][j+1][(k+b[i]*10)%11] += (ll)dp[i-1][j][k]*(np/2-j)%MOD;

				if(dp[i][j+1][(k+b[i]*10)%11] >= MOD)
					dp[i][j+1][(k+b[i]*10)%11] -= MOD;

				dp[i][j][(k+b[i])%11] += (ll)dp[i-1][j][k]*(np-np/2-(i-1-j))%MOD;

				if(dp[i][j][(k+b[i])%11] >= MOD)
					dp[i][j][(k+b[i])%11] -= MOD;
			}	
		}
	}

	wybor[0][0][0] = 1;

	for(int i = 1; i <= p; ++i)
	{
		for(int j = 0; j <= i-1; ++j)
		{
			for(int k = 0; k < 11; ++k)
			{
				wybor[i][j+1][(k+c[i]*10)%11] += wybor[i-1][j][k];

				if(wybor[i][j+1][(k+c[i]*10)%11] >= MOD)
					wybor[i][j+1][(k+c[i]*10)%11] -= MOD;

				wybor[i][j][(k+c[i])%11] += wybor[i-1][j][k];

				if(wybor[i][j][(k+c[i])%11]>=MOD)
					wybor[i][j][(k+c[i])%11] -= MOD;
			}
		}
	}

	ll ans = 0;

	for(int i = 0; i <= (np==0?0:p); ++i)
	{
		for(int j = 0; j < 11; ++j)
		{
			ans += (i+(np+1)/2-1>=0 && (np+1)/2-1>=0 ? dwumian[i+(np+1)/2-1][(np+1)/2-1] : 1ll)*(p-i+(np+2)/2-1>=0 && (np+2)/2-1>=0 ? dwumian[p-i+(np+2)/2-1][(np+2)/2-1] : 1)%MOD*fact[i]%MOD*fact[p-i]%MOD*wybor[p][i][j]%MOD*dp[np][np/2][(11-j)%11]%MOD;
			ans %= MOD;
		}
	}

	cout << ans << endl;
	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
	}

	for(int i = 0; i < N; ++i)
	{
		dwumian[i][0] = 1;
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j < N; ++j)
		{
			dwumian[i][j] = (dwumian[i-1][j]+dwumian[i-1][j-1])%MOD;
		}
	}

	cin >> t;

	while(t--)
		solve();
}