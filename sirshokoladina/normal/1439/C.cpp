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

const int N = 200000;
const int M = 200000;

struct Input {
	int n, m;
	int a[N];
	int qt[M], qx[M], qy[M];
	
	bool read() {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, m) {
			scanf("%d%d%d", &qt[i], &qx[i], &qy[i]);
			--qt[i];
			if (qt[i] == 1) {
				qx[i]--;
			}
		}
		return 1;
	}

	void init(const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write() {
		forn (i, m) {
			if (qt[i] == 1) {
				printf("%d\n", ans[i]);
			}
		}
	}
};


namespace Main {
	struct Solution: Data {
		int upd[4 * N], mn[4 * N], mx[4 * N];
		ll sum[4 * N];

		void apply(int val, int lb, int rb, int v) {
			upd[v] = val;
			sum[v] = ll(rb - lb) * val;
			mn[v] = val;
			mx[v] = val;
		}

		void push(int lb, int rb, int v) {
			if (upd[v] != -1) {
				apply(upd[v], lb, (lb + rb) / 2, 2 * v + 1);
				apply(upd[v], (lb + rb) / 2, rb, 2 * v + 2);
				upd[v] = -1;
			}
		}

		void update(int r, int val, int lb, int rb, int v) {
			if (r <= lb || mn[v] >= val) {
				return;
			}
			if (rb <= r && mx[v] <= val) {
				apply(val, lb, rb, v);
				return;
			}
			if (rb - lb > 1) {
				push(lb, rb, v);
				update(r, val, lb, (lb + rb) / 2, 2 * v + 1);
				update(r, val, (lb + rb) / 2, rb, 2 * v + 2);
				sum[v] = sum[2 * v + 1] + sum[2 * v + 2];
				mn[v] = min(mn[2 * v + 1], mn[2 * v + 2]);
				mx[v] = max(mx[2 * v + 1], mx[2 * v + 2]);
			}
		}

		int get(int l, ll &val, int lb, int rb, int v) {
			if (rb <= l || mn[v] > val) {
				return 0;
			}
			if (l <= lb && sum[v] <= val) {
				val -= sum[v];
				return rb - lb;
			}
			int res = 0;
			if (rb - lb > 1) {
				push(lb, rb, v);
				res += get(l, val, lb, (lb + rb) / 2, 2 * v + 1);
				res += get(l, val, (lb + rb) / 2, rb, 2 * v + 2);
			}
			return res;
		}
		
		void solve() {
			memset(upd, -1, sizeof upd);
			memset(mn, 0, sizeof mn);
			memset(mx, 0, sizeof mx);
			memset(sum, 0, sizeof sum);
			forn (i, n) {
				update(i + 1, a[i], 0, n, 0);
			}
			forn (i, m) {
				if (qt[i] == 0) {
					update(qx[i], qy[i], 0, n, 0);
				} else {
					ll val = qy[i];
					ans[i] = get(qx[i], val, 0, n, 0);
				}
			}
		}
		
		void clear() {
			*this = Solution();
		}
	};
}


Main::Solution sol;

int main() {
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