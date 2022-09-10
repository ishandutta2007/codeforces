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
const int N = 1e6+7;

int n, m, ans;

int a[N];
int b[N];
int c[N];
int span[N];
int vis[N];

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

	rep[a] = b;
	return 1;
}

int dfs(int v)
{
	if(v==b[1])
		return 1;

	bool ret = 0;

	vis[v] = 1;

	for(auto it:G[v])
	{
		if(!vis[it.st])
		{
			if(dfs(it.st))
			{
				ret = 1;
				ans = max(ans, it.nd);
			}
		}
	}

	return ret;
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

	c[1] = inf;

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

	if(span[1])
	{
		cout << (int)1e9 << endl;
		return 0;
	}

	for(int i = 1; i <= m; ++i)
	{
		if(span[i])
		{
			debug(i);
			G[a[i]].eb(b[i], c[i]);
			G[b[i]].eb(a[i], c[i]);
		}
	}

	dfs(a[1]);

	cout << ans << endl;
}