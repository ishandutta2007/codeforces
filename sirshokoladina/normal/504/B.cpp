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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200000;

struct Input {
	int n;
	int a[N], b[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &a[i]);
		}
		forn (i, n) {
			scanf("%d", &b[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[N];
	
	void write () {
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i]);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int M = 2 * N;
	
	struct tree {
		int sz;
		int lb[2 * M], rb[2 * M], val[2 * M];
		
		void init (int n) {
			memset(val, 0, sizeof val);
			sz = 1;
			while (sz < n) {
				sz *= 2;
			}
			forn (i, sz) {
				lb[sz + i] = i;
				rb[sz + i] = i + 1;
				val[sz + i] = 1;
			}
			ford (i, 1, sz) {
				lb[i] = lb[2 * i];
				rb[i] = rb[2 * i + 1];
				val[i] = val[2 * i] + val[2 * i + 1];
			}
		}
		
		void upd (int v, int x) {
			v += sz;
			val[v] = x;
			while (v != 1) {
				v >>= 1;
				val[v] = val[2 * v] + val[2 * v + 1];
			}
		}
		
		int get (int l, int r, int v = 1) {
			if (rb[v] <= l || lb[v] >= r) {
				return 0;
			}
			if (lb[v] >= l && rb[v] <= r) {
				return val[v];
			}
			return get(l, r, 2 * v) + get(l, r, 2 * v + 1);
		}
	} ta, tb, tans;
	
	int posa[N], posb[N], posans[N];
	
	void solve () {
		ta.init(n);
		forn (i, n) {
			posa[i] = ta.get(0, a[i]);
			ta.upd(a[i], 0);
		}
		tb.init(n);
		forn (i, n) {
			posb[i] = tb.get(0, b[i]);
			tb.upd(b[i], 0);
		}
		forn (i, n) {
			posans[i] = posa[i] + posb[i];
		}
		ford (i, n) {
			if (i) {
				posans[i - 1] += posans[i] / (n - i);
			}
			posans[i] %= n - i;
		}
		debug(posa, posa + n);
		debug(posb, posb + n);
		debug(posans, posans + n);
		tans.init(n);
		forn (i, n) {
			int l = 0, r = n - 1;
			while (l < r) {
				int m = (l + r + 1) >> 1;
				if (tans.get(0, m) > posans[i]) {
					r = m - 1;
				} else {
					l = m;
				}
			}
			ans[i] = l;
			tans.upd(ans[i], 0);
		}
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
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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