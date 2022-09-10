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

const int N = 1e6+7;

int n, m;

VI G[N][2];

int ans[N];

void clear()
{
	for(int i = 1; i <= n; ++i)
	{
		G[i][0].clear();
		G[i][1].clear();
	}
}

void wez(int v, int d)
{
	ans[v] = d;

	for(auto it:G[v][d])
	{
		if(ans[it]==-1)
			wez(it, d);
	}
}

void solve()
{
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		ans[i] = -1;
	}

	for(int i = 1; i <= m; ++i)
	{
		int a, b;
		cin >> a >> b;
		G[a][0].pb(b);
		G[b][1].pb(a);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i]==-1)
		{
			wez(i, 0);
			break;
		}
	}

	bool ok = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(ans[i]==-1)
		{
			wez(i, 1);
			ok = 1;
		}
	}

	if(!ok)
	{
		for(int i = 1; i <= n; ++i)
		{
			ans[i] = -1;
		}

		for(int i = 1; i <= n; ++i)
		{
			if(ans[i]==-1)
			{
				wez(i, 1);
				break;
			}
		}

		ok = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(ans[i]==-1)
			{
				wez(i, 0);
				ok = 1;
			}
		}
	}

	if(!ok)
		cout << "No" << endl;
	else
	{	
		cout << "Yes" << endl;

		int cnt = 0;

		for(int i = 1; i <= n; ++i)
		{
			if(!ans[i])
				++cnt;
		}

		cout << cnt << " " << n-cnt << endl;

		for(int i = 1; i <= n; ++i)
		{
			if(!ans[i])
				cout << i << " ";
		}

		cout << endl;

		for(int i = 1; i <= n; ++i)
		{
			if(ans[i])
				cout << i << " ";
		}

		cout << endl;
	}

	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--)
		solve();
}