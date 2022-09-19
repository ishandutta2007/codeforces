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


#ifdef SG
	const int N = 3000;
	const int Q = 3000;
#else
	const int N = 300000;
	const int Q = 300000;
#endif

struct Input {
	int n;
	vi e[N];
	int q;
	int lq[Q], rq[Q];
	
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
		cin >> q;
		forn (i, q) {
			scanf("%d%d", &lq[i], &rq[i]);
			--lq[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ll ans[Q];

	void write () {
		forn (i, q) {
			printf("%" PRId64 "\n", ans[i]);
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int u[N];
		ve<pii> bad;

		vi w;

		void dfs (int v, int pr) {
			if (u[v] == 2) {
				return;
			}
			if (u[v] == 1) {
				int mn = v, mx = v;
				ford (i, sz(w)) {
					if (w[i] == v) {
						break;
					}
					umn(mn, w[i]);
					umx(mx, w[i]);
				}
				bad.pb(mp(mn, mx + 1));
				return;
			}
			u[v] = 1;
			w.pb(v);
			for (int to : e[v]) {
				if (to == pr) {
					continue;
				}
				dfs(to, v);
			}
			w.pop_back();
			u[v] = 2;
		}

		int m;
		ll t[4 * N];
		int uuu[4 * N];

		void push (int v, int lb, int rb) {
			if (uuu[v] == -1) {
				return;
			}
			t[v] = uuu[v] * 1ll * (rb - lb);
			if (rb - lb > 1) {
				uuu[2 * v + 1] = uuu[v];
				uuu[2 * v + 2] = uuu[v];
			}
			uuu[v] = -1;
		}

		void upd (int l, int r, int val, int v, int lb, int rb) {
			push(v, lb, rb);
			if (l >= rb || r <= lb) {
				return;
			}
			if (l <= lb && r >= rb) {
				uuu[v] = val;
				push(v, lb, rb);
				return;
			}
			int md = (lb + rb) / 2;
			upd(l, r, val, 2 * v + 1, lb, md);
			upd(l, r, val, 2 * v + 2, md, rb);
			t[v] = t[2 * v + 1] + t[2 * v + 2];
		}

		ll get (int l, int r, int v, int lb, int rb) {
			push(v, lb, rb);
			if (l >= rb || r <= lb) {
				return 0;
			}
			if (l <= lb && r >= rb) {
				return t[v];
			}
			int md = (lb + rb) / 2;
			return get(l, r, 2 * v + 1, lb, md) + get(l, r, 2 * v + 2, md, rb);
		}

		vi bad_r[N];
		ve<pii> req[N];
		
		void solve () {
			memset(u, 0, sizeof u);
			forn (i, n) {
				if (!u[i]) {
					dfs(i, -1);
				}
			}
			debug(bad);
			memset(t, 0, sizeof t);
			memset(uuu, -1, sizeof uuu);
			m = 1;
			while (m < n + 1) {
				m *= 2;
			}
			forn (i, q) {
				req[lq[i]].pb(mp(rq[i], i));
			}
			for (const auto &p : bad) {
				bad_r[p.fs].pb(p.sc);
			}
			int curb = m;
			ford (lb, n) {
				for (int rb : bad_r[lb]) {
					debug(mt(lb, rb));
					upd(min(curb, rb), curb, lb + 1, 0, 0, m);
					umn(curb, rb);
				}
				debug(t, t + 2 * m - 1);
				debug(uuu, uuu + 2 * m - 1);
				for (const auto &p : req[lb]) {
					int rb = p.fs;
					int i = p.sc;
					debug(mt(lb, rb, i));
					int cnt = max(0, rb + 1 - curb);
					ll sum = get(0, rb + 1, 0, 0, m);
					ll del = sum - cnt * 1ll * lb;
					int len = rb - lb;
					ll tot = len * 1ll * (len + 1) / 2;
					debug(mt(cnt, sum, tot, del));
					ans[i] = tot - del;
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