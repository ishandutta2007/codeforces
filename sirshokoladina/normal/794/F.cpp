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
	int a[N];
	int rt[Q], rl[Q], rr[Q], rx[Q], ry[Q];
	
	bool read () {
		if (!(cin >> n >> q)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, q) {
			scanf("%d%d%d", &rt[i], &rl[i], &rr[i]);
			--rt[i];
			--rl[i];
			if (rt[i] == 0) {
				scanf("%d%d", &rx[i], &ry[i]);
			}
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
			if (rt[i] == 1) {
				printf("%" PRId64 "\n", ans[i]);
			}
		}
	}
};


namespace Main {
	
	struct Solution: Data {
		ll s[4 * N][10];
		int p[4 * N][10];
		
		void add (int v, int lb, int rb, int pos, int dig, int val) {
			if (rb <= pos || lb > pos) {
				return;
			}
			if (rb - lb == 1) {
				s[v][dig] += val;
				return;
			}
			add(2 * v + 1, lb, (lb + rb) / 2, pos, dig, val);
			add(2 * v + 2, (lb + rb) / 2, rb, pos, dig, val);
			s[v][dig] = s[2 * v + 1][dig] + s[2 * v + 2][dig];
		}
		
		int tmp[10];
		
		void apply (int *p1, int *p2) {
			memcpy(tmp, p1, 10 * sizeof(int));
			forn (i, 10) {
				p1[i] = p2[tmp[i]];
			}
		}
		
		ll tmpll[10];
		
		void apply2 (ll *aa, int *pp) {
			debug(aa, aa + 10);
			debug(pp, pp + 10);
			memcpy(tmpll, aa, 10 * sizeof(ll));
			memset(aa, 0, 10 * sizeof(ll));
			forn (i, 10) {
				aa[pp[i]] += tmpll[i];
			}
			debug(aa, aa + 10);
		}
		
		void push (int v, int lb, int rb) {
			debug(mt(v, lb, rb));
			if (rb - lb > 1) {
				apply(p[2 * v + 1], p[v]);
				apply(p[2 * v + 2], p[v]);
			}
			apply2(s[v], p[v]);
			forn (i, 10) {
				p[v][i] = i;
			}
		}
		
		void upd (int v, int lb, int rb, int l, int r, int x, int y) {
			if (rb <= l || lb >= r) {
				push(v, lb, rb);
				return;
			}
			if (lb >= l && rb <= r) {
				forn (i, 10) {
					if (p[v][i] == x) {
						p[v][i] = y;
					}
				}
				push(v, lb, rb);
				return;
			}
			push(v, lb, rb);
			upd(2 * v + 1, lb, (lb + rb) / 2, l, r, x, y);
			upd(2 * v + 2, (lb + rb) / 2, rb, l, r, x, y);
			forn (i, 10) {
				s[v][i] = s[2 * v + 1][i] + s[2 * v + 2][i];
			}
		}
		
		ll get (int v, int lb, int rb, int l, int r) {
			if (rb <= l || lb >= r) {
				return 0;
			}
			if (lb >= l && rb <= r) {
				push(v, lb, rb);
				ll res = 0;
				forn (i, 10) {
					res += i * s[v][i];
				}
				return res;
			}
			push(v, lb, rb);
			return (
				get(2 * v + 1, lb, (lb + rb) / 2, l, r) + 
				get(2 * v + 2, (lb + rb) / 2, rb, l, r)
			);
		}
		
		void solve () {
			deepen(0);
			forn (i, 4 * N) {
				forn (j, 10) {
					s[i][j] = 0;
					p[i][j] = j;
				}
			}
			forn (i, n) {
				int pw = 1;
				while (a[i]) {
					add(0, 0, n, i, a[i] % 10, pw);
					a[i] /= 10;
					pw *= 10;
				}
			}
			forn (i, q) {
				if (rt[i] == 0) {
					upd(0, 0, n, rl[i], rr[i], rx[i], ry[i]);
				} else {
					ans[i] = get(0, 0, n, rl[i], rr[i]);
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