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

const ld pi = acos(ld(-1));

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 1000;
const int Q = 1000;
const int M = N * (N - 1) / 2;

struct Input {
	int n, m, q;
	int e_a[M], e_b[M], e_w[M];
	int r_l[Q], r_r[Q];
	
	bool read () {
		if (!(cin >> n >> m >> q)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d%d", &e_a[i], &e_b[i], &e_w[i]);
			--e_a[i];
			--e_b[i];
		}
		forn (i, q) {
			scanf("%d%d", &r_l[i], &r_r[i]);
			--r_l[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[Q];
	
	void write () {
		forn (i, q) {
			printf("%d\n", ans[i]);
		}
	}
};


namespace Main {
	const int K = 22000;
	const int X = 4;
	
	int rnd = 0;
		
	struct DSU {
		pii pr[N];
		bool ok;
		
		void init (int n) {
			forn (i, n) {
				pr[i] = mp(i, 0);
			}
			ok = 1;
		}
		
		pii p (int v) {
			if (pr[v].fs == v) {
				return mp(v, 0);
			}
			pii res = p(pr[v].fs);
			return pr[v] = mp(res.fs, res.sc ^ pr[v].sc);
		}
		
		void uni (int x, int y) {
			pii rx = p(x);
			pii ry = p(y);
			x = rx.fs;
			y = ry.fs;
			int dif = rx.sc ^ ry.sc ^ 1;
			if (x == y) {
				if (dif) {
					ok = 0;
				}
				return;
			}
			if (rnd ^= 1) {
				pr[x] = mp(y, dif);
			} else {
				pr[y] = mp(x, dif);
			}
		}
	};
	
	struct Solution: Data {
		int ord[M];
		int ordpos[M];
				
		int bst[Q];
		DSU dsu[Q];
		
		int bounds[K];
		ve<pii> nums[K];
		
		void solve () {
			forn (i, m) {
				ord[i] = i;
			}
			sort(ord, ord + m, [&] (int i, int j) {
				return e_w[i] < e_w[j];
			});
			forn (i, m) {
				ordpos[ord[i]] = i;
			}
			
			forn (i, K) {
				bounds[i] = m * (i + 1) / (X + 1);
			}
			
			forn (i, q) {
				bst[i] = m;
				dsu[i].init(n);
				int lb = int(lower_bound(bounds, bounds + K , r_l[i]) - bounds);
				nums[min(lb, K - 1)].pb(mp(r_r[i], i));
			}
			
			forn (i, K) {
				sort(all(nums[i]));
			}
			
			forn (x, X) {
				int up = m * (x + 1) / (X + 1);
				forn (i, K) {
					DSU tmp;
					tmp.init(n);
					int curpos = bounds[i];
					for (const auto &p : nums[i]) {
						while (curpos < p.fs) {
							if (ordpos[curpos] >= up) {
								tmp.uni(e_a[curpos], e_b[curpos]);
							}
							++curpos;
						}
						int num = p.sc;
						DSU cur = tmp;
						forn (pos, r_l[num], min(bounds[i], r_r[num])) {
							if (ordpos[pos] >= up) {
								cur.uni(e_a[pos], e_b[pos]);
							}
						}
						if (cur.ok) {
							bst[num] = up;
							dsu[num] = cur;
						}
					}
				}
			}
			
			forn (i, q) {
				while (dsu[i].ok) {
					--bst[i];
					if (bst[i] < 0) {
						break;
					}
					int pos = ord[bst[i]];
					if (pos >= r_l[i] && pos < r_r[i]) {
						dsu[i].uni(e_a[pos], e_b[pos]);
					}
				}
				if (bst[i] == -1) {
					ans[i] = -1;
				} else {
					ans[i] = e_w[ord[bst[i]]];
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
	
	return 0;
}