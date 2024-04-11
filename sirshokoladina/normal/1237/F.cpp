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

const int N = 3600;

const ll mod = 998244353;

struct Input {
	int n[2];
	int k;
	int x[2][N][2];
	
	bool read() {
		if (!(cin >> n[0] >> n[1] >> k)) {
			return 0;
		}
		forn (i, k) {
			forn (j, 2) {
				forn (t, 2) {
					scanf("%d", &x[t][i][j]);
					--x[t][i][j];
				}
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
		ll f[N + 1];
		ll c[N + 1][N + 1];

		bool u[N];
		ll d[N + 1][N + 1];

		int s[2];
		ll a[2][N + 1];
		
		void solve() {
			forn (i, N + 1) {
				if (i == 0) {
					f[i] = 1;
				} else {
					f[i] = f[i - 1] * i % mod;
				}
			}
			forn (i, N + 1) {
				forn (j, N + 1) {
					if (i == 0 || j == 0) {
						c[i][j] = 1;
					} else {
						c[i][j] = (c[i - 1][j] + c[i][j - 1]) % mod;
					}
				}
			}
			forn (t, 2) {
				memset(u, 0, sizeof u);
				forn (i, k) {
					forn (j, 2) {
						u[x[t][i][j]] = 1;
						s[t]--;
					}
				}
				s[t] = n[t] - accumulate(u, u + n[t], 0);
				debug(s[t]);
				debug(u, u + n[t]);
				memset(d, 0, sizeof d);
				d[0][0] = 1;
				forn (i, n[t]) {
					forn (j, i / 2 + 1) {
						(d[i + 1][j] += d[i][j]) %= mod;
						if (i + 1 < n[t] && !u[i] && !u[i + 1]) {
							(d[i + 2][j + 1] += d[i][j]) %= mod;
						}
					}
				}
				forn (i, N + 1) {
					a[t][i] = d[n[t]][i];
				}
				debug(a[t], a[t] + n[t] / 2 + 1);
			}
			ans = 0;
			forn (i, N + 1) {
				forn (j, N + 1) {
					if (2 * i + j > s[0] || 2 * j + i > s[1]) {
						continue;
					}
					(ans +=
						(a[0][i] * c[s[0] - 2 * i - j][j] % mod) *
						(a[1][j] * c[s[1] - 2 * j - i][i] % mod) % mod *
						f[i] % mod * f[j]
					) %= mod;
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