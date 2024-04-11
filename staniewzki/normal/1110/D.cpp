#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, R> a) {cerr << "(" << a.ST << ", " << a.ND << ")";}
template<class T> void db(V<T> v) 
{ cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr << *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

int main()
{
	ios_base::sync_with_stdio(0);
 	cin.tie(0);

	int n, m;
	cin >> n >> m;

	VI v(m);
	REP(i, n)
	{
		int x;
		cin >> x;
		x--;
		v[x]++;
	}

	int dp[m][3][5];
	REP(i, m) REP(x, 3) REP(y, 5)
	{
		if(i == 0 && x != 0) { dp[i][x][y] = -1e9; continue; }
		if(y > v[i]) { dp[i][x][y] = -1e9; continue; }
		if(i != 0 && x > v[i - 1]) { dp[i][x][y] = -1e9; continue; }

		dp[i][x][y] = 0;
		if(i == 0) dp[i][x][y] = (v[i] - y) / 3;
		if(i == 1) dp[i][x][y] = (v[i] - y) / 3 + (v[i - 1] - x) / 3;
		if(i >= 2) dp[i][x][y] = dp[i - 1][0][x] + (v[i] - y) / 3;
		if(i >= 2 && v[i] - y >= 1 && v[i - 1] - x >= 1 && v[i - 2] >= 1)
			dp[i][x][y] = max(dp[i][x][y], 1 + dp[i - 1][1][x + 1] + (v[i] - y - 1) / 3);
		if(i >= 2 && v[i] - y >= 2 && v[i - 1] - x >= 2 && v[i - 2] >= 2)
			dp[i][x][y] = max(dp[i][x][y], 2 + dp[i - 1][2][x + 2] + (v[i] - y - 2) / 3);

		DB(i, x, y, dp[i][x][y]);
	}

	cout << dp[m - 1][0][0] << "\n";
}