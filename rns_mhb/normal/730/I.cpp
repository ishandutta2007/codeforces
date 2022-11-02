#include <bits/stdc++.h>
using namespace std;
#define N 3010
#define ll long long
template<class T> void chkmax(T &a, T b) {if (a < b) a = b;}
template<class T> void chkmin(T &a, T b) {if (a > b) a = b;}
const ll INFll = 1e18;
const int INF = 1e9;

class Mincost_Maxflow {

	public:
	struct edge{ int to, rev, cap, cost;
		edge(int to = 0, int rev = 0, int cap = 0, int cost = 0) : to(to) , rev(rev), cap(cap), cost(cost) {}
	};
	vector < vector <edge> > g;
	vector < vector <edge> :: iterator > cur;
	vector < ll > dist;
	vector <bool> vis;
	int nodes, src, dst;
	void init(int _nodes) {
		nodes = _nodes;
		g.resize(_nodes);
		for (int i = 0; i < _nodes; i ++) g[i].clear();
		cur.resize(_nodes);
		dist.resize(_nodes);
		vis.resize(_nodes);
	}
	void add_Edge(int _from, int _to, int _cap, int _cost) {
		g[_from].push_back( edge(_to, g[_to].size(), _cap, -_cost) );
		g[_to].push_back( edge(_from, g[_from].size() - 1, 0, _cost) );
	}
	bool relabel() {
		ll d = INFll;
		for (int u = 0; u < nodes; u ++) if (vis[u]) {
			for (int i = 0; i < g[u].size(); i ++) {
				edge id = g[u][i];
				if (id.cap && !vis[id.to]) chkmin(d, dist[id.to] + id.cost - dist[u]);
			}

		}
		if (d == INFll) return false;
		for (int u = 0; u < nodes; u ++) if (vis[u]) dist[u] += d;
		return true;
	}
	int increase(int u, int f) {
		if (u == dst) return f;
		vis[u] = true;
		int ret = 0;
		for (vector <edge> :: iterator &it = cur[u]; it != g[u].end(); it ++)
		if (it->cap) { int v = it->to;
			if (vis[v] || dist[u] != dist[v] + it->cost) continue;
			int tmp = increase(v, min(f, it->cap));
			it->cap -= tmp, g[v][it->rev].cap += tmp, f -= tmp, ret += tmp;
			if (!f) return ret;
		}
		return ret;
	}
	pair <ll, int> MCMF(int _src, int _dst) {
		src = _src, dst = _dst;
		ll mincost = 0, flow = 0;
		fill(dist.begin(), dist.end(), 0);
		do {
			for (int i = 0; i < nodes; i ++) cur[i] = g[i].begin();
			while (true) {
				fill(vis.begin(), vis.end(), 0);
				int tmp = increase(src, INF); ///INF change
				if (!tmp) break;
				flow += tmp;
				mincost += dist[src] * tmp;
			}
		} while ( relabel() );
		return make_pair(mincost, flow);
	}
} D;

int n, p, s, a, b;

int main() {
	scanf("%d%d%d", &n, &p, &s);
	D.init(n + 5);
	D.add_Edge(0, n + 1, p, 0);
	D.add_Edge(0, n + 2, s, 0);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		D.add_Edge(n + 1, i, 1, a);
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b);
		D.add_Edge(n + 2, i, 1, b);
	}
	for (int i = 1; i <= n; i ++) D.add_Edge(i, n + 3, 1, 0);
	printf("%d\n", -D.MCMF(0, n + 3).first);
	for (int i = 1; i <= n; i ++) if ((D.g[i][0]).cap) printf("%d ", i);
	puts("");
	for (int i = 1; i <= n; i ++) if ((D.g[i][1]).cap) printf("%d ", i);
    return 0;
}