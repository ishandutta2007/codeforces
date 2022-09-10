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

#define int ll
const int N = 107;
const int mod = 998244353;

int n, m, s, sl, sd;

int w[N];
int l[N];

int dp[N][N][N]; //ujemne

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

int dziel(int a, int b)
{
	a %= mod;
	b %= mod;
	return a*fpow(b, mod-2)%mod;
}

void clear()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			memset(dp[i][j], 0, sizeof dp[i][j]);
		}
	}
}

void dislikes(int ind)
{
	clear();

	dp[0][0][0] = 1;

	for(int i = 0; i < m; ++i)
	{
		for(int ja = 0; ja <= i; ++ja)
		{
			for(int plus = 0; plus <= i; ++plus)
			{
				if(dp[i][ja][plus]==0)
					continue;

				int curr_ja = w[ind]-ja;
				int curr_l = sl+plus;
				int curr_d = sd-(i-plus);
				int curr_s = curr_l+curr_d;

				//trafia we mnie
				dp[i+1][ja+1][plus] += dziel(dp[i][ja][plus]*curr_ja, curr_s);
				dp[i+1][ja+1][plus] %= mod;

				//trafia w dislikes ale nie we mnie
				dp[i+1][ja][plus] += dziel(dp[i][ja][plus]*(curr_d-curr_ja), curr_s);
				dp[i+1][ja][plus] %= mod;

				//trafia w likes
				dp[i+1][ja][plus+1] += dziel(dp[i][ja][plus]*curr_l, curr_s);
				dp[i+1][ja][plus+1] %= mod;
			}
		}
	}

	int ans = w[ind];
	int kek = 0;

	for(int ja = 0; ja <= m; ++ja)
	{
		for(int plus = 0; plus <= m; ++plus)
		{
			ans -= dp[m][ja][plus]*ja%mod;
			ans %= mod;

			kek += dp[m][ja][plus];
			kek %= mod;
		}
	}

	kek += mod;
	kek %= mod;
	assert(kek==1);

	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << endl;
}

void likes(int ind)
{
	clear();

	dp[0][0][0] = 1;

	for(int i = 0; i < m; ++i)
	{
		for(int ja = 0; ja <= i; ++ja)
		{
			for(int plus = 0; plus <= i; ++plus)
			{
				if(dp[i][ja][plus]==0)
					continue;

				int curr_ja = w[ind]+ja;
				int curr_l = sl+plus;
				int curr_d = sd-(i-plus);
				int curr_s = curr_l+curr_d;

				//trafia we mnie
				dp[i+1][ja+1][plus+1] += dziel(dp[i][ja][plus]*curr_ja, curr_s);
				dp[i+1][ja+1][plus+1] %= mod;

				//trafia w likes ale nie we mnie
				dp[i+1][ja][plus+1] += dziel(dp[i][ja][plus]*(curr_l-curr_ja), curr_s);
				dp[i+1][ja][plus+1] %= mod;

				//trafia w dis
				dp[i+1][ja][plus] += dziel(dp[i][ja][plus]*curr_d, curr_s);
				dp[i+1][ja][plus] %= mod;
			}
		}
	}

	int ans = w[ind];
	int kek = 0;

	for(int ja = 0; ja <= m; ++ja)
	{
		for(int plus = 0; plus <= m; ++plus)
		{
			ans += dp[m][ja][plus]*ja%mod;
			ans %= mod;

			kek += dp[m][ja][plus];
			kek %= mod;
		}
	}

	kek += mod;
	kek %= mod;
	assert(kek==1);

	ans %= mod;
	ans += mod;
	ans %= mod;
	cout << ans << endl;
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
		cin >> w[i];

		if(l[i])
			sl += w[i];
		else
			sd += w[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(l[i])
			likes(i);
		else
			dislikes(i);
	}
}