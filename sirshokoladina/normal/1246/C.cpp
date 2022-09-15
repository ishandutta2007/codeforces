#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
	template<typename T> struct outputer;
	struct outputable {};
	#define PRINT(...)
	#define OUTPUT(...)
	#define show(...)
	#define debug(...)
	#define deepen(...)
	#define timer(...)
	#define fbegin(...)
	#define fend
	#define pbegin(...)
	#define pend
#endif

#define ARG4(_1,_2,_3,_4,...) _4

#define forn3(i,l,r) for (int i = int(l); i < int(r); ++i)
#define forn2(i,n) forn3 (i, 0, n)
#define forn(...) ARG4(__VA_ARGS__, forn3, forn2) (__VA_ARGS__)

#define ford3(i,l,r) for (int i = int(r) - 1; i >= int(l); --i)
#define ford2(i,n) ford3 (i, 0, n)
#define ford(...) ARG4(__VA_ARGS__, ford3, ford2) (__VA_ARGS__)

#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb emplace_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef int64_t ll;
typedef uint64_t ull;
typedef uint32_t ui;
typedef uint16_t us;
typedef uint8_t uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 2000;
const ll mod = 1000000007;

struct Input {
	int n, m;
	bool a[N][N];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		string s;
		getline(cin, s);
		forn (i, n) {
			getline(cin, s);
			forn (j, m) {
				a[i][j] = (s[j] == 'R');
			}
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		int rx[N][N], ry[N][N];
		ll dx[N][N + 1], dy[N + 1][N];
		ll sx[N], sy[N];
		
		void solve() {
			if (n == 1 && m == 1) {
				ans = 1;
				return;
			}
			forn (i, n) {
				int cnt = 0;
				ford (j, m) {
					rx[i][j] = m - cnt;
					cnt += a[i][j];
				}
			}
			forn (j, m) {
				int cnt = 0;
				ford (i, n) {
					ry[i][j] = n - cnt;
					cnt += a[i][j];
				}
			}
			forn (i, n) {
				debug(rx[i], rx[i] + m);
				debug(ry[i], ry[i] + m);
			}
			memset(dx, 0, sizeof dx);
			memset(dy, 0, sizeof dy);
			memset(sx, 0, sizeof sx);
			memset(sy, 0, sizeof sy);
			sx[0] = 1;
			sy[0] = 1;
			forn (i, n) {
				forn (j, m) {
					(sx[i] += dx[i][j]) %= mod;
					(sy[j] += dy[i][j]) %= mod;
					ll curx = sx[i];
					ll cury = sy[j];
					debug(mt(i, j, curx, cury));
					if (i == n - 1 && j == m - 1) {
						ans = (curx + cury) % mod;
					}
					if (i || j) {
						(sx[i] += cury) %= mod;
						(sy[j] += curx) %= mod;
					}
					(dx[i][rx[i][j]] += mod - cury) %= mod;
					(dy[ry[i][j]][j] += mod - curx) %= mod;
				}
			}
		}
		
		void clear() {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main() {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);

	#ifdef SG
		freopen((problemname + ".in").c_str(), "r", stdin);
//		freopen((problemname + ".out").c_str(), "w", stdout);
		while (sol.read()) {
			sol.solve();
			sol.write();
			sol.clear();
		}
	#else
		sol.read();
		sol.solve();
		sol.write();
	#endif
	
	/*
	int t;
	cin >> t;
	forn (i, t) {
		sol.read();
		sol.solve();
		sol.write();
		sol.clear();
	}
	*/
	
	return 0;
}