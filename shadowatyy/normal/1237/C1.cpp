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

const int N = 50007;

int n;

int x[N];
int y[N];
int z[N];

set<PII> X;
map<int, set<PII> > Y;
map<PII, set<PII> > Z;

int del[N];

void dodaj(int i)
{
	X.insert(mp(x[i], i));
	Y[x[i]].insert(mp(y[i], i));
	Z[mp(x[i], y[i])].insert(mp(z[i], i));
}

void usun(int i)
{
	X.erase(mp(x[i], i));
	Y[x[i]].erase(mp(y[i], i));

	if(Y[x[i]].empty())
		Y.erase(x[i]);

	Z[mp(x[i], y[i])].erase(mp(z[i], i));

	if(Z[mp(x[i], y[i])].empty())
		Z.erase(mp(x[i], y[i]));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i] >> z[i];
		dodaj(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(del[i])
			continue;

		del[i] = 1;
		usun(i);

		auto itx = X.lower_bound(mp(x[i], -1));

		if(itx==X.end())
			--itx;

		auto ity = Y[itx->st].lower_bound(mp(y[i], -1));

		if(ity==Y[itx->st].end())
			--ity;

		auto itz = Z[mp(itx->st, ity->st)].lower_bound(mp(z[i], -1));

		if(itz==Z[mp(itx->st, ity->st)].end())
			--itz;

		cout << i << " " << itz->nd << endl;
		del[itz->nd] = 1;
		usun(itz->nd);
	}
}