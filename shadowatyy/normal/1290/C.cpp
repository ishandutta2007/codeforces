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

const int N = 3e5+7;

int n, k, ans;

string s;

int a[N];
int b[N];

int kol[N];
int jaka[N];
VI spo[N];
int czar[N];
int bial[N];
int musze[N];

void dodaj(int x, int y, int zmiana)
{
	//debug(I(x), I(y), I(jaka[x]), I(jaka[y]), I(kol[x]), I(kol[y]), I(zmiana), I(spo[jaka[x]]), I(spo[jaka[y]]));

	if(jaka[x]==jaka[y])
		return;

	if(siz(spo[jaka[x]])<siz(spo[jaka[y]]))
		swap(x, y);

	if(musze[jaka[x]]==-1)
		ans -= min(czar[jaka[x]], bial[jaka[x]]);
	else if(musze[jaka[x]])
		ans -= czar[jaka[x]];
	else
		ans -= bial[jaka[x]];

	if(musze[jaka[y]]==-1)
		ans -= min(czar[jaka[y]], bial[jaka[y]]);
	else if(musze[jaka[y]])
		ans -= czar[jaka[y]];
	else
		ans -= bial[jaka[y]];

	int X = jaka[x];
	int Y = jaka[y];

	if((kol[x] == kol[y] && !zmiana) || (kol[x] != kol[y] && zmiana))
	{
		if(musze[Y]!=-1)
		{
			musze[X] = musze[Y];
		}

		for(auto it:spo[Y])
		{
			spo[X].pb(it);
			jaka[it] = X;

			if(kol[it])
				++czar[X];
			else
				++bial[X];
		}
	}
	else
	{
		if(musze[Y]!=-1)
		{
			musze[Y] ^= 1;
			musze[X] = musze[Y];
		}

		for(auto it:spo[Y])
		{
			spo[X].pb(it);
			kol[it] ^= 1;
			jaka[it] = X;

			if(kol[it])
				++czar[X];
			else
				++bial[X];
		}
	}

	spo[Y].clear();
	spo[Y].shrink_to_fit();

	//debug(I(spo[jaka[x]]), I(spo[jaka[y]]));

	if(musze[X]==-1)
		ans += min(czar[X], bial[X]);
	else if(musze[X])
		ans += czar[X];
	else
		ans += bial[X];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s;
	s = '#' + s;

	for(int i = 1; i <= k; ++i)
	{
		int c;
		cin >> c;

		while(c--)
		{
			int x;
			cin >> x;

			if(!a[x])
				a[x] = i;
			else
				b[x] = i;
		}
	}

	for(int i = 1; i <= k; ++i)
	{
		jaka[i] = i;
		spo[i].pb(i);
		bial[i] = 1;
		musze[i] = -1;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i] && !b[i])
		{	
			int x = a[i];

			if(musze[jaka[x]]==-1)
				ans -= min(czar[jaka[x]], bial[jaka[x]]);
			else if(musze[jaka[x]])
				ans -= czar[jaka[x]];
			else
				ans -= bial[jaka[x]];

			if(s[i]=='0')
				musze[jaka[x]] = kol[x];
			else
				musze[jaka[x]] = !kol[x];

			if(musze[jaka[x]]==-1)
				ans += min(czar[jaka[x]], bial[jaka[x]]);
			else if(musze[jaka[x]])
				ans += czar[jaka[x]];
			else
				ans += bial[jaka[x]];
		}
		else if(a[i] && b[i])
		{
			if(s[i]=='0')
				dodaj(a[i], b[i], 1);
			else
				dodaj(a[i], b[i], 0);
		}

		cout << ans << endl;
	}


}