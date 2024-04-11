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

const int N = 100000;
const int M = 200000;

struct Input {
	int n, m;
	ve<array<int, 2> > e;
	
	bool read () {
		if (!(cin >> n >> m)) {
			return 0;
		}
		e.resize(m);
		forn (i, m) {
			scanf("%d%d", &e[i][0], &e[i][1]);
			--e[i][0];
			--e[i][1];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<pii> ans;
	
	void write () {
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
			printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);
		}
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	ve<pii> a[N];
	int k[N];
	ve<bool> u;
	vi q;
	
	void dfs (int v) {
		while (k[v] < sz(a[v])) {
			auto p = a[v][k[v]++];
			if (u[p.fs]) {
				continue;
			}
			u[p.fs] = 1;
			dfs(e[p.fs][p.sc]);
		}
		q.pb(v);
	}
	
	void solve () {
		forn (i, m) {
			forn (j, 2) {
				a[e[i][j]].pb(mp(i, 1 - j));
			}
		}
		vi t;
		forn (i, n) {
			if (sz(a[i]) & 1) {
				t.pb(i);
			}
		}
		forn (i, sz(t) / 2) {
			e.pb({t[2 * i], t[2 * i + 1]});
		}
		if (sz(e) & 1) {
			e.pb({0, 0});
		}
		forn (i, m, sz(e)) {
			forn (j, 2) {
				a[e[i][j]].pb(mp(i, 1 - j));
			}
		}
		memset(k, 0, sizeof k);
		u = ve<bool>(sz(e), 0);
		dfs(0);
		debug(q);
		forn (i, sz(q) - 1) {
			if (i & 1) {
				ans.pb(mp(q[i], q[i + 1]));
			} else {
				ans.pb(mp(q[i + 1], q[i]));
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