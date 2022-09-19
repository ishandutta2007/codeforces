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
	int n, q;
	vi e[N];
	int rx[Q], ry[Q];
	
	bool read () {
		int m;
		if (!(cin >> n >> m >> q)) {
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
		forn (i, q) {
			scanf("%d%d", &rx[i], &ry[i]);
			--rx[i];
			--ry[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans[Q];

	void write () {
		forn (i, q) {
			if (ans[i] < -0.5) {
				puts("-1");
			} else {
				printf("%0.20lf\n", double(ans[i]));
			}
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		int k;
		int comp[N];
		ve<ld> val[N];
		ve<ld> sum[N + 1];
		ve<ld> eee[N + 1];
		int ddd[N];

		vi cur;

		void dfs (int v, int pr) {
			cur.pb(v);
			comp[v] = k;
			forn (i, sz(e[v])) {
				if (e[v][i] == pr) {
					continue;
				}
				dfs(e[v][i], v);
			}
		}

		void calclen (int v, int pr, int len, int *curlen) {
			curlen[v] = len;
			forn (i, sz(e[v])) {
				if (e[v][i] == pr) {
					continue;
				}
				calclen(e[v][i], v, len + 1, curlen);
			}
		}

		int fndmx (int *curlen) {
			int res = -1;
			int mx = -1;
			forn (i, sz(cur)) {
				if (umx(mx, curlen[cur[i]])) {
					res = cur[i];
				}
			}
			return res;
		}

		int len1[N], len2[N], len3[N];

		void calc (int rt) {
			cur.clear();
			dfs(rt, -1);
			calclen(rt, -1, 0, len1);
			int v1 = fndmx(len1);
			calclen(v1, -1, 0, len2);
			int v2 = fndmx(len2);
			calclen(v2, -1, 0, len3);

			ddd[k] = len2[v2];
			val[k].resize(ddd[k] + 1);
			forn (i, sz(cur)) {
				val[k][max(len2[cur[i]], len3[cur[i]])] += 1.l / sz(cur);
			}
			sum[k].resize(ddd[k] + 2);
			eee[k].resize(ddd[k] + 2);
			sum[k][0] = 0;
			eee[k][0] = 0;
			forn (i, ddd[k] + 1) {
				sum[k][i + 1] = sum[k][i] + val[k][i];
				eee[k][i + 1] = eee[k][i] + val[k][i] * i;
			}
			debug(mt(k, rt, v1, v2, val[k]));
		}

		map<pii, ld> mem;

		ld fnd (int i, int j) {
			if (mp(ddd[i], i) > mp(ddd[j], j)) {
				swap(i, j);
			}
			if (mem.count(mp(i, j))) {
				return mem[mp(i, j)];
			}
			ld res = 0;

			forn (x, ddd[i] + 1) {
				res += val[i][x] * sum[j][ddd[j] - x] * ddd[j];
				res += val[i][x] * ((sum[j][ddd[j] + 1] - sum[j][ddd[j] - x]) * (x + 1) + (eee[j][ddd[j] + 1] - eee[j][ddd[j] - x]));
			}

			mem[mp(i, j)] = res;
			return res;
		}

		void solve () {
			memset(len1, 0, sizeof len1);
			memset(len2, 0, sizeof len2);
			memset(len3, 0, sizeof len3);
			memset(comp, -1, sizeof comp);
			k = 0;
			forn (i, n) {
				if (comp[i] == -1) {
					calc(i);
					++k;
				}
			}
			forn (i, q) {
				if (comp[rx[i]] == comp[ry[i]]) {
					ans[i] = -1;
				} else {
					ans[i] = fnd(comp[rx[i]], comp[ry[i]]);
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