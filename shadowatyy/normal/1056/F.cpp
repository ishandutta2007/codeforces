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

const int N = 107;

int n;

double T, C;

int a[N];
int p[N];

double coef[N];

double dp[N][10*N];

void add(int ind)
{
	for(int i = n-1; i >= 0; --i)
	{
		double add = a[ind]*coef[i+1];

		for(int j = 0; j <= 10*i; ++j)
		{
			dp[i+1][j+p[ind]] = min(dp[i+1][j+p[ind]], dp[i][j]+add);
		}
	}
}

inline double calc(double t, double sum, int ile)
{
	return T+T*C*t-t-C*t*t-sum-(1+C*t)*10*ile;
}

bool ok(double sum, int ile)
{
	double l = 0, r = T;

	for(int i = 0; i < 60; ++i)
	{
		double m1 = 2.0/3*l + 1.0/3*r;
		double m2 = 1.0/3*l + 2.0/3*r;

		double c1 = calc(m1, sum, ile);
		double c2 = calc(m2, sum, ile);

		if(c1>0 || c1>0)
			return 1;

		if(c1>c2)
			r = m2;
		else
			l = m1;
	}

	return calc(l, sum, ile)>0;
}

void solve()
{
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < 10*N; ++j)
		{
			dp[i][j] = 1e18;
		}
	}

	dp[0][0] = 0;

	cin >> n >> C >> T;

	VI kol;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> p[i];
		kol.pb(i);
	}

	sort(ALL(kol), [](int p, int q)
	{
		return a[p]>a[q];
	});

	for(auto it:kol)
	{
		add(it);
	}

	int ans = 0;

	for(int i = 0; i <= n; ++i)
	{
		for(int j = 0; j <= 10*i; ++j)
		{
			if(ok(dp[i][j], i))
				ans = max(ans, j);  
		}
	}	

	cout << ans << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	coef[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		coef[i] = 10.0/9*coef[i-1];
	}

	int tc;
	cin >> tc;

	while(tc--)
		solve();
}