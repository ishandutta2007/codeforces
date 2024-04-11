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

#define int ll
const int mod = 1e9+7;
const int N = 1e4+7;

int n, k;

int dp[N][57];
int suf[N][57];

int inv[57];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%mod;

		a = a*a%mod;
		b /= 2;
	}

	return res;
}

void calc(int ile)
{
	for(int i = 0; i < 57; ++i)
	{
		memset(dp, 0, sizeof dp);
		memset(suf, 0, sizeof suf);
	}

	dp[0][ile] = 1;

	for(int l = 0; l < k; ++l)
	{
		for(int a = ile; a >= 0; --a)
		{
			suf[l][a] = suf[l][a+1] + inv[a+1]*dp[l][a]%mod;
			suf[l][a] %= mod;
		}

		for(int a = 0; a <= ile; ++a)
		{
			dp[l+1][a] = suf[l][a];
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < 57; ++i)
	{
		inv[i] = fpow(i, mod-2);
	}

	cin >> n >> k;

	vector<pair<ll, int> > fact;

	for(int i = 2; i*i <= n; ++i)
	{
		while(n%i==0)
		{
			if(fact.empty() || fact.back().st!=i)
				fact.eb(i, 1);
			else
				++fact.back().nd;

			n /= i;
		}
	}

	if(n>1)
	{
		fact.eb(n, 1);
		n /= n;
	}

	int ans = 1;

	for(auto it:fact)
	{
		calc(it.nd);

		int mul = 0;

		for(int i = 0; i <= it.nd; ++i)
		{
			debug(it.nd, i, dp[k][i]);
			mul += fpow(it.st, i)*dp[k][i]%mod;
			mul %= mod;
		}

		ans *= mul;
		ans %= mod;
	}

	cout << ans << endl;
}