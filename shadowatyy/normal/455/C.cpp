#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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
using namespace std;

#define N 300007

int n, m, q, c, a, b, t;

int diam[N];

int dist[N];
int far[N];
int comp[N];

bitset<N> vis;

VI G[N];

int Find(int a)
{
	if(comp[a]!=a)
		comp[a] = Find(comp[a]);

	return comp[a];
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a==b)
		return;

	comp[a] = b;
	diam[b] = max(diam[a], max(diam[b], (diam[a]+1)/2+(diam[b]+1)/2+1));
}

void dfs1(int v)
{
	comp[v] = c;

	if(dist[v]>dist[far[c]])
		far[c] = v;

	for(auto it:G[v])
	{
		if(!comp[it])
		{
			dist[it] = dist[v]+1;
			dfs1(it);
		}
	}
}

void dfs2(int v)
{
	vis[v] = 1;
	diam[comp[v]] = max(diam[comp[v]], dist[v]);

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dist[it] = dist[v]+1;
			dfs2(it);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> q;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!comp[i])
		{
			c = i;
			far[c] = i;
			dfs1(i);
		}
	}

	memset(dist, 0, sizeof dist);

	for(int i = 1; i <= n; ++i)
	{
		if(comp[i]==i)
			dfs2(far[i]);
	}

	while(q--)
	{
		cin >> t >> a;

		if(t==2)
		{
			cin >> b;
			Union(a, b);
		}
		else
			cout << diam[Find(a)] << endl;
	}
}