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

const int N = 300000;
const int M = 300000;

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
	bool res;
	int ans[N];
	
	void write () {
		if (!res) {
			puts("NO");
			return;
		}
		puts("YES");
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		puts("");
	}
};


namespace Main {
	const int X = 10000000;
	
	struct Solution: Data {
		set<pii> s;
		
		bool check () {
			forn (i, n) {
				if (ans[i] == -1) {
					return 0;
				}
			}
			for (const pii &p : s) {
				if (abs(ans[p.fs] - ans[p.sc]) > 1) {
					return 0;
				}
			}
			
			ve<pii> v;
			forn (i, n) {
				v.pb(mp(ans[i], i));
			}
			sort(all(v));
			int j = 0;
			forn (i, n) {
				while (j < n && abs(v[j].fs - v[i].fs) <= 1) {
					++j;
				}
				forn (t, i + 1, j) {
					if (v[i].sc != v[t].sc && !s.count(mp(v[i].sc, v[t].sc))) {
						return 0;
					}
				}
			}
			return 1;
		}
		
		void rec (int v1, int v2, int x1, int x2) {
			int x3 = 2 * x2 - x1;
			set<int> s3;
			forn (i, sz(e[v2])) {
				if (v1 != e[v2][i] && !s.count(mp(v1, e[v2][i]))) {
					if (ans[e[v2][i]] != -1) {
						return;
					}
					ans[e[v2][i]] = x3;
					s3.insert(e[v2][i]);
				}
			}
			debug(mt(v1, v2, s3));
			if (sz(s3)) {
				rec(v2, *s3.begin(), x2, x3);
			}
		}
		
		void make (int v1, int v2, int v3) {
			debug(mt(v1, v2, v3));
			memset(ans, -1, sizeof ans);
			set<int> s1, s2, s3;
			s2.insert(v2);
			ans[v2] = X;
			forn (i, sz(e[v2])) {
				if (v1 != e[v2][i] && !s.count(mp(v1, e[v2][i]))) {
					ans[e[v2][i]] = X + 1;
					s3.insert(e[v2][i]);
				} else if (v3 != e[v2][i] && !s.count(mp(v3, e[v2][i]))) {
					ans[e[v2][i]] = X - 1;
					s1.insert(e[v2][i]);
				} else {
					ans[e[v2][i]] = X;
					s2.insert(e[v2][i]);
				}
			}
			debug(mt(s1, s2, s3));
			rec(v2, v1, X, X - 1);
			rec(v2, v3, X, X + 1);
			res = check();
		}
		
		void solve () {
			forn (i, n) {
				forn (j, sz(e[i])) {
					s.insert(mp(i, e[i][j]));
				}
			}
			
			forn (i, sz(e[0])) {
				forn (j, sz(e[e[0][i]])) {
					if (e[e[0][i]][j] != 0 && !s.count(mp(0, e[e[0][i]][j]))) {
						make(0, e[0][i], e[e[0][i]][j]);
						return;
					}
				}
			}
			
			assert(sz(e[0]) == n - 1);
			
			forn (i, n) {
				forn (j, i) {
					if (i != j && !s.count(mp(i, j))) {
						make(i, 0, j);
						return;
					}
				}
			}
			
			forn (i, n) {
				ans[i] = X;
			}
			res = check();
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