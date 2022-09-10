#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
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
const int N = 3007;

int n, D, ans;

int kom[N][N];
int dp[N][N];
int rozne[N];
int fact[N];
int rev[N];
int inv[N];

VI G[N];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%mod;

		b /= 2;
		a = a*a%mod;
	}

	return res;
}

void dfs(int v)
{	
	for(int i = 1; i <= n; ++i)
	{
		dp[v][i] = 1;
	}

	for(auto u:G[v])
	{
		dfs(u);

		for(int i = 1; i <= n; ++i)
		{
			dp[u][i] += dp[u][i-1];
			dp[u][i] %= mod;
			dp[v][i] *= dp[u][i];
			dp[v][i] %= mod;
		}
	}
}

int kom_brut(int n, int k)
{	
	int ans = 1;

	for(int i = n-k+1; i <= n; ++i)
	{
		ans = ans*i%mod;
	}

	ans = ans*rev[k]%mod;
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = i*fact[i-1]%mod;
		rev[i] = fpow(fact[i], mod-2);
		inv[i] = fpow(i, mod-2);
	}

	for(int i = 0; i < N; ++i)
	{
		kom[i][0] = 1;
	}

	for(int i = 1; i < N; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			kom[i][j] = (kom[i-1][j-1]+kom[i-1][j])%mod;
		}
	}

	cin >> n >> D;

	for(int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		G[p].pb(i);
	}

	dfs(1);

	for(int i = 0; i <= n; ++i)
	{
		if(i>0)
		{
			dp[1][i] += dp[1][i-1];
			dp[1][i] %= mod;
		}

		int ilo = 1;

		for(int j = 0; j <= n; ++j)
		{
			if(i!=j)
			{
				ilo *= D-j;
				ilo %= mod;
				ilo *= i>j?inv[i-j]:-inv[j-i];
				ilo %= mod;
			}
		}

		ans += ilo*dp[1][i]%mod;
		ans %= mod;
	}

	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;
}