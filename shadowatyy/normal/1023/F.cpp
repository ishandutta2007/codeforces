#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using VLL = vector<ll>;
using PII = pair<int, int>;
using VPII = vector<PII>;
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 5e5+7;

int n, k, m;

int ga[N];
int gb[N];
int fa[N];
int fb[N];
int fw[N];
int rep[N];
int spo[N];
int mini[N];
int sub[N];
int max_sub[N];
int comp[N];

bitset<N> del;

VPII G[N];

VI curr;

ll ans;

void dfs1(int v, int p)
{
	sub[v] = 1;
	max_sub[v] = 0;
	curr.pb(v);

	for(auto it:G[v])
	{
		int u = it.st;

		if(!del[u] && u!=p)
		{
			dfs1(u, v);
			sub[v] += sub[u];
			max_sub[v] = max(max_sub[v], sub[u]);
		}
	}
}

void dfs2(int v, int p, int nr)
{
	spo[v] = nr;

	for(auto it:G[v])
	{
		int u = it.st;

		if(!del[u] && u!=p)
			dfs2(u, v, nr);
	}
}

int res[N];

void dfs3(int v, int p, int e)
{
	for(auto it:G[v])
	{
		int u = it.st;

		if(!del[u] && u!=p)
		{
			dfs3(u, v, it.nd);
			mini[v] = min(mini[v], mini[u]);
		}
	}

	res[e] = min(res[e], mini[v]);
}

void go(int v, VI jego)
{
	curr.clear();
	dfs1(v, -1);

	for(auto &it:curr)
	{
		max_sub[it] = max(max_sub[it], (int)curr.size()-sub[it]);

		if(max_sub[curr[0]]>max_sub[it])
			swap(curr[0], it);
	}

	int centro = curr[0];
	int cnt = 0;
	del[centro] = 1;
	spo[centro] = 0;

	for(auto it:curr)
	{
		mini[it] = inf;
	}

	for(auto it:G[centro])
	{
		if(!del[it.st])
			dfs2(it.st, centro, ++cnt);
	}

	vector<VI> potem(cnt+1);

	for(auto it:jego)
	{
		if(spo[fa[it]]!=spo[fb[it]])
		{	
			mini[fa[it]] = min(mini[fa[it]], fw[it]);
			mini[fb[it]] = min(mini[fb[it]], fw[it]);
		}
		else
			potem[spo[fa[it]]].pb(it);
	}	

	for(auto it:G[centro])
	{
		if(!del[it.st])
			dfs3(it.st, centro, it.nd);
	}

	for(auto it:G[centro])
	{
		if(!del[it.st])
			go(it.st, potem[spo[it.st]]);
	}
}

int Find(int a)
{
	if(rep[a]!=a)
		rep[a] = Find(rep[a]);

	return rep[a];
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a==b)
		return 0;

	rep[a] = b;
	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> m;

	for(int i = 1; i <= n; ++i)
	{	
		rep[i] = i;
	}

	for(int i = 1; i <= k; ++i)
	{
		cin >> ga[i] >> gb[i];
		G[ga[i]].eb(gb[i], i);
		G[gb[i]].eb(ga[i], i);
		Union(ga[i], gb[i]);
	}

	VI jego;

	for(int i = 1; i <= m; ++i)
	{
		cin >> fa[i] >> fb[i] >> fw[i];
		
		if(Union(fa[i], fb[i]))
		{
			G[fa[i]].eb(fb[i], 0);
			G[fb[i]].eb(fa[i], 0);
		}
		else
			jego.pb(i);
	}

	for(int i = 1; i <= k; ++i)
	{
		res[i] = inf;
	}	

	go(1, jego);

	for(int i = 1; i <= k; ++i)
	{
		if(res[i]==inf)
		{
			cout << -1;
			return 0;
		}

		ans += res[i];
	}

	cout << ans << endl;
}