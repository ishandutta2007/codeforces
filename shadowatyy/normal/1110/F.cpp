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

const int N = 1<<19;

int n, q;

VPII G[N];

int deg[N];
int sub[2*N];
int lazy[2*N];
int dist[N];
int ans[N];
int u[N];
int l[N];
int r[N];
int Min[N];
int Max[N];
VI odp[N];

void push(int v)
{
	if(lazy[v])
	{
		lazy[2*v] += lazy[v];
		lazy[2*v+1] += lazy[v];
		sub[2*v] += lazy[v];
		sub[2*v+1] += lazy[v];
		lazy[v] = 0;
	}
}

void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
{
	if(a>b || a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		sub[v] += c;
		lazy[v] += c;
		return;
	}

	push(v);
	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = min(sub[2*v], sub[2*v+1]);
}

int query(int a, int b, int v = 1, int l = 0, int r = N-1)
{
	if(a>b || a>r || l>b)
		return INF;

	if(a<=l && r<=b)
		return sub[v];

	push(v);
	int ans = min(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
	sub[v] = min(sub[2*v], sub[2*v+1]);
	return ans;
}

void dfs(int v)
{
	if(deg[v]==1)
		Min[v] = Max[v] = v;
	else
	{
		Min[v] = inf;
		Max[v] = -inf;
	}

	for(auto it:G[v])
	{
		dist[it.st] = dist[v] + it.nd;
		dfs(it.st);
		Min[v] = min(Min[v], Min[it.st]);
		Max[v] = max(Max[v], Max[it.st]);
	}
}

void solve(int v)
{
	debug(v, Min[v], Max[v]);

	for(auto it:odp[v])
	{
		ans[it] = query(l[it], r[it]);
	}

	for(auto it:G[v])
	{
		insert(1, n, it.nd);
		insert(Min[it.st], Max[it.st], -2*it.nd);
		solve(it.st);
		insert(Min[it.st], Max[it.st], 2*it.nd);
		insert(1, n, -it.nd);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 2; i <= n; ++i)
	{
		int p, w;
		cin >> p >> w;
		++deg[p];
		++deg[i];
		G[p].eb(i, w);
	}

	for(int i = 1; i <= q; ++i)
	{
		cin >> u[i] >> l[i] >> r[i];
		odp[u[i]].pb(i);
	}

	dfs(1);

	for(int i = 1; i <= n; ++i)
	{
		debug(i, dist[i]);

		if(deg[i]==1)
			insert(i, i, dist[i]);
		else
			insert(i, i, INF);
	}

	solve(1);

	for(int i = 1; i <= q; ++i)
	{
		cout << ans[i] << endl;
	}
}