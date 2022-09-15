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

const int N = 600;
const int M = N * N / 2;
const int Q = N * N / 2;

const ll inf = ll(1e18);

struct Input {
	int n, m, q;
	int ex[M], ey[M];
	ll ew[M];
	int qx[Q], qy[Q];
	ll qw[Q];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d%" SCNd64, &ex[i], &ey[i], &ew[i]);
			--ex[i];
			--ey[i];
		}
		cin >> q;
		forn (i, q) {
			scanf("%d%d%" SCNd64, &qx[i], &qy[i], &qw[i]);
			--qx[i];
			--qy[i];
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans;

	void write() {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		ll d[N][N];
		ll mx[N];
		
		void solve() {
			forn (i, n) {
				forn (j, n) {
					d[i][j] = inf;
				}
			}
			forn (i, n) {
				d[i][i] = 0;
			}
			forn (i, m) {
				umn(d[ex[i]][ey[i]], ew[i]);
				umn(d[ey[i]][ex[i]], ew[i]);
			}
			forn (k, n) {
				forn (i, n) {
					forn (j, n) {
						umn(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			forn (i, n) {
				debug(d[i], d[i] + n);
			}
			ans = 0;
			forn (v, n) {
				forn (i, n) {
					mx[i] = -inf;
				}
				forn (i, q) {
					int x = qx[i];
					int y = qy[i];
					forn (t, 2) {
						umx(mx[y], qw[i] - d[x][v]);
						swap(x, y);
					}
				}
				debug(v);
				debug(mx, mx + n);
				forn (i, m) {
					if (ex[i] == v) {
						bool good = 0;
						forn (j, n) {
							good |= (ew[i] + d[ey[i]][j] <= mx[j]);
						}
						ans += good;
					}
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