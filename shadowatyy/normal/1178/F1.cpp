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
const int N = 507;

int n, m;

int tab[N];
int dp[N][N][3];
int vis[N][N][3];
int pie[N];
int dru[N];

void solve(int a, int b, int t)
{
	if(vis[a][b][t])
		return;

	vis[a][b][t] = 1;

	if(a>b)
	{
		if(t==2)
			dp[a][b][t] = 1;
		else
			dp[a][b][t] = 0;

		return;
	}

	int col = inf;
	int ind = -1;

	if(t==2)
	{
		for(int i = a; i <= b; ++i)
		{
			if(col>tab[i])
			{
				col = tab[i];
				ind = i;
			}
		}

		solve(a, ind, 1);
		solve(ind, b, 0);
		dp[a][b][t] = (ll)dp[a][ind][1]*dp[ind][b][0]%mod;
	}
	else if(t==0)
	{
		for(int i = a; i <= b; ++i)
		{
			solve(a+1, i, 2);
			solve(i+1, b, 2);
			dp[a][b][t] += (ll)dp[a+1][i][2]*dp[i+1][b][2]%mod;
			
			if(dp[a][b][t]>=mod)
				dp[a][b][t] -= mod;
		}
	}
	else if(t==1)
	{
		for(int i = a; i <= b; ++i)
		{
			solve(a, i-1, 2);
			solve(i, b-1, 2);
			dp[a][b][t] += (ll)dp[a][i-1][2]*dp[i][b-1][2]%mod;

			if(dp[a][b][t]>=mod)
				dp[a][b][t] -= mod;
		}
	}

	//debug(a, b, " ", t, " ", dp[a][b][t]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> tab[i];
	}

	solve(1, n, 2);
	cout << dp[1][n][2] << endl;
}