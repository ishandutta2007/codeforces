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

const int N = 500;

struct Input {
	ll mod;
	int n, m;
	
	bool read() {
		return !!(cin >> n >> m >> mod);
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

		ll pw(ll x, ll y) {
			ll res = 1;
			while (y) {
				if (y & 1) {
					res = res * x % mod;
				}
				x = x * x % mod;
				y >>= 1;
			}
			return res;
		}

		ll inv(ll x) {
			return pw(x, mod - 2);
		}

		ll ss(int x) {
			return x * (x + 1) / 2;
		}

		ll c[N + 1][N + 1];

		// cnt, sum
		pll a[N + 1];
		pll d[N + 2][N + 1];
		
		void solve() {
			forn (i, n + 1) {
				forn (j, n + 1) {
					if (!i || !j) {
						c[i][j] = 1;
						continue;
					}
					c[i][j] = (c[i - 1][j] + c[i][j - 1]) % mod;
				}
			}

			memset(a, 0, sizeof a);
			a[0] = pll(1, 0);
			forn (i, 1, m + 1) {
				forn (j, i) {
					pll cur;
					cur.fs = a[j].fs * a[i - 1 - j].fs % mod;
					cur.sc = (a[j].sc * a[i - 1 - j].fs + a[j].fs * a[i - 1 - j].sc) % mod;
					cur.sc = (cur.sc * (i + 1) + (ss(j) + ss(i - 1 - j)) * cur.fs) % mod;
					cur.fs = cur.fs * (i + 1) % mod;
					cur.fs = cur.fs * c[j][i - 1 - j] % mod;
					cur.sc = cur.sc * c[j][i - 1 - j] % mod;
					a[i].fs = (a[i].fs + cur.fs) % mod;
					a[i].sc = (a[i].sc + cur.sc) % mod;
				}
			}

			debug(a, a + m + 1);

			memset(d, 0, sizeof d);
			d[0][0] = pll(1, 0);
			forn (i, n + 2) {
				forn (j, m + 1) {
					forn (k, min(n - i, m - j) + 1) {
						pll cur;
						cur.fs = a[k].fs * d[i][j].fs % mod;
						cur.sc = (a[k].sc * d[i][j].fs + a[k].fs * d[i][j].sc) % mod;
						cur.fs = cur.fs * c[j][k] % mod;
						cur.sc = cur.sc * c[j][k] % mod;
						d[i + k + 1][j + k].fs = (d[i + k + 1][j + k].fs + cur.fs) % mod;
						d[i + k + 1][j + k].sc = (d[i + k + 1][j + k].sc + cur.sc) % mod;
					}
				}
				debug(d[i], d[i] + m + 1);
			}
			ans = d[n + 1][m].sc;
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