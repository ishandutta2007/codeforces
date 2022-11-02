#include <bits/stdc++.h>
using namespace std;

namespace netflow {
	struct edge{ int to, rev, cap; };
	vector < vector <edge> > g;
	vector < vector <edge> :: iterator > nowi;
	vector < int > dist;
	int nodes, src, dst, q[100010];

	void init(int _nodes) {
		nodes = _nodes;
		g.resize(_nodes);
		nowi.resize(_nodes);
		for (int i = 0; i < _nodes; i ++) g[i].clear();
		dist.resize(_nodes);
	}

	int add_Edge(int _from, int _to, int _cap) {
		g[_from].push_back( {_to, g[_to].size(), _cap} );
		g[_to].push_back( {_from, g[_from].size() - 1, 0} );
		return g[_from].size() - 1;
	}

	bool dinic_bfs() {
		fill(dist.begin(), dist.end(), -1);
		int qt = 0;
		dist[src] = 0, q[qt ++] = src;
		for (int qh = 0; qh < qt; qh ++) { int u = q[qh];
			for (auto &e : g[u]) if (e.cap) { auto v = e.to;
				if (dist[v] < 0) dist[v] = dist[u] + 1, q[qt ++] = v;
			}
		} return dist[dst] >= 0;
	}

	int dinic_dfs(int u, int f) {
		if (u == dst) return f;
		int ret = 0;
		for (auto &it = nowi[u]; it != g[u].end(); it ++) if (it->cap) { auto v = it->to;
			if (dist[v] == dist[u] + 1) {
				int tmp = dinic_dfs(v, min(f, it->cap) );
				it->cap -= tmp, f -= tmp, ret += tmp, g[v][it->rev].cap += tmp;
				if (!f) return ret;
			}
		} return ret;
	}

	int maxFlow(int _src, int _dst) {
		src = _src, dst = _dst;
		int flow = 0;
		while (dinic_bfs()) {
			for (int i = 0; i < nodes; i ++) nowi[i] = g[i].begin();
			flow += dinic_dfs(_src, 1e9);
		} return flow;
	}
}

#define N 100010

int n, m, x[N], y[N], xx[N], yy[N];

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", x + i, y + i);
	}

	int st = 0, en = m;
	while (st < en - 1) {
		int mid = (st + en) >> 1;
		netflow::init(n + m + 10);
		int src = n + m + 1, dst = n + m + 2;
		for (int i = 1; i <= n; i ++) {
			netflow::add_Edge(src, i, mid);
		}
		for (int i = 1; i <= m; i ++) {
			netflow::add_Edge(x[i], i + n, 1);
			netflow::add_Edge(y[i], i + n, 1);
			netflow::add_Edge(i + n, dst, 1);
		}
		if (netflow::maxFlow(src, dst) == m) en = mid;
		else st = mid;
	}

	cout << en << endl;

	netflow::init(n + m + 10);
	int src = n + m + 1, dst = n + m + 2;

	for (int i = 1; i <= n; i ++) {
		netflow::add_Edge(src, i, en);
	}

	for (int i = 1; i <= m; i ++) {
		xx[i] = netflow::add_Edge(x[i], i + n, 1);
		yy[i] = netflow::add_Edge(y[i], i + n, 1);
		netflow::add_Edge(i + n, dst, 1);
	}
	 netflow::maxFlow(src, dst);

	for (int i = 1; i <= m; i ++) {
		if (netflow::g[x[i]][xx[i]].cap == 0) printf("%d %d\n", x[i], y[i]);
		else printf("%d %d\n", y[i], x[i]);
	}

}