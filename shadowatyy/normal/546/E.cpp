#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

#define N 207

#define S 0
#define T (2*n+1)

int n, m, ansa, ansb, u, v;

VI G[N];

int c[N][N];

int wyn[N][N];

int a[N];

int b[N];

int p[N];

bitset<N> vis;

bool dfs(int v, int t)
{
	vis[v] = 1;

	if(v==t)
		return 1;

	for(auto it:G[v])
	{
		if(!vis[it] && c[v][it])
		{	
			p[it] = v;

			if(dfs(it, t))
				return 1;
		}
	}

	return 0;
}

int flow(int s, int t)
{
	int res = 0;

	p[s] = s;

	while(dfs(s, t))
	{
		int v = t, f = inf;

		while(v!=s)
		{
			f = min(f, c[p[v]][v]);
			v = p[v];
		}

		v = t;

		while(v!=s)
		{
			wyn[p[v]][v] += f;
			wyn[v][p[v]] -= f;
			c[p[v]][v] -= f;
			c[v][p[v]] += f;
			v = p[v];
		}

		res += f;

		memset(p, 0, sizeof p);
		vis.reset();
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		c[S][i] += a[i];

		G[S].pb(i);
		G[i].pb(S);

		ansa += a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];

		c[i+n][T] += b[i];

		G[T].pb(i+n);
		G[i+n].pb(T);

		ansb += b[i];
	}

	while(m--)
	{
		cin >> v >> u;
		G[v].pb(u+n);
		G[u].pb(v+n);
		G[v+n].pb(u);
		G[u+n].pb(v);
		c[v][u+n] += inf;
		c[u][v+n] += inf;
	}

	for(int i = 1; i <= n; ++i)
	{
		G[i].pb(i+n);
		G[i+n].pb(i);
		c[i][i+n] += inf;
	}

	if(ansa==ansb && flow(S, T)==ansb)
	{
		cout << "YES" << endl;

		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				cout << wyn[i][j+n] << " ";
			}

			cout << endl;
		}
	}
	else
		cout << "NO";
}