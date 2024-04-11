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

const int N = 1<<19;

int n, ans;

int x[2][N];
int y[2][N];

VI kon[N];
VI pocz[N];

VI val;

int load[2*N];

int query(int a, int b)
{
	a += N-1;
	b += N+1;

	int res = -inf;

	while(a<b-1)
	{
		if(a%2==0)
			maxi(res, load[a+1]);

		if(b%2==1)
			maxi(res, load[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

void insert(int a, int v)
{
	a += N;

	while(a)
	{	
		maxi(load[a], v);
		a /= 2;
	}
}

void clear()
{
	for(int i = 0; i < 2*N; ++i)
	{
		load[i] = -inf;
	}

	for(int i = 0; i < N; ++i)
	{
		pocz[i].clear();
		kon[i].clear();
	}
}

void solve()
{
	clear();

	for(int i = 1; i <= n; ++i)
	{
		pocz[x[0][i]].pb(i);
		kon[y[0][i]].pb(i);
	}

	for(int i = 0; i < N; ++i)
	{
		if(i)
		{
			for(auto it:kon[i-1])
				insert(x[1][it], y[1][it]);
		}

		for(auto it:pocz[i])
		{
			if(query(0, y[1][it]) >= x[1][it])
				ans = 1;
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
		for(int j = 0; j < 2; ++j)
		{
			cin >> x[j][i] >> y[j][i];
			val.pb(x[j][i]);
			val.pb(y[j][i]);
		}
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			x[j][i] = lower_bound(ALL(val), x[j][i])-val.begin();
			y[j][i] = lower_bound(ALL(val), y[j][i])-val.begin();
		}
	}

	solve();

	for(int i = 1; i <= n; ++i)
	{
		swap(x[0][i], x[1][i]);
		swap(y[0][i], y[1][i]);
	}

	solve();

	if(ans)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}