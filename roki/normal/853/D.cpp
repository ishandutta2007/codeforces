#include <bits/stdc++.h>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;

const int N = 300 * 1000 + 5;
int n;
int a[N];

inline bool read() {
	cin >> n;
	forn (i, n)
		scanf("%d", &a[i]);
	return true;
}
   
const int M = 101;

int dp[N][M];

inline void solve() {   
	forn (i, N)
		forn (j, M)
			dp[i][j] = INF;
	dp[0][0] = 0;
	
	forn (i, n) {
		forn (j, M) {
			if (dp[i][j] == INF)
				continue;
			if (j > 0) {
				int dj = a[i] == 1000 ? 10 : 20;
				int addcost = j < dj ? (dj - j) * 100 : 0;
				dj = min(dj, j);
				dp[i + 1][j - dj] = min(dp[i + 1][j - dj], dp[i][j] + addcost);
			}
			int addj = a[i] == 1000 ? 1 : 2;
			if (j + addj < M)
				dp[i + 1][j + addj] = min(dp[i + 1][j + addj], dp[i][j] + a[i]);
		}
	}
	int ans = INF;
	forn (i, M)
		ans = min(ans, dp[n][i]);
	cout << ans << endl;
}

int main()
{
#ifdef _DEBUG
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	read();
	solve();

#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}