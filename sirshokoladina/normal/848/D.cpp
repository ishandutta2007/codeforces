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

const int N = 50;
const ll mod = 1000000007;

struct Input {
	int n, m;
	
	bool read () {
		return !!(cin >> n >> m);
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans;

	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		ll d[N + 1][N + 1], nd[N + 1][N + 1];
		ll p[N + 1][N + 1];

		ll pw (ll a, ll k) {
			ll res = 1;
			while (k) {
				if (k & 1) {
					(res *= a) %= mod;
				}
				(a *= a) %= mod;
				k >>= 1;
			}
			return res;
		}
		
		void solve () {
			memset(d, 0, sizeof d);
			memset(p, 0, sizeof p);
			d[0][0] = 1;
			forn (i, 1, N + 1) {
				forn (j, 1, i + 1) {
					forn (x, i) {
						forn (y, j - 1, x + 1) {
							(p[i][j] += d[x][y] * d[i - 1 - x][j - 1] * (2 - (y == j - 1))) %= mod;
						}
					}
					memcpy(nd, d, sizeof d);
					ll c = 1;
					forn (k, 1, N / i + 1) {
						(c *= (p[i][j] + k - 1) * pw(k, mod - 2) % mod) %= mod;
						ford (x, N - i * k + 1) {
							ford (y, x + 1) {
								(nd[x + k * i][y + k * j] += d[x][y] * c) %= mod;
							}
						}
					}
					memcpy(d, nd, sizeof d);
				}
			}

			ans = d[n][m - 1];
		}
		
		void clear () {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main () {
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