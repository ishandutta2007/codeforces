#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

// Source: https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Flows%20(12.3)/MCMF.h

using ll = long long;
using db = long double;
using str = string;

using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

template<class T> using V = vector<T>;

#define mp make_pair
#define f first
#define s second

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define eb emplace_back
#define pf push_front
#define rtn return

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)

template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; }

struct MCMF {
	using F = ll; using C = ll; // flow type, cost type
	struct Edge { int to, rev; F flo, cap; C cost; int id; };
	int N, m = 0; V<C> p, dist; vpi pre; V<V<Edge>> adj;
    vector<pair<int, int>> pos;
	void init(int _N) { N = _N;
		p.rsz(N), adj.rsz(N), dist.rsz(N), pre.rsz(N); }
	void ae(int u, int v, F cap, C cost) { assert(cap >= 0);
		adj[u].pb({v,sz(adj[v]),0,cap,cost, m});
		adj[v].pb({u,sz(adj[u])-1,0,0,-cost, m});
        m++;
        pos.emplace_back(u, (int) adj[u].size() - 1);
	} // use asserts, don't try smth dumb
	bool path(int s, int t) { // find lowest cost path to send flow through
		const C inf = numeric_limits<C>::max(); dist.assign(N,inf);
		using T = pair<C,int>; priority_queue<T,vector<T>,greater<T>> todo;
		todo.push({dist[s] = 0,s});
		while (sz(todo)) { // Dijkstra
			T x = todo.top(); todo.pop(); if (x.f > dist[x.s]) continue;
			each(e,adj[x.s]) { // all weights should be non-negative
				if (e.flo < e.cap && ckmin(dist[e.to],x.f+e.cost+p[x.s]-p[e.to]))
					pre[e.to] = {x.s,e.rev}, todo.push({dist[e.to],e.to});
			}
		} // if costs are doubles, add some EPS so you
		// don't traverse ~0-weight cycle repeatedly
		return dist[t] != inf; // return flow
	}
	pair<F,C> calc(int s, int t) { assert(s != t);
		F0R(_,N) F0R(i,N) each(e,adj[i]) // Bellman-Ford
			if (e.cap) ckmin(p[e.to],p[i]+e.cost);
		F totFlow = 0; C totCost = 0;
		while (path(s,t)) { // p -> potentials for Dijkstra
			F0R(i,N) p[i] += dist[i]; // don't matter for unreachable nodes
			F df = numeric_limits<F>::max();
			for (int x = t; x != s; x = pre[x].f) {
				Edge& e = adj[pre[x].f][adj[x][pre[x].s].rev];
				ckmin(df,e.cap-e.flo); }
			totFlow += df; totCost += (p[t]-p[s])*df;
			for (int x = t; x != s; x = pre[x].f) {
				Edge& e = adj[x][pre[x].s]; e.flo -= df;
				adj[pre[x].f][e.rev].flo += df;
			}
		} // get max flow you can send along path
		return {totFlow,totCost};
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> s(n), t(n), c(n), compress;
    for (int i=0; i<n; i++) {
        cin >> s[i] >> t[i] >> c[i];
        t[i] += s[i];
        compress.push_back(s[i]);
        compress.push_back(t[i]);
    }

    sort(compress.begin(), compress.end());
    compress.erase(unique(compress.begin(), compress.end()), compress.end());
    int o = (int) compress.size();
    MCMF mcmf;
    mcmf.init(o + 2);
    for (int i=0; i<n; i++) {
        s[i] = int(lower_bound(compress.begin(), compress.end(), s[i]) - compress.begin());
        t[i] = int(lower_bound(compress.begin(), compress.end(), t[i]) - compress.begin());
        mcmf.ae(s[i], t[i], 1, -c[i]);
    }
    for (int i=1; i<o; i++)
        mcmf.ae(i - 1, i, k, 0);
    mcmf.ae(o, 0, k, 0);
    mcmf.ae(o - 1, o + 1, k, 0);

    mcmf.calc(o, o + 1);
    for (int i=0; i<n; i++) {
        auto p = mcmf.pos[i];
        cout << mcmf.adj[p.first][p.second].flo << " ";
    }
    cout << "\n";

    return 0;
}