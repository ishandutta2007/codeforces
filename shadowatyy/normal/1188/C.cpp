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

const int mod = 998244353;
const int N = 1007;
const int nax = 1e5+7;

int n, k;

int a[N];

int dp[N][N];
int sum[N][N];

int ans[nax];

void solve(int x)
{
	for(int i = 0; i <= k; ++i)
	{
		memset(dp[i], 0, sizeof dp[i]);
		memset(sum[i], 0, sizeof sum[i]);
	}

	for(int i = 1; i <= n; ++i)
	{
		dp[1][i] = 1;
	}

	for(int l = 2; l <= k; ++l)
	{
		for(int i = 1; i <= n; ++i)
		{
			sum[l-1][i] = (dp[l-1][i]+sum[l-1][i-1])%mod;
		}

		int moge = 1;

		for(int i = 1; i <= n; ++i)
		{
			while(moge+1<i && a[i]-a[moge+1]>=x)
				++moge;

			if(moge<i && a[i]-a[moge]>=x)
			{
				dp[l][i] += sum[l-1][moge];
				dp[l][i] %= mod;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		ans[x] += dp[k][i];
		ans[x] %= mod;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	sort(a+1, a+1+n);

	for(int i = 0; i <= (nax-1)/(k-1); ++i)
	{
		solve(i);
	}

	int all = 0, res = 0;

	for(int i = nax-1; i >= 0; --i)
	{
		ans[i] -= all;
		ans[i] %= mod;
		res += (ll)i*ans[i]%mod;
		res %= mod;
		all += ans[i];
		all %= mod;
	}

	res += mod;
	res %= mod;

	cout << res << endl;
}