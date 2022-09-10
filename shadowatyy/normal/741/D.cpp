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

const int N = 5e5+7;

int n;

vector<pair<int, char> > G[N];

int dsu[1<<23];

int path[N];
int res[N];
int sub[N];
int d[N];

void dfs(int v)
{
	sub[v] = 1;

	for(auto it:G[v])
	{
		d[it.st] = d[v]+1;
		path[it.st] = path[v]^(1<<(it.nd-'a'));
		dfs(it.st);
		sub[v] += sub[it.st];
	}
}

void clear(int v)
{
	dsu[path[v]] = -inf;

	for(auto it:G[v])
		clear(it.st);
}

void update(int v, int r)
{
	res[r] = max(res[r], dsu[path[v]]+d[v]-2*d[r]);

	for(int i = 0; i < 22; ++i)
		res[r] = max(res[r], dsu[path[v]^(1<<i)]+d[v]-2*d[r]);

	for(auto it:G[v])
		update(it.st, r);
}

void add(int v)
{
	dsu[path[v]] = max(dsu[path[v]], d[v]);

	for(auto it:G[v])
		add(it.st);
}

void solve(int v)
{
	PII h = mp(-1, -1);

	for(auto it:G[v])
		h = max(h, mp(sub[it.st], it.st));

	if(h.nd!=-1)
	{
		for(auto it:G[v])
		{
			if(it.st!=h.nd)
			{
				solve(it.st);
				res[v] = max(res[v], res[it.st]);
				clear(it.st);
			}
		}		

		solve(h.nd);
		res[v] = max(res[v], res[h.nd]);

		for(auto it:G[v])
		{
			if(it.st!=h.nd)
			{
				update(it.st, v);
				add(it.st);
			}
		}
	}

	res[v] = max(res[v], dsu[path[v]]-d[v]);

	for(int i = 0; i < 22; ++i)
	{
		res[v] = max(res[v], dsu[path[v]^(1<<i)]-d[v]);
	}

	dsu[path[v]] = max(dsu[path[v]], d[v]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	memset(dsu, -inf16, sizeof dsu);

	cin >> n; 

	for(int i = 2; i <= n; ++i)
	{
		int a;
		char c;
		cin >> a >> c;
		G[a].eb(i, c);
	}

	dfs(1);
	solve(1);

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}