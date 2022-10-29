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

int n, q;

inline bool read() {
	cin >> n >> q;
	return true;
}
   
const int N = 1005;
ld dp[2][N];

inline void solve() {   
	dp[0][0] = 1;
	vector<ld> a;
	forn (it, 10000) {
		int cur = it & 1;
		int nt = 1 - cur;
		memset(dp[nt], 0, sizeof dp[nt]);
		forn (i, n + 1) {
			ld p = ld(n - i) / n;
			dp[nt][i + 1] += dp[cur][i] * p;
			dp[nt][i] += dp[cur][i] * (1 - p);
		}
		a.pb(dp[cur][n]);		
	}
	ld eps = 1e-7 - 1e-9;
	forn (i, q) {
		int r;
		cin >> r;
		forn (j, sz(a)) {
			if (a[j] >=  (r - eps) / 2000) {
				cout << j << endl;	
				break;
			}
		}
	}
}

int main()
{
#ifdef SU2
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
	solve();

#ifdef SU2
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}