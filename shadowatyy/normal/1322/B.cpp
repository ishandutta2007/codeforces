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

const int N = 4e5+7;
const int L = 25;

int n, ans;

int a[N];

VI tyle[L][2];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		for(int b = 0; b < L; ++b)
		{
			int bit = 0;

			if(a[i]&(1<<b))
				bit = 1;

			int dol = (a[i]&((1<<b)-1));
			tyle[b][bit].pb(dol);
		}
	}

	for(int i = 0; i < L; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			sort(ALL(tyle[i][j]));
		}
	}

	for(int b = 0; b < L; ++b)
	{
		int curr = 0;

		for(int j = 0; j < 2; ++j)
		{
			for(int k = j; k < 2; ++k)
			{
				for(int ind = 0; ind < siz(tyle[b][j]); ++ind)
				{
					int dol = tyle[b][j][ind];
					int bez_zm, all;

					if(j!=k)
					{
						bez_zm = lower_bound(ALL(tyle[b][k]), (1<<b) - dol) - tyle[b][k].begin();
						all = siz(tyle[b][k]);
					}
					else
					{
						bez_zm = lower_bound(ALL(tyle[b][k]), (1<<b) - dol) - tyle[b][k].begin();
						mini(bez_zm, ind);
						all = ind;
					}

					if(j^k)
						curr += bez_zm;
					else
						curr += all-bez_zm;

					curr %= 2;
				}
			}
		}

		if(curr)
			ans ^= 1<<b;
	}

	cout << ans << endl;
}