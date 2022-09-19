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

const int N = 500000;
const int M = 500000;
const int Q = 500000;

struct Input {
	int n, m;
	int x[N], y[N], z[N];
	int q;
	vi r[Q];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			--x[i];
			--y[i];
		}
		cin >> q;
		forn (i, q) {
			int k;
			scanf("%d", &k);
			r[i].resize(k);
			forn (j, k) {
				scanf("%d", &r[i][j]);
				--r[i][j];
			}
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
		forn (i, q) {
			puts(ans[i] ? "YES" : "NO");
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		map<int, map<int, vi>> g;

		ve<pa<int*, int>> bk;

		int pr[N];
		int rnd = 0;

		int Pr (int v) {
			if (v == pr[v]) {
				return v;
			}
			bk.pb(mp(&pr[v], pr[v]));
			return pr[v] = Pr(pr[v]);
		}

		bool uni (int u, int v) {
			u = Pr(u);
			v = Pr(v);
			if (u == v) {
				return false;
			}
			if (rnd ^= 1) {
				swap(u, v);
			}
			bk.pb(mp(&pr[u], pr[u]));
			pr[u] = v;
			return true;
		}
		
		void solve () {
			forn (i, q) {
				ans[i] = true;
				forn (j, sz(r[i])) {
					g[z[r[i][j]]][i].pb(r[i][j]);
				}
			}
			vi e;
			forn (i, m) {
				e.pb(i);
			}
			sort(all(e), [&] (int i, int j) {
				return z[i] < z[j];
			});
			int i = 0;
			debug(e);
			debug(g);
			forn (i, n) {
				pr[i] = i;
			}
			for (const auto &p : g) {
				deepen();
				debug(p);
				debug(pr, pr + n);
				while (i < sz(e) && z[e[i]] < p.fs) {
					uni(x[e[i]], y[e[i]]);
					++i;
				}
				int state = sz(bk);
				for (const auto &w : p.sc) {
					deepen();
					debug(w);
					debug(pr, pr + n);
					for (int j : w.sc) {
						if (!uni(x[j], y[j])) {
							ans[w.fs] = false;
						}
					}
					debug(pr, pr + n);
					while (sz(bk) > state) {
						*bk.back().fs = bk.back().sc;
						bk.pop_back();
					}
					debug(pr, pr + n);
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