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

const int N = 1000000000;
const int M = 200000;

struct Input {
	int n, m;
	int x[M][2], t[M];
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		forn (i, m) {
			char c;
			scanf("%d%d %c", &x[i][0], &x[i][1], &c);
			--x[i][0];
			--x[i][1];
			t[i] = c == 'U';
			debug(mt(x[i][0], x[i][1], t[i]));
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	int ans[M];
	
	void write () {
		forn (i, m) {
			printf("%d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	struct item {
		int val;
		int tol_, tor_;
	};
	
	const static int L = 65;
	
	item items[M * L];
	int items_cnt = 0;
	
	int new_item () {
		items[items_cnt].val = 0;
		items[items_cnt].tol_ = -1;
		items[items_cnt].tor_ = -1;
		return items_cnt++;
	}
	
	int tol (int v) {
		if (items[v].tol_ == -1) {
			items[v].tol_ = new_item();
		}
		return items[v].tol_;
	}
	
	int tor (int v) {
		if (items[v].tor_ == -1) {
			items[v].tor_ = new_item();
		}
		return items[v].tor_;
	}
	
	void upd (int l, int r, int val, int v, int lb, int rb) {
		deepen();
		debug(mt(l, r, val, v, lb, rb));
		if (l <= lb && r >= rb) {
			umx(items[v].val, val);
			return;
		}
		int mid = (lb + rb) >> 1;
		if (l < mid) {
			upd(l, r, val, tol(v), lb, mid);
		}
		if (r > mid) {
			upd(l, r, val, tor(v), mid, rb);
		}
	}
	
	int get (int x, int v, int lb, int rb) {
		if (v == -1) {
			return 0;
		}
		if (rb == lb + 1) {
			return items[v].val;
		}
		int mid = (lb + rb) >> 1;
		return max(items[v].val, x < mid ?
			get(x, items[v].tol_, lb, mid) :
			get(x, items[v].tor_, mid, rb)
		);
	}
	
	int tree[2];
	set<int> u[2];
	
	void solve () {
		tree[0] = new_item();
		tree[1] = new_item();
		forn (i, m) {
			int rb = x[i][t[i]] + 1;
			int lb = u[t[i]].count(x[i][t[i] ^ 1]) ? rb : get(x[i][t[i] ^ 1], tree[t[i] ^ 1], 0, n);
			debug(mt(i, lb, rb));
			u[t[i]].insert(x[i][t[i] ^ 1]);
			if (lb < rb) {
				upd(lb, rb, x[i][t[i] ^ 1] + 1, tree[t[i]], 0, n);
			}
			ans[i] = rb - lb;
		}
	}
	
	void clear () {
		*this = Solution();
	}
};

Solution sol;

int main () {
	deepen(0);
	cout.setf(ios::showpoint | ios::fixed);
	cout.precision(20);
#ifdef SG
	freopen((problemname + ".in").c_str(), "r", stdin);
//	freopen((problemname + ".out").c_str(), "w", stdout);
	while (sol.read()) {
		sol.solve();
		sol.write();
		sol.clear();
		puts("");
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}