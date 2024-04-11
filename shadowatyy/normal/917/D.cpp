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
const int N = 107;

int n;

VI G[N];

int dp[N][N][N]; //korzen, rozmiar jego czesci, ile krawedzi pominalem

int ans[N];

int newton[N][N];

int sub[N];

int inv[N];

int fpow(int a, int b)
{
	int res = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(b&(1<<i))
		{
			res *= a;
			res %= MOD;
		}

		a *= a;
		a %= MOD;
	}

	return res;
}

void dfs(int v, int p)
{
	sub[v] = 1;
	dp[v][1][0] = 1;

	for(auto u:G[v])
	{
		if(u==p)
			continue;

		dfs(u, v);

		for(int rv = sub[v]; rv >= 1; --rv)
		{
			for(int kv = sub[v]-1; kv >= 0; --kv)
			{
				for(int ru = 1; ru <= sub[u]; ++ru)
				{
					for(int ku = 0; ku <= sub[u]-1; ++ku)
					{
						dp[v][rv+ru][kv+ku] += dp[v][rv][kv]*dp[u][ru][ku]%MOD*inv[rv]%MOD*inv[ru]%MOD*(rv+ru)%MOD;
						dp[v][rv][kv+ku+1] += dp[v][rv][kv]*dp[u][ru][ku]%MOD;

						dp[v][rv+ru][kv+ku] %= MOD;
						dp[v][rv][kv+ku+1] %= MOD;
					}
				}

				dp[v][rv][kv] = 0;
			}
		}	

		sub[v] += sub[u];
	}

}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;	

	for(int i = 1; i <= n; ++i)
	{
		inv[i] = fpow(i, MOD-2);
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 0; i <= n; ++i)
	{
		newton[i][0] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			newton[i][j] = (newton[i-1][j-1]+newton[i-1][j])%MOD;
		}
	}

	dfs(1, -1);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j <= n-1; ++j)
		{	
			if(!dp[1][i][j])
				continue;

			ans[n-1-j] += dp[1][i][j]*fpow(n, j-1+MOD-1)%MOD;
			ans[n-1-j] %= MOD;
		}
	}

	for(int i = n-1; i >= 0; --i)
	{
		for(int j = i+1; j <= n-1; ++j)
		{
			ans[i] -= ans[j]*newton[j][i]%MOD;
			ans[i] %= MOD;
		}

		ans[i] += MOD;
		ans[i] %= MOD;
	}

	for(int i = 0; i <= n-1; ++i)
	{
		cout << ans[i] << " ";
	}
}