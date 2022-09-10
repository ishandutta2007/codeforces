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

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 2007;

int n;

VI G[N];

int ans[N];
int p[N];
int c[N];
int sub[N];

void fail()
{
	cout << "NO" << endl;
	exit(0);
}

void get(int v, VPII &vec)
{
	vec.eb(ans[v], v);

	for(auto it:G[v])
	{
		get(it, vec);
	}
}

void dfs(int v)
{
	sub[v] = 1;

	for(auto it:G[v])
	{
		dfs(it);
		sub[v] += sub[it];
	}

	if(c[v]>=sub[v])
		fail();

	VPII vec;

	for(auto it:G[v])
	{
		get(it, vec);
	}

	sort(ALL(vec));

	for(int i = 0; i < c[v]; ++i)
	{
		ans[vec[i].nd] = i;
	}

	ans[v] = c[v];

	for(int i = c[v]; i < siz(vec); ++i)
	{
		ans[vec[i].nd] = i+1;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	int r = -1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i] >> c[i];
		G[p[i]].pb(i);

		if(!p[i])
			r = i;
	}

	dfs(r);

	cout << "YES" << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i]+1 << " ";
	}

	cout << endl;
}