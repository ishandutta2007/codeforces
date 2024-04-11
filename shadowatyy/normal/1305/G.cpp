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

const int L = 18;
const int N = 1<<L;

int n;

int a[N];
int rep[N];

pair<PII, PII> sos[N];

pair<PII, int> bestComp[N];

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

void wrzuc(int m, PII val)
{
	if(val.st==-inf)
		return;

	if(sos[m].st.st==-inf || Find(sos[m].st.nd)==Find(val.nd))
		sos[m].st = max(sos[m].st, val);
	else if(sos[m].nd.st==-inf || Find(sos[m].nd.nd)==Find(val.nd))
		sos[m].nd = max(sos[m].nd, val);
	else if(sos[m].st < val)
	{
		sos[m].nd = sos[m].st;
		sos[m].st = val;
	}
	else if(sos[m].nd < val)
		sos[m].nd = val;
}

void pisz()
{
	for(int i = 0; i < N; ++i)
	{
		debug(sos[i]);
	}

	debug("koniec");
}

void sosuj()
{
	for(int i = 0; i < N; ++i)
	{
		sos[i] = mp(mp(-inf, -inf), mp(-inf, -inf));
	}

	for(int i = 1; i <= n; ++i)
	{	
		wrzuc(a[i], mp(a[i], i));
	}

	//pisz();

	for(int b = 0; b < L; ++b)
	{
		for(int m = N-1; m >= 0; --m)
		{
			if(m&(1<<b))
			{
				wrzuc(m, sos[m^(1<<b)].st);
				wrzuc(m, sos[m^(1<<b)].nd);
			}
		}
	}

	//pisz();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	ll ans = 0;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		ans -= a[i];
		rep[i] = i;
	}

	++n;
	rep[n] = n;
	int comps = n;

	while(comps>1)
	{
		sosuj();
		
		for(int i = 1; i <= n; ++i)
		{
			bestComp[i] = mp(mp(-inf, -inf), -inf);
		}	

		for(int i = 1; i <= n; ++i)
		{
			int c = Find(i);
			int oki = ((N-1)^a[i]);

			if(Find(sos[oki].st.nd)!=c)
				maxi(bestComp[c], mp(mp(sos[oki].st.st+a[i], sos[oki].st.nd), i));
			else
				maxi(bestComp[c], mp(mp(sos[oki].nd.st+a[i], sos[oki].nd.nd), i));
		}

		/*for(int i = 1; i <= n; ++i)
		{
			if(Find(i)==i)
				debug(i, bestComp[i]);
		}*/

		//exit(0);

		for(int i = 1; i <= n; ++i)
		{
			if(i==rep[i])
			{
				int x = bestComp[i].st.nd;
				int y = bestComp[i].nd;

				if(Union(x, y))
				{
					--comps;
					ans += a[x];
					ans += a[y];
				}
			}
		}

		//debug(comps);
		//exit(0);
	}

	cout << ans << endl;
}