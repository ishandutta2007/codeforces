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

#define int ll
const int mod = 1e9+7;
const int N = 57;

int n, p;

int t[N];
int kom[N][N];
int par[N][2];
int dp[N][2][N][N];
int pot[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> p;

	pot[0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		pot[i] = (1ll<<i)%mod;
	}

	for(int i = 0; i <= n; ++i)
	{
		kom[i][0] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			kom[i][j] = (kom[i-1][j]+kom[i-1][j-1])%mod;
		}
	}

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			par[i][j%2] += kom[i][j];
			par[i][j%2] %= mod;
		}
	}

	dp[0][0][0][0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		for(int x = 0; x < 2; ++x)
		{
			for(int b = 0; b <= i-1; ++b)
			{
				for(int c = 0; b+c <= i-1; ++c)
				{
					if(t[i]!=1) //ustawiam bialy
					{
						dp[i][x^1][b+1][c] += dp[i-1][x][b][c]*par[c][0]%mod*pot[i-1-c]%mod;
						dp[i][x^1][b+1][c] %= mod;

						dp[i][x][b][c] += dp[i-1][x][b][c]*par[c][1]%mod*pot[i-1-c]%mod;
						dp[i][x][b][c] %= mod;
					}

					if(t[i]!=0) //ustawiam czarny
					{
						dp[i][x^1][b][c+1] += dp[i-1][x][b][c]*par[b][0]%mod*pot[i-1-b]%mod;
						dp[i][x^1][b][c+1] %= mod;

						dp[i][x][b][c] += dp[i-1][x][b][c]*par[b][1]%mod*pot[i-1-b]%mod;
						dp[i][x][b][c] %= mod;
					}
				}
			}
		}
	}

	int ans = 0;

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= n; ++j)
		{
			ans += dp[n][p][i][j];
			ans %= mod;
		}
	}

	cout << ans << endl;
}