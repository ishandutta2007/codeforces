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

const int N = 1<<12;

int t, n, m, k;

int a[N];

int load[2*N];

void insert(int a, int v)
{
	a += N;

	while(a)
	{
		mini(load[a], v);
		a /= 2;
	}
}

int query(int a, int b)
{
	a += N-1;
	b += N+1;

	int res = inf;

	while(a<b-1)
	{
		if(a%2==0)
			mini(res, load[a+1]);

		if(b%2==1)
			mini(res, load[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}
void solve()
{
	for(int i = 0; i < 2*N; ++i)
	{
		load[i] = inf;
	}

	cin >> n >> m >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	int left = n - m + 1;

	for(int i = 1; i + left - 1 <= n; ++i)
	{
		insert(i, max(a[i], a[i+left-1]));
	}

	int fix = min(k, m-1);
	int nonfix = m-1 - fix;
	int len = n-fix;
	int ans = -inf;

	for(int i = 1; i+len-1 <= n; ++i)
	{
		maxi(ans, query(i, i+nonfix));
	}

	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}