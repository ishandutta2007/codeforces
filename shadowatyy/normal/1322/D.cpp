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

const int N = 2027;

int n, m;

int l[N];
int c[N];
int dp[N][N];
int p[N+N];
int all[N];

int pykMemo[N][N];

int pyk(int i, int mam)
{
	if(pykMemo[i][mam]!=-inf)
		return pykMemo[i][mam];

	int val = 0;
	int curr = mam;

	for(int k = i; curr; ++k)
	{
		curr /= 2;
		val += p[k+1]*curr;
	}

	return pykMemo[i][mam] = val;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> l[i];
	}

	for(int i = 1; i <= n; ++i)
	{ 
		cin >> c[i];
	}

	reverse(l+1, l+1+n);
	reverse(c+1, c+1+n);

	for(int i = 1; i <= n+m; ++i)
	{
		cin >> p[i];
	}

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			dp[i][j] = -inf;
			pykMemo[i][j] = -inf;
		}

		all[i] = -inf;
	}

	dp[0][0] = 0;
	maxi(all[0], dp[0][0]);
	
	int tres = 13;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = l[i]; j >= 0; --j)
		{
			if(l[i] - j < tres)
			{
				for(int mam = N - 1; mam >= 0; --mam)
				{
					int val = dp[j][mam];
					int curr = mam;

					for(int k = j; k < l[i] && curr; ++k)
					{
						curr /= 2;
						val += p[k+1]*curr;
					}

					if(curr+1 < N)
					{
						assert(l[i] - j < tres || !curr);
						maxi(dp[l[i]][curr+1], val-c[i]+p[l[i]]);
						maxi(all[l[i]], dp[l[i]][curr+1] + pyk(l[i], curr+1));
					}
				}
			}
			else
			{
				maxi(dp[l[i]][1], all[j] - c[i] + p[l[i]]);
				maxi(all[l[i]], dp[l[i]][1]);
			}
		}
	}

	int ans = 0;

	for(int i = 0; i < N; ++i)
	{
		for(int mam = 0; mam < N; ++mam)
		{
			maxi(ans, dp[i][mam] + pyk(i, mam));
		}
	}

	cout << ans << endl;
}