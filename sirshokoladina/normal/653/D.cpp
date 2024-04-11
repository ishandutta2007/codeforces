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

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

typedef int flow;

const int N = 50;
const int M = 500;
const int K = 100000;
const int X = 1000000;
const flow INF = K;

struct Input {
	int n, m, k;
	int ex[M], ey[M], c[M];
	
	bool read () {
		if (!(cin >> n >> m >> k)) {
			return 0;
		}
		forn (i, m) {
			cin >> ex[i] >> ey[i] >> c[i];
			--ex[i];
			--ey[i];
		}
		return 1;
	}

	void init (const Input &input) {
		*this = input;
	}
};

struct Data: Input {
	ld ans;
	
	void write () {
		cout << ans << endl;
	}
	
	virtual void solve () {}
	
	virtual void clear () {
		*this = Data();
	}
};

struct Solution: Data {
	struct edge {
		int to;
		flow b, f;
		
		edge (int to_ = -1, flow b_ = 0): to(to_), b(b_), f(0) {}
		
		flow r () {
			return b - f;
		}
	};
	
	int es;
	edge e[2 * M];
	
	void push (int num, flow d) {
		e[num].f += d;
		e[num ^ 1].f -= d;
	}
	
	vi adj[N];
	
	void add_edge (int x, int y, flow b) {
		e[es] = edge(y, b);
		adj[x].pb(es);
		++es;
		e[es] = edge(x, 0);
		adj[y].pb(es);
		++es;
	}

	int st, fn;
	
	int l[N];
	
	bool bfs () {
		memset(l, -1, sizeof l);
		vi q(1, st);
		l[st] = 0;
		forn (i, sz(q)) {
			int v = q[i];
			for (auto j: adj[v]) {
				int to = e[j].to;
				if (l[to] == -1 && e[j].r()) {
					q.pb(to);
					l[to] = l[v] + 1;
				}
			}
		}
		return l[fn] != -1;
	}

	int done[N];

	flow dfs (int v, flow r) {
		if (v == fn) {
			return r;
		}
		for (; done[v] < sz(adj[v]); ++done[v]) {
			int i = adj[v][done[v]];
			int to = e[i].to;
			if (l[to] != l[v] + 1 || !e[i].r()) {
				continue;
			}
			flow d = dfs(to, min(r, e[i].r()));
			if (d) {
				push(i, d);
				return d;
			}
		}
		return 0;
	}
	
	flow dinic () {
		flow res = 0;
		while (1) {
			if (!bfs()) {
				break;
			}
			memset(done, 0, sizeof done);
			while (flow d = dfs(st, INF)) {
				res += d;
			}
		}
		return res;
	}
	
	void solve () {
		deepen(0);
		ld lb = 1 / K, rb = X;
		forn (ttt, 100) {
			ld md = (lb + rb) / 2;
			forn (i, n) {
				adj[i].clear();
			}
			es = 0;
			debug(md);
			forn (i, m) {
				add_edge(ex[i], ey[i], min<ld>(floorl(c[i] / md), ld(INF)));
				debug(mt(ex[i], ey[i], min<ld>(floorl(c[i] / md), ld(INF))));
			}
			st = 0;
			fn = n - 1;
			flow res = dinic();
			debug(res);
			if (res < k) {
				rb = md;
			} else {
				lb = md;
			}
		}
		ans = (lb + rb) / 2 * k;
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
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	sol.read();
	sol.solve();
	sol.write();
#endif
	return 0;
}