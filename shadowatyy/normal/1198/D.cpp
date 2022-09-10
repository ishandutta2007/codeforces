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

#define y1 aanaabababa
const int N = 57;

int n;

int g[N][N];
int pref[N][N];
int dp[N][N][N][N];

bool any(int x1, int x2, int y1, int y2)
{
	return pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1] > 0;
}

void solve(int x1, int x2, int y1, int y2)
{
	if(x1>x2 || y1>y2)
		return;

	if(dp[x1][x2][y1][y2]!=inf)
		return;

	if(!any(x1, x2, y1, y2))
	{
		dp[x1][x2][y1][y2] = 0;
		return;
	}

	dp[x1][x2][y1][y2] = max(x2-x1+1, y2-y1+1);

	for(int i = x1; i < x2; ++i)
	{
		solve(x1, i, y1, y2);
		solve(i+1, x2, y1, y2);
		mini(dp[x1][x2][y1][y2], dp[x1][i][y1][y2]+dp[i+1][x2][y1][y2]);
	}

	for(int i = y1; i < y2; ++i)
	{
		solve(x1, x2, y1, i);
		solve(x1, x2, i+1, y2);
		mini(dp[x1][x2][y1][y2], dp[x1][x2][y1][i]+dp[x1][x2][i+1][y2]);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;

			if(c=='#')
				g[i][j] = 1;
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pref[i][j] = g[i][j];
			pref[i][j] += pref[i-1][j];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			pref[i][j] += pref[i][j-1];
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i; j <= n; ++j)
		{
			for(int k = 1; k <= n; ++k)
			{
				for(int l = k; l <= n; ++l)
				{
					dp[i][j][k][l] = inf;
				}
			}
		}
	}

	solve(1, n, 1, n);
	cout << dp[1][n][1][n] << endl;
}