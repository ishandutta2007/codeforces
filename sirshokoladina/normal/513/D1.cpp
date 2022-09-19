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

const int N = 1000000;

struct Input {
	int n;
	vi el[N], er[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m)) {
			return 0;
		}
		char buf[100];
		forn (i, m) {
			int x, y;
			scanf("%d%d %s", &x, &y, buf);
			--x;
			--y;
			if (string(buf) == "LEFT") {
				el[x].pb(y);
			} else {
				er[x].pb(y);
			}
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
			puts("IMPOSSIBLE");
			return;
		}
		forn (i, n) {
			if (i) {
				printf(" ");
			}
			printf("%d", ans[i] + 1);
		}
		puts("");
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int mxl[N], mxr[N];
	int q[20][N];
	
	int fnd (int l, int r) {
		if (r <= l) {
			return -1;
		}
		int t = 0;
		while ((1 << (t + 1)) <= r - l) {
			++t;
		}
		return max(q[t][l], q[t][r - (1 << t)]);
	}
	
	bool u[N];
	int l, k;
	
	bool dfs (int mx) {
		deepen();
		debug(mt(l, mx));
		mx = fnd(l, mx + 1);
		int v = l++;
		if (v > mx || u[v]) {
			return 0;
		}
		u[v] = 1;
		debug(mt(v, l, mx));
		
		forn (i, sz(el[v])) {
			if (u[el[v][i]]) {
				return 0;
			}
		}
		if (sz(el[v])) {
			if (!(dfs(mxl[v]))) {
				return 0;
			}
		}
		forn (i, sz(el[v])) {
			if (!u[el[v][i]]) {
				return 0;
			}
		}
		
		ans[k++] = v;
		debug(mx);
		
		forn (i, sz(er[v])) {
			if (u[er[v][i]]) {
				return 0;
			}
		}
		if (mx >= l) {
			if (!(dfs(mx))) {
				return 0;
			}
		}
		forn (i, sz(er[v])) {
			if (!u[er[v][i]]) {
				return 0;
			}
		}
		return 1;
	}
	
	void solve () {
		forn (i, n) {
			mxl[i] = mxr[i] = -1;
			forn (j, sz(el[i])) {
				umx(mxl[i], el[i][j]);
			}
			forn (j, sz(er[i])) {
				umx(mxr[i], er[i][j]);
			}
		}
		memset(q, -1, sizeof q);
		forn (j, n) {
			q[0][j] = max(max(mxl[j], mxr[j]), j);
		}
		forn (i, 19) {
			forn (j, n + 1 - (2 << i)) {
				q[i + 1][j] = max(q[i][j], q[i][j + (1 << i)]);
			}
		}
		debug(q[2], q[2] + 5);
		l = k = 0;
		memset(u, 0, sizeof u);
		res = dfs(n - 1);
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