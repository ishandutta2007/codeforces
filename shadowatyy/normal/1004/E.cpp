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
const int N = 1e5+7;

int n, k;

VPII G[N];

int dist[N];
int skad[N];
int h[N];
int deg[N];
int waga[N];

bool check(int u, int x)
{
	memset(deg, 0, sizeof deg);
	int cnt = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(i==u || h[i]+waga[i]>x)
		{
			++cnt;

			for(auto it:G[i])
				++deg[it.st];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(deg[i]>2)
			return 0;
	}

	return cnt<=k;
}

void dfs(int v, int p)
{
	for(auto it:G[v])
	{
		if(it.st!=p)
		{
			dist[it.st] = dist[v]+it.nd;
			skad[it.st] = v;
			dfs(it.st, v);
		}
	}
}

void solve(int v, int p)
{
	for(auto it:G[v])
	{
		if(it.st!=p)
		{
			waga[it.st] = it.nd;
			solve(it.st, v);
			h[v] = max(h[v], h[it.st]+it.nd);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i < n; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		G[a].eb(b, c);
		G[b].eb(a, c);
	}

	dfs(1, -1);
	int far1 = 1;

	for(int i = 2; i <= n; ++i)
	{
		if(dist[far1]<dist[i])
			far1 = i;
	}

	dist[far1] = 0;
	dfs(far1, -1);
	int far2 = 1;

	for(int i = 2; i <= n; ++i)
	{
		if(dist[far2]<dist[i])
			far2 = i;
	}

	VI path;
	int curr = far2;
	path.pb(curr);

	while(curr!=far1)
	{
		curr = skad[curr];
		path.pb(curr);
	}

	int len = dist[far2];
	int u = far1;

	for(auto it:path)
	{
		if(max(dist[it], len-dist[it])<max(dist[u], len-dist[u]))
			u = it;
	}

	solve(u, -1);

	int l = 0, r = 1e12;

	while(l<r)
	{
		int m = (l+r)/2;

		if(r==m)
			--m;

		if(check(u, m))
			r = m;
		else
			l = m+1;
	}

	cout << l << endl;
}