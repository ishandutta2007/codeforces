#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;
const long long mod = 1e9 + 7; 
const long long LOGN = 20;

long long n, m;
vector<long long> adj[N], adj_real[N];
long long parent[N], t;
long long comp[N], type[N], c, in[N];
long long prefix[N], lvl[N];
long long lca_table[N][LOGN];

void dfs(long long u, long long par)
{
	if(parent[u] != 0)
		return;

	parent[u] = par;
	in[u] = t;
	//cout << u << " in " << in[u] << endl;
	t++;

	for(long long to: adj[u])
	{
		if(to == par)
			continue;
		dfs(to, u);
	}
}

void make_cycle(long long from, long long to)
{
	c++;
	type[c] = 2;
	while(from != to)
	{
		comp[from] = c;
		from = parent[from];
	}

	comp[from] = c; 
}

void dfs2(long long u, long long par)
{
	if(par == -1)
	{
		prefix[u] = type[u];
		lvl[u] = 0;
	}
	else
	{
		prefix[u] = prefix[par] * type[u];
		lvl[u] = lvl[par] + 1;
	}

	prefix[u] %= mod;
	parent[u] = par;

	for(long long to: adj_real[u])
	{
		if(to == par)
			continue;
		dfs2(to, u);
	}
}

void init_lca()
{
	parent[1] = 1;

	for(long long i = 1; i <= c; i++)
		lca_table[i][0] = parent[i];

	for(long long j = 1; j < LOGN; j++)
		for(long long i = 1; i <= c; i++)
			lca_table[i][j] = lca_table[ lca_table[i][j-1] ][j-1];
}

long long go_up(long long u, long long times)
{
	if(!times)
		return u;

	for(long long i = LOGN - 1; i >= 0; i--)
		if(times & (1<<i))
			u = lca_table[u][i];

	return u;
}

long long calc_lca(long long u, long long v)
{
	if(lvl[u] > lvl[v])
		swap(u, v);

	v = go_up(v, lvl[v] - lvl[u]);

	//cout << u << " up " << v << endl;

	if(u == v)
		return u;

	for(long long i = LOGN - 1; i >= 0; i--)
		if(lca_table[u][i] != lca_table[v][i])
		{
			u = lca_table[u][i];
			v = lca_table[v][i];
		}

	u = lca_table[u][0];

	return u;
}

void init()
{
	dfs(1, -1);

	for(long long i = 1; i <= n; i++)
		for(long long to: adj[i])
			if(in[i] < in[to] && parent[to] != i)
			{
				//cout << to << " -- " << i << "\n"; 
				make_cycle(to, i);
			}

	for(long long i = 1; i <= n; i++)
		if(comp[i] == 0)
		{
			c++;
			comp[i] = c;
			type[c] = 1;
		}

	for(long long i = 1; i <= n; i++)
		for(long long to: adj[i])
			if(comp[i] != comp[to])
			{
				adj_real[ comp[i] ].push_back(comp[to]);
				//cout << comp[i] << " " <<comp[to] << " kk\n";
			}

	//cout << "pre dfs\n";

	dfs2(1, -1);

	//cout << "mid\n";

	init_lca();

	//cout << "finish init\n";
}

void read()
{
	cin >> n >> m;

	for(long long i = 0; i < m; i++)
	{
		long long u, v;

		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

long long fast_pow(long long base, long long exp)
{
	if(exp == 0)
		return 1ll;

	if(exp & 1)
	{
		long long res = fast_pow(base, exp - 1) * base;
		res %= mod;

		return res;
	}

	long long tmp = fast_pow(base, exp / 2);

	return (tmp * tmp) % mod;
}

long long find_ans(long long u, long long v)
{
	long long lca = calc_lca(u, v);

	//cout << lca << " lca " << u << " " << v << endl;

	long long res = prefix[u]*prefix[v];

	res %= mod;

	if(lca != 1)
	{
		res *= fast_pow(prefix[ parent[lca] ], mod-2);
		res %= mod;
	}
	res *= fast_pow(prefix[lca], mod-2);
	res %= mod;

	return res;
}

void solve()
{
	long long k;

	cin >> k;

	for(long long i = 0; i < k; i++)
	{
		long long x, y;

		cin >> x >> y;

		cout << find_ans(comp[x], comp[y]) << "\n";
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	read();
	init();
	solve();

	return 0;
}