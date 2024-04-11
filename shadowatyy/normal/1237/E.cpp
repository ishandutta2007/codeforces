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

/*const int N = 10007;

int n;

int dp[N][2];

int ok(int l, int r)
{
	if(abs(l-r)<=1)
		return 1;

	for(int i = 1; i < inf; i = 2*i+1)
	{
		if(i<=min(l, r) && max(l, r)<=2*i+1)
			return 1;
	}

	return 0;
}*/

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	int x = 1;
	int minus = 0;

	while(x<inf)
	{
		if(x==n || x+1==n)
		{
			cout << 1 << endl;
			exit(0);
		}

		x = 2*(x+1);

		if(minus)
			x--;

		minus ^= 1;
	}

	cout << 0 << endl;

	/*cin >> n;

	dp[0][0] = dp[0][1] = 1;
	dp[1][1] = 1;

	for(int i = 2; i <= n; ++i)
	{
		for(int l = 0; l <= i-1; ++l)
		{
			int r = i-1-l;

			if(ok(l, r))
			{
				//debug(i, l, r);
				dp[i][0] += dp[l][1]*dp[r][0];
				dp[i][1] += dp[l][0]*dp[r][0]; 
			}
		}

		if(dp[i][0]+dp[i][1])
			cout << i << endl;
	}*/
}