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

const int N = 200;
const int M = 2000;

struct Input {
	int n, m;
	int x[M], y[M], t[M];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d%d", &x[i], &y[i], &t[i]);
			--x[i];
			--y[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;
	int val[N];

	void write() {
		if (ans == -1) {
			puts("NO");
			return;
		}
		puts("YES");
		cout << ans << endl;
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", val[i]);
			assert(val[i] >= 0);
		}
		puts("");
		forn (i, m) {
			int dif = val[y[i]] - val[x[i]];
			if (t[i] == 1) {
				assert(dif == 1);
			} else {
				assert(abs(dif) == 1);
			}
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int d[N][N];
		
		void solve() {
			ans = -1;
			forn (i, n) {
				forn (j, n) {
					d[i][j] = N;
				}
				d[i][i] = 0;
			}
			forn (i, m) {
				d[x[i]][y[i]] = 1;
				d[y[i]][x[i]] = ((t[i] == 1) ? -1 : 1);
			}
			forn (v, n) {
				forn (i, n) {
					forn (j, n) {
						umn(d[i][j], d[i][v] + d[v][j]);
					}
				}
				forn (i, n) {
					if (d[i][i] < 0) {
						return;
					}
				}
			}
			forn (i, n) {
				debug(d[i], d[i] + n);
			}
			forn (i, m) {
				if (d[0][x[i]] % 2 == d[0][y[i]] % 2) {
					return;
				}
			}
			forn (i, n) {
				forn (j, n) {
					assert((d[0][i] ^ d[0][j] ^ d[i][j]) % 2 == 0);
				}
			}
			forn (v, n) {
				int mn = d[v][0];
				int mx = d[v][0];
				forn (i, n) {
					umn(mn, d[v][i]);
					umx(mx, d[v][i]);
				}
				debug(mt(v, mx, mn));
				if (umx(ans, mx - mn)) {
					forn (i, n) {
						val[i] = d[v][i] - mn;
					}
				}
			}
			assert(ans > -1);
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