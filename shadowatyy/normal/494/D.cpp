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

#define int long long
#define N 100007
#define L 18
#define MOD 1000000007

int n, q, c;

vector<pair<int, ll> > G[N];

int p[L][N];
ll sub[3][N];
ll all[3][N];
ll upp[3][N];
int pre[N];
int post[N];
ll d[N];

void dfs1(int v)
{
	pre[v] = ++c;
	sub[0][v] = 1;

	for(auto it:G[v])
	{
		if(it.st!=p[0][v])
		{
			p[0][it.st] = v;
			d[it.st] = (d[v]+it.nd)%MOD;
			dfs1(it.st);
			sub[0][v] += sub[0][it.st];
			sub[1][v] += sub[1][it.st]+sub[0][it.st]*it.nd%MOD;
			sub[2][v] += sub[2][it.st]+sub[0][it.st]*it.nd%MOD*it.nd%MOD+2*it.nd%MOD*sub[1][it.st]%MOD;
			sub[0][v] %= MOD;
			sub[1][v] %= MOD;
			sub[2][v] %= MOD;
		}
	}

	post[v] = c;
}

void dfs2(int v)
{
	for(auto it:G[v])
	{
		if(it.st!=p[0][v])
		{
			all[1][it.st] = all[1][v];
			all[1][it.st] += (n-sub[0][it.st])*it.nd%MOD;
			all[1][it.st] -= sub[0][it.st]*it.nd%MOD;
			all[2][it.st] = all[2][v];
			all[2][it.st] += (n-sub[0][it.st])*it.nd%MOD*it.nd%MOD+2*it.nd%MOD*(all[1][v]-(sub[1][it.st]+sub[0][it.st]*it.nd%MOD))%MOD;
			all[2][it.st] -= sub[0][it.st]*it.nd%MOD*it.nd%MOD+2*it.nd%MOD*sub[1][it.st]%MOD;
			all[1][it.st] %= MOD;
			all[2][it.st] %= MOD;
			all[1][it.st] += MOD;
			all[2][it.st] += MOD;
			all[1][it.st] %= MOD;
			all[2][it.st] %= MOD;
			dfs2(it.st);
		}
	}
}

bool child(int a, int b)
{
	return pre[a]>=pre[b] && post[a]<=post[b];
}

int lca(int a, int b)
{
	if(child(a, b))
		return b;

	if(child(b, a))
		return a;

	int l = L-1;

	while(l>=0)
	{
		if(child(a, p[l][b]))
			--l;
		else
			b = p[l][b];
	}

	return p[0][b];
}

ll dist(int a, int b)
{
	return d[a]+d[b]-2*d[lca(a, b)];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	p[0][1] = 1;

	dfs1(1);

	for(int i = 1; i <= n; ++i)
	{
		all[0][i] = n;
	}

	all[1][1] = sub[1][1];
	all[2][1] = sub[2][1];

	dfs2(1);

	for(int l = 1; l < L; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			p[l][i] = p[l-1][p[l-1][i]];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		upp[0][i] = (all[0][i]-sub[0][i]+MOD)%MOD;
		upp[1][i] = (all[1][i]-sub[1][i]+MOD)%MOD;
		upp[2][i] = (all[2][i]-sub[2][i]+MOD)%MOD;
	}

	cin >> q;

	while(q--)
	{
		int u, v;

		ll d, res = 0;

		cin >> u >> v;

		d = dist(u, v);

		if(!child(u, v))
		{
			res += sub[2][v]+sub[0][v]*d%MOD*d%MOD+2*d%MOD*sub[1][v]%MOD;
			res -= all[2][u]-(sub[2][v]+sub[0][v]*d%MOD*d%MOD+2*d%MOD*sub[1][v]%MOD);
			res %= MOD;
			res += MOD;
			res %= MOD;
			cout << res << endl;
		}
		else
		{
			res -= upp[2][v]+upp[0][v]*d%MOD*d%MOD+2*d%MOD*upp[1][v]%MOD;
			res += all[2][u]-(upp[2][v]+upp[0][v]*d%MOD*d%MOD+2*d%MOD*upp[1][v]%MOD);
			res %= MOD;
			res += MOD;
			res %= MOD;
			cout << res << endl;
		}
	}
}