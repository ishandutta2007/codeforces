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

typedef double ld;
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

const ld pi = acos(ld(-1));

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 400;

struct Input {
	int n;
	vi e[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans;
	
	void write () {
		cout << ans << endl;
	}
};


namespace Main {
	
	struct Solution: Data {
		
		int d[N][N];
		
		ld a[N + 2], cur_a[N + 2];
		ld b[N + 2][N];
		ld c[N][3];
		
		void solve () {
			deepen(0);
			forn (i, n) {
				forn (j, n) {
					d[i][j] = N;
				}
			}
			forn (i, n) {
				d[i][i] = 0;
				forn (j, sz(e[i])) {
					d[i][e[i][j]] = 1;
				}
			}
			forn (i, n) {
				forn (j, n) {
					forn (k, n) {
						umn(d[j][k], d[j][i] + d[i][k]);
					}
				}
			}
			
			ans = 0;
			memset(b, 0, sizeof b);
			forn (i, n) {
				deepen(i == 0);
				debug(i);
				deepen();
				ld cur = 0;
				memset(a, 0, sizeof a);
				forn (j, n) {
					int l1 = d[i][j] + 1;
					cur -= a[l1];
					umx(a[l1], ld(1) / n);
					cur += a[l1];
				}
				debug(a, a + n + 2);
				debug(cur);
			
				memset(c, 0, sizeof c);
				forn (j, n) {
					for (int k : e[j]) {
						c[k][d[i][j] + 1 - d[i][k]] += ld(1) / (n * sz(e[j]));
					}
				}
				forn (j, n) {
					debug(c[j], c[j] + 3);
				}
				
				forn (j, n) {
					memset(cur_a, 0, sizeof cur_a);
					debug(j);
					deepen();
					forn (k, n) {
						forn (t, 3) {
							int l1 = d[i][k] + t;
							int l2 = d[j][k];
							debug(mt(k, t, l1, l2));
							
							cur_a[l1] -= b[l1][l2];
							umx(b[l1][l2], c[k][t]);
							cur_a[l1] += b[l1][l2];
							
							cur -= a[l1];
							umx(a[l1], cur_a[l1]);
							cur += a[l1];
						}
					}
					forn (k, n + 2) {
						debug(b[k], b[k] + n);
					}
					forn (k, n) {
						forn (t, 3) {
							int l1 = d[i][k] + t;
							int l2 = d[j][k];
							b[l1][l2] = 0;
						}
					}
				}
				debug(a, a + n + 2);
				
				debug(mt(i, cur));
				umx(ans, cur);
			}
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
//		freopen("", "r", stdin);
//		freopen("", "w", stdout);
		sol.read();
		sol.solve();
		sol.write();
	#endif
	
	return 0;
}