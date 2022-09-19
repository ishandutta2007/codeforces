#include <bits/stdc++.h>
using namespace std;

#ifdef SG
	#include <debug.h>
#else
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
#define pb push_back
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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 25;
const char *s = "LMW";
const int inf = 500000000;

struct Input {
	int n;
	int a[N], b[N], c[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d%d%d", &a[i], &b[i], &c[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int res;
	int ans[N];
	
	void write () {
		if (res == -inf) {
			puts("Impossible");
			return;
		}
		forn (i, n) {
			forn (j, 3) {
				if (ans[i] != j) {
					printf("%c", s[j]);
				}
			}
			puts("");
		}
		return;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	pa<int, pii> bst;
	
	map<pii, pii> q;
	
	ve<vi> v, w;
	
	vi cur;
	
	void go1 (int k, int msk) {
		if (k == sz(v)) {
			debug(mt(cur[1] - cur[0], cur[2] - cur[0], cur[0], msk));
			umx(q[mp(cur[1] - cur[0], cur[2] - cur[0])], mp(cur[0] + 2 * inf, msk));
			return;
		}
		forn (i, 3) {
			forn (j, 3) {
				if (j != i) {
					cur[j] += v[k][j];
				}
			}
			go1(k + 1, msk + (i << (2 * k)));
			forn (j, 3) {
				if (j != i) {
					cur[j] -= v[k][j];
				}
			}
		}
	}
	
	void go2 (int k, int msk) {
		if (k == sz(w)) {
			debug(mt(cur[1] - cur[0], cur[2] - cur[0], cur[0], msk));
			int val, msk0;
			tie(val, msk0) = q[mp(cur[0] - cur[1], cur[0] - cur[2])];
			umx(bst, mp(val - 2 * inf + cur[0], mp(msk0, msk)));
			return;
		}
		forn (i, 3) {
			forn (j, 3) {
				if (j != i) {
					cur[j] += w[k][j];
				}
			}
			go2(k + 1, msk + (i << (2 * k)));
			forn (j, 3) {
				if (j != i) {
					cur[j] -= w[k][j];
				}
			}
		}
	}
	
	void solve () {
		bst.fs = -inf;
		forn (i, n) {
			if (i < n / 2) {
				v.pb(vi({a[i], b[i], c[i]}));
			} else {
				w.pb(vi({a[i], b[i], c[i]}));
			}
		}
		cur = vi(3, 0);
		debug(v);
		debug(w);
		go1(0, 0);
		debug();
		go2(0, 0);
		debug();
		debug(bst);
		res = bst.fs;
		forn (i, n) {
			if (i < n / 2) {
				ans[i] = (bst.sc.fs >> (2 * i)) & 3;
			} else {
				ans[i] = (bst.sc.sc >> (2 * (i - n / 2))) & 3;
			}
		}
		debug(ans, ans + n);
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
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
	return 0;
}