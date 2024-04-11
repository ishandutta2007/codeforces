#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair
#define siz(c) SIZ(c)
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#define int ll
const int N = 1e5+7;
const int M = 1e6+7;
const int L = 20;

int n, m, ans, cnt;

int a[M];
int b[M];
int c[M];
int span[M];
int vis[N];
int dep[N];

int p[L][N];
int q[L][N];

int pre[N];
int post[N];

int path[N];

VPII G[N];

VI vec;

int rep[N];

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

	if(dep[b]>dep[a])
		swap(a, b);

	rep[a] = b;
	return 1;
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

	int i = L-1;

	while(i>=0)
	{
		if(child(a, p[i][b]))
			--i;
		else
			b = p[i][b];
	}

	return p[0][b];
}

int up(int a, int l)
{
	int skok = dep[a]-dep[l];
	int ans = 0;

	for(int i = 0; i < 20; ++i)
	{
		if(skok&(1<<i))
		{
			ans = max(ans, q[i][a]);
			a = p[i][a];
		}
	}

	return ans;
}

int query(int a, int b)
{
	int l = lca(a, b);
	return max(up(a, l), up(b, l));
}

void dfs(int v)
{
	vis[v] = 1;
	pre[v] = ++cnt;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			dep[it.st] = dep[v]+1;
			p[0][it.st] = v;
			q[0][it.st] = it.nd;
			dfs(it.st);
		}
	}

	post[v] = cnt;
}

void insertPathUp(int a, int l, int c)
{
	int curr = Find(a);

	while(dep[curr]>dep[l])
	{
		path[curr] = c;
		Union(curr, p[0][curr]);
		curr = Find(curr);
	}
}

void insertPath(int a, int b, int c)
{
	int l = lca(a, b);
	insertPathUp(a, l, c);
	insertPathUp(b, l, c);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		vec.pb(i);
	}

	sort(ALL(vec), [](int x, int y)
	{
		return c[x]<c[y];
	});

	for(int i = 1; i <= n; ++i)
	{
		rep[i] = i;
	}

	for(auto it:vec)
	{
		if(Union(a[it], b[it]))
			span[it] = 1;
	}

	for(int i = 1; i <= m; ++i)
	{
		if(span[i])
		{
			G[a[i]].eb(b[i], c[i]);
			G[b[i]].eb(a[i], c[i]);
		}
	}

	q[0][1] = -inf;
	p[0][1] = 1;
	dfs(1);

	for(int l = 1; l < L; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			p[l][i] = p[l-1][p[l-1][i]];
			q[l][i] = max(q[l-1][i], q[l-1][p[l-1][i]]);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		rep[i] = i;
	}

	VI poza;

	for(int i = 1; i <= m; ++i)
	{
		if(!span[i])
			poza.pb(i);
	}

	sort(ALL(poza), [](int x, int y)
	{
		return c[x]<c[y];
	});

	for(int i = 1; i <= n; ++i)
	{
		path[i] = 1e9;
	}

	for(auto it:poza)
	{
		insertPath(a[it], b[it], c[it]);
	}

	for(int i = 1; i <= m; ++i)
	{
		if(!span[i])
			cout << query(a[i], b[i]) << endl;
		else
		{
			if(dep[a[i]]>dep[b[i]])
				cout << path[a[i]] << endl;
			else
				cout << path[b[i]] << endl;
		}
	}
}