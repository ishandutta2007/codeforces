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

#define N 200007
//#define cerr if(0)cout

int n, m, q, a, b, c;

VPII G[N];
VI T[N];
VI D[N];

bitset<N> juz;
bitset<N> vis;

int comp[N];

int up[N];
int down[N];

VI post;

void dfs1(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!juz[it.nd])
		{
			juz[it.nd] = 1;
			T[it.st].pb(v);

			if(!vis[it.st])
				dfs1(it.st);
		}
	}	

	post.pb(v);
}

void dfs2(int v)
{
	comp[v] = c;

	for(auto it:T[v])
	{
		if(!comp[it])
			dfs2(it);
	}
}

void dfs3(int v)
{
	vis[v] = 1;

	for(auto it:D[v])
	{
		if(!vis[it])
		{
			dfs3(it);
			int ile = min(up[v], down[it])+min(down[v], up[it]);
			up[v] += up[it];
			down[v] += down[it];
			up[v] -= ile;
			down[v] -= ile;
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
		G[a].eb(b, i);
		G[b].eb(a, i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			dfs1(i);
	}

	c = 0;

	while(!post.empty())
	{
		if(!comp[post.back()])
		{
			++c;
			dfs2(post.back());
		}

		post.pop_back();
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:G[i])
		{
			if(comp[i]!=comp[it.st])
				D[comp[i]].pb(comp[it.st]);
		}
	}

	for(int i = 1; i <= c; ++i)
	{
		sort(ALL(D[i]));
		D[i].erase(unique(ALL(D[i])), D[i].end());
	}

	while(q--)
	{
		cin >> a >> b;

		if(comp[a]!=comp[b])
		{
			++up[comp[a]];
			++down[comp[b]];
		}
	}

	vis.reset();

	for(int i = 1; i <= c; ++i)
	{
		if(!vis[i])
			dfs3(i);
	}

	for(int i = 2; i <= c; ++i)
	{
		if(up[i] && down[i])
		{
			cout << "No";
			exit(0);
		}
	}

	if(up[1] || down[1])
	{
		cout << "No";
		exit(0);
	}

	cout << "Yes";
}