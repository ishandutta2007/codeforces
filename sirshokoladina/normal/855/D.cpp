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

const int N = 100000;
const int Q = 100000;

struct Input {
	int n;
	int pr[N], ty[N];
	
	int m;
	int r_x[Q], r_y[Q], r_t[Q];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d", &pr[i], &ty[i]);
			if (pr[i] != -1) {
				--pr[i];
			}
		}
		cin >> m;
		forn (i, m) {
			scanf("%d%d%d", &r_t[i], &r_x[i], &r_y[i]);
			--r_x[i];
			--r_y[i];
			--r_t[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	bool ans[Q];
	
	void write () {
		forn (i, m) {
			puts(ans[i] ? "YES" : "NO");
		}
	}
};


namespace Main {
	const int L = 20;
	
	struct Solution: Data {
		int len[N];
		int p[N][L];
		int q[N][L];
		
		void solve () {
			forn (i, n) {
				p[i][0] = i;
				q[i][0] = i;
				if (ty[i] == 0) {
					len[i] = len[pr[i]] + 1;
					p[i][0] = pr[i];
				} else if (ty[i] == 1) {
					len[i] = len[pr[i]] + 1;
					q[i][0] = pr[i];
				} else {
					len[i] = 0;
				}
				forn (j, L - 1) {
					p[i][j + 1] = p[p[i][j]][j];
					q[i][j + 1] = q[q[i][j]][j];
				}
				debug(mt(len[i], p[i][0], q[i][0]));
			}
			forn (t, m) {
				int x = r_x[t];
				int y = r_y[t];
				if (r_t[t] == 0) {
					swap(x, y);
				}
				debug(mt(t, r_t[t], x, y));
				int lx = 0, ly = 0;
				ford (i, L) {
					if (len[p[x][i]] == len[x] - (1 << i) && len[x] - (1 << i) >= len[y]) {
						x = p[x][i];
						lx += 1 << i;
					}
					if (len[q[y][i]] == len[y] - (1 << i) && len[y] - (1 << i) >= len[x]) {
						y = q[y][i];
						ly += 1 << i;
					}
				}
				ford (i, L) {
					if (len[p[x][i]] == len[x] - (1 << i) && len[q[y][i]] == len[y] - (1 << i) && p[x][i] != q[y][i]) {
						x = p[x][i];
						y = q[y][i];
						lx += 1 << i;
						ly += 1 << i;
					}
				}
				if (x != y) {
					x = p[x][0];
					y = q[y][0];
					lx += 1;
					ly += 1;
				}
				debug(mt(x, y, lx, ly));
				if (r_t[t] == 0) {
					ans[t] = (x == y && lx > 0 && ly == 0);
				}
				if (r_t[t] == 1) {
					ans[t] = (x == y && ly > 0);
				}
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