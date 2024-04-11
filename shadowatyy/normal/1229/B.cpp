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

const int mod = 1e9+7;
#define int ll
const int N = 1e5+7;

int n, ans;

int x[N];

VI G[N];

int vis[N];
int dep[N];

VPII stos[N];

int gcd(int a, int b)
{
	if(!a)
		return b;

	if(!b)
		return a;

	return __gcd(a, b);
}

VPII popraw(VPII s)
{
	VPII ans;

	for(auto it:s)
	{
		if(!ans.empty() && ans.back().st==it.st)
			ans.pop_back();

		ans.pb(it);
	}

	return ans;
}

void dfs(int v)
{	
	vis[v] = 1;

	for(auto &it:stos[v])
	{
		it.st = gcd(it.st, x[v]);
	}

	stos[v].eb(x[v], dep[v]);
	stos[v] = popraw(stos[v]);

	for(int i = 1; i < siz(stos[v]); ++i)
	{
		ans += stos[v][i].st * (stos[v][i].nd - stos[v][i-1].nd);
		ans %= mod;
	}
 
	ans += stos[v][0].st * (stos[v][0].nd + 1);
	ans %= mod;

	for(auto it:G[v])
	{
		if(!vis[it])
		{
			dep[it] = dep[v] + 1;
			stos[it] = stos[v];
			dfs(it);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}

	for(int i = 1; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);

	cout << ans << endl;
}