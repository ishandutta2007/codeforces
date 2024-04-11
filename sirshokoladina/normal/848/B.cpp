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

struct Input {
	int n, sw, sh;

	int g[N], p[N], t[N];
	
	bool read () {
		if (!(cin >> n >> sw >> sh)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d%d", &g[i], &p[i], &t[i]);
			--g[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans_x[N], ans_y[N];

	void write () {
		forn (i, n) {
			printf("%d %d\n", ans_x[i], ans_y[i]);
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		map<int, vi> q;
		
		void solve () {
			forn (i, n) {
				q[p[i] - t[i]].pb(i);
			}
			for (const auto &o : q) {
				auto v = o.sc;
				sort(all(v), [&] (int i, int j) {
					if (g[i] != g[j]) {
						return g[i] == 1;
					}
					if (g[i] == 0) {
						return p[i] < p[j];
					} else {
						return p[i] > p[j];
					}
				});
				auto w = o.sc;
				sort(all(w), [&] (int i, int j) {
					if (g[i] != g[j]) {
						return g[i] == 0;
					}
					if (g[i] == 0) {
						return p[i] < p[j];
					} else {
						return p[i] > p[j];
					}
				});
				debug(mt(v, w));
				forn (i, sz(v)) {
					if (g[w[i]] == 0) {
						ans_x[v[i]] = p[w[i]];
						ans_y[v[i]] = sh;
					} else {
						ans_x[v[i]] = sw;
						ans_y[v[i]] = p[w[i]];
					}
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