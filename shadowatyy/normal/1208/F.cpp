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

#define int ll
const int N = 21;

int n, ans;

int a[1<<N];

int dp[1<<N][2];

void wrzuc(int v, int i)
{
	if(i>dp[v][0])
	{
		dp[v][1] = dp[v][0];
		dp[v][0] = i;
	}
	else if(i>dp[v][1])
		dp[v][1] = i;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < 1<<N; ++i)
	{
		dp[i][0] = dp[i][1] = -inf;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		wrzuc(a[i], i);
	}

	for(int b = 0; b < N; ++b)
	{
		for(int i = 0; i < 1<<N; ++i)
		{
			if(!(i&(1<<b)))
			{
				wrzuc(i, dp[i|(1<<b)][0]);
				wrzuc(i, dp[i|(1<<b)][1]);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		int add = 0;

		for(int b = N-1; b >= 0; --b)
		{
			if(a[i]&(1<<b))
				continue;

			if(dp[add|(1<<b)][1]>i)
				add |= (1<<b);
		}

		if(dp[add][1]>i)
			ans = max(ans, a[i]|add);
	}

	cout << ans << endl;
}