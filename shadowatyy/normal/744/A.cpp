#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 1007

int n, m, k, c, a, b, odw;

VI G[N];

int g[N];

int size[N];

bitset<N> vis;

ll res;

void dfs(int v)
{
	vis[v] = 1;

	++size[c];

	++odw;

	for(auto u:G[v])
	{
		if(!vis[u])
			dfs(u);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= k; ++i)
	{
		cin >> g[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	for(int i = 1; i <= k; ++i)
	{
		c = i;

		dfs(g[i]);
	}

	sort(size+1, size+1+k);

	size[k] += (n-odw);

	for(int i = 1; i <= k; ++i)
	{
		res += (ll)size[i]*(size[i]-1)/2;
	}

	cout << res-m;
}