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

const int N = 200;

struct Input {
	int n;
	int val[N];
	
	bool read () {
		if (!(cin >> n)) {
			return 0;
		}
		forn (i, n) {
			scanf("%d", &val[i]);
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ve<vi> ans;
	
	void write () {
		if (!sz(ans)) {
			puts("Impossible");
			return;
		}
		cout << sz(ans) << endl;
		forn (i, sz(ans)) {
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
	static const int V = N + 2;
	static const int E = 21000;
	
	struct edge {
		int to;
		int a, f;
		
		edge () {}
		edge (int to_, int a_): to(to_), a(a_), f(0) {}
		
		int r () {
			return a - f;
		}
	};
	
	int v, e;
	edge ed[2 * E];
	vi a[V];
	
	void push (int i, int f) {
		ed[i].f += f;
		ed[i ^ 1].f -= f;
	}
	
	void add_edge (int s, int t, int f) {
		ed[2 * e] = edge(t, f);
		ed[2 * e + 1] = edge(s, 0);
		a[s].pb(2 * e);
		a[t].pb(2 * e + 1);
		++e;
	}
	
	int st, fn;
	
	bool u[V];
	
	bool go (int v) {
		if (u[v]) {
			return 0;
		}
		if (v == fn) {
			return 1;
		}
		u[v] = 1;
		forn (i, sz(a[v])) {
			int num = a[v][i];
			if (ed[num].r() && go(ed[num].to)) {
				push(num, 1);
				return 1;
			}
		}
		return 0;
	}
	
	bool isp (int n) {
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				return 0;
			}
		}
		return 1;
	}
	
	void solve () {
		deepen(0);
		v = n + 2;
		e = 0;
		st = n;
		fn = n + 1;
		forn (i, n) {
			if (val[i] & 1) {
				add_edge(st, i, 2);
				forn (j, n) {
					if (isp(val[i] + val[j])) {
						//debug(mp(i, j));
						add_edge(i, j, 1);
					}
				}
			} else {
				add_edge(i, fn, 2);
			}
		}
		forn (i, n) {
			memset(u, 0, sizeof u);
			if (!go(st)) {
				return;
			}
		}
		forn (i, e) {
			debug(mt(ed[2 * i + 1].to, ed[2 * i].to, ed[2 * i].a, ed[2 * i].f));
		}
		memset(u, 0, sizeof u);
		forn (i, n) {
			if (!u[i]) {
				vi q;
				int j = i;
				while (!u[j]) {
					u[j] = 1;
					q.pb(j);
					forn (k, sz(a[j])) {
						int num = a[j][k];
						int to = ed[num].to;
						if (ed[num].f && to < n && !u[to]) {
							j = to;
							break;
						}
					}
				}
				ans.pb(q);
			}
		}
	}
	
	bool check () {
		forn (i, sz(ans)) {
			forn (j, sz(ans[i])) {
				if (!isp(val[ans[i][j]] + val[ans[i][(j + 1) % sz(ans[i])]])) {
					return 0;
				}
			}
		}
		return 1;
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
		assert(sol.check());
		sol.clear();
	}
#else
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}