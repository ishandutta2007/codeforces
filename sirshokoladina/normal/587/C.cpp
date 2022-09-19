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

const int N = 100000;
const int K = 10;

struct Input {
	int n, q;
	vi a[N];
	vi e[N];
	int x[N], y[N], s[N];
	
	bool read () {
		int m;
		if (!(cin >> n >> m >> q)) {
			return 0;
		}
		forn (i, n - 1) {
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].pb(y);
			e[y].pb(x);
		}
		memset(a, 0, sizeof a);
		forn (i, m) {
			int x;
			scanf("%d", &x);
			--x;
			a[x].pb(i);
		}
		forn (i, n) {
			a[i].resize(min(sz(a[i]), K));
		}
		forn (i, q) {
			scanf("%d%d%d", &x[i], &y[i], &s[i]);
			--x[i];
			--y[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans[N];
	
	void write () {
		forn (i, q) {
			printf("%d", sz(ans[i]));
			forn (j, sz(ans[i])) {
				printf(" %d", ans[i][j] + 1);
			}
			puts("");
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	static const int L = 17;
	int p[N][L];
	vi d[N][L];
	int h[N];
	
	vi uni (const vi &a, const vi &b) {
		vi res(sz(a) + sz(b));
		merge(a.begin(), a.end(), b.begin(), b.end(), res.begin());
		res.resize(min(K, sz(res)));
		return res;
	}
	
	void dfs (int v, int pr, int l) {
		h[v] = l;
		p[v][0] = pr;
		d[v][0] = a[v];
		forn (t, L - 1) {
			if (p[v][t] != -1) {
				p[v][t + 1] = p[p[v][t]][t];
				d[v][t + 1] = uni(d[v][t], d[p[v][t]][t]);
			}
		}
		for (int i : e[v]) {
			if (i == pr) {
				continue;
			}
			dfs(i, v, l + 1);
		}
	}
	
	void solve () {
		dfs(0, -1, 0);
		forn (i, q) {
			vi res;
			int u = x[i], v = y[i];
			if (h[u] < h[v]) {
				swap(u, v);
			}
			ford (i, L) {
				if ((h[u] - h[v]) & (1 << i)) {
					res = uni(res, d[u][i]);
					u = p[u][i];
				}
			}
			if (u != v) {
				ford (i, L) {
					if (p[v][i] != p[u][i]) {
						res = uni(res, uni(d[v][i], d[u][i]));
						u = p[u][i];
						v = p[v][i];
					}
				}
				res = uni(res, uni(a[u], a[v]));
				u = p[u][0];
				v = p[v][0];
			}
			res = uni(res, a[u]);
			ans[i] = res;
			ans[i].resize(min(s[i], sz(ans[i])));
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