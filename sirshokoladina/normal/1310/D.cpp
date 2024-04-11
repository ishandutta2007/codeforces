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

const int N = 80;
const int K = 5;
const int inf = 1000000010;

struct Input {
	int n, k;
	int a[N][N];
	
	bool read() {
		if (!(cin >> n >> k)) {
			return 0;
		}
		k /= 2;
		forn (i, n) {
			forn (j, n) {
				scanf("%d", &a[i][j]);
			}
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
		pii bst[N][N][N + 10];
		int b[K][K];
		bool our[N];

		int d[K + 1][K];

		int calc(vi v) {
			sort(all(v));
			v.erase(unique(all(v)), v.end());
			int m = sz(v);
			if (m == n) {
				return inf;
			}
			memset(our, 0, sizeof our);
			forn (i, m) {
				our[v[i]] = 1;
			}
			forn (i, m) {
				forn (j, m) {
					int x = 0;
					while (our[bst[v[i]][v[j]][x].sc]) {
						++x;
					}
					b[i][j] = bst[v[i]][v[j]][x].fs;
					assert(b[i][j] < inf);
				}
			}
			forn (i, K + 1) {
				forn (j, K) {
					d[i][j] = inf;
				}
			}
			d[0][0] = 0;
			forn (i, k) {
				forn (x, m) {
					forn (y, m) {
						umn(d[i + 1][y], d[i][x] + b[x][y]);
					}
				}
			}
			assert(d[k][0] < inf);
			return d[k][0];
		}
		
		void solve() {
			forn (i, n) {
				forn (j, n) {
					forn (t, N + 10) {
						bst[i][j][t] = mp(inf, -1);
					}
					forn (x, n) {
						if (x == i || x == j) {
							continue;
						}
						bst[i][j][x] = mp(a[i][x] + a[x][j], x);
					}
					sort(bst[i][j], bst[i][j] + N + 10);
				}
			}
			ans = inf;
			forn (i1, n) {
				forn (i2, i1 + 1) {
					forn (i3, i2 + 1) {
						forn (i4, i3 + 1) {
							int val = calc({0, i1, i2, i3, i4});
							umn(ans, val);
						}
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