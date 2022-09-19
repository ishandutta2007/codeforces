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

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 300000;
const int M = 300000;
const int Q = 300000;

struct Input {
	int n, m, q;

	pii e[M];
	pa<int, pii> r[Q];

	bool read () {
		if (!(cin >> n >> m >> q)) {
			return 0;
		}
		forn (i, m) {
			scanf("%d%d", &e[i].fs, &e[i].sc);
			--e[i].fs;
			--e[i].sc;
		}
		forn (i, q) {
			scanf("%d%d", &r[i].fs, &r[i].sc.fs);
			--r[i].fs;
			--r[i].sc.fs;
			if (r[i].fs) {
				scanf("%d", &r[i].sc.sc);
				--r[i].sc.sc;
			} else {
				r[i].sc.sc = -1;
			}
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	vi ans;
	
	void write () {
		forn (i, sz(ans)) {
			printf("%d\n", ans[i]);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	int p[N];
	int d[N];
	
	int P (int v) {
		return p[v] == v ? v : p[v] = P(p[v]);
	}
	
	int rnd = 0;
	
	void uni (int x, int y) {
		x = P(x);
		y = P(y);
		if (x == y) {
			return;
		}
		if (rnd ^= 1) {
			swap(x, y);
		}
		p[x] = y;
		d[y] = max(max(d[x], d[y]), ((d[x] + 1) >> 1) + ((d[y] + 1) >> 1) + 1);
	}
	
	vi adj[N];
	
	bool u[N];

	pii dfs (int v, int pr) {
		u[v] = 1;
		pii res = mp(0, v);
		for (int i: adj[v]) {
			if (i != pr) {
				pii cur = dfs(i, v);
				++cur.fs;
				umx(res, cur);
			}
		}
		return res;
	}
	
	void solve () {
		forn (i, n) {
			p[i] = i;
			d[i] = 0;
		}
		forn (i, m) {
			uni(e[i].fs, e[i].sc);
		}
		forn (i, m) {
			adj[e[i].fs].pb(e[i].sc);
			adj[e[i].sc].pb(e[i].fs);
		}
		memset(u, 0, sizeof u);
		forn (i, n) {
			if (!u[i]) {
				int v = dfs(i, -1).sc;
				d[P(i)] = dfs(v, -1).fs;
			}
		}
		forn (i, q) {
			if (r[i].fs) {
				uni(r[i].sc.fs, r[i].sc.sc);
			} else {
				ans.pb(d[P(r[i].sc.fs)]);
			}
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