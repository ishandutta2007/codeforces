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
const int N = 2e5+7;

int n, ans;

int V[N];

VI G[N];

int path[N];
int dep[N];

int ile_p[N];
int ile_np[N];
int sum_p[N];
int sum_np[N];

void dfs(int v, int u)
{
	for(auto it:G[v])
	{
		if(it!=u)
		{
			dep[it] = dep[v]+1;
			path[it] = (V[it]-path[v])%MOD;
			dfs(it, v);

			if(dep[v]%2==0)
			{
				ans += ile_p[it]*sum_p[v]%MOD + ile_p[v]*sum_p[it]%MOD;
				ans -= path[v]*ile_p[v]%MOD*ile_p[it]%MOD;
				ans += path[u]*ile_p[v]%MOD*ile_p[it]%MOD;

				ans %= MOD;

				ans += ile_np[it]*sum_np[v]%MOD + ile_np[v]*sum_np[it]%MOD;
				ans += path[v]*ile_np[v]%MOD*ile_np[it]%MOD;
				ans -= path[u]*ile_np[v]%MOD*ile_np[it]%MOD;

				ans %= MOD;
			}
			else
			{
				ans += ile_p[it]*sum_p[v]%MOD + ile_p[v]*sum_p[it]%MOD;
				ans += path[v]*ile_p[v]%MOD*ile_p[it]%MOD;
				ans -= path[u]*ile_p[v]%MOD*ile_p[it]%MOD;

				ans %= MOD;

				ans += ile_np[it]*sum_np[v]%MOD + ile_np[v]*sum_np[it]%MOD;
				ans -= path[v]*ile_np[v]%MOD*ile_np[it]%MOD;
				ans += path[u]*ile_np[v]%MOD*ile_np[it]%MOD;

				ans %= MOD;
			}

			ile_p[v] += ile_p[it];
			ile_np[v] += ile_np[it];

			ile_p[v] %= MOD;
			ile_np[v] %= MOD;

			sum_p[v] += sum_p[it];
			sum_np[v] += sum_np[it];

			sum_p[v] %= MOD;
			sum_np[v] %= MOD;
		}
	}

	if(dep[v]%2==0)
	{
		ans += sum_p[v];
		ans += ile_p[v]*path[u]%MOD;
		ans %= MOD;

		++ile_p[v];
		sum_p[v] += path[v];
		sum_p[v] %= MOD;
	}
	else
	{
		ans += sum_np[v];
		ans += ile_np[v]*path[u]%MOD;
		ans %= MOD;

		++ile_np[v];
		sum_np[v] += path[v];
		sum_np[v] %= MOD;
	}
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> V[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	int r = 1;

	path[r] = V[r];
	dfs(r, 0);

	ans *= 2;

	for(int i = 1; i <= n; ++i)
	{
		ans += V[i];
		ans %= MOD;
	}

	ans += MOD;
	ans %= MOD;

	cout << ans << endl;
}