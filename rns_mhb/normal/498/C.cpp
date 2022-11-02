#include <bits/stdc++.h>
using namespace std;
#define N 36123
#define M 110
#define inf 1000000000
#define pb push_back
int p[N], tot = 0;

void prime() {
	bool vis[N] = {};
	for (int i = 2; i < N; i ++) if (!vis[i]) {
		p[tot++] = i;
		for (int j = i * i; j < N; j += i) vis[j] = 1;
	}
}

int a[M], l[M], r[M];

class dinic_flow {
    public:
    struct edge{
    	int to, rev, cap;
		edge(int to = 0, int rev = 0, int cap = 0) : to(to), rev(rev), cap(cap) {}
    };
    vector < vector <edge> > g;
    vector < vector <edge> :: iterator > nowi;
    vector < int > dist;
    int nodes, src, dst, q[N];
    void init(int _nodes) {
        nodes = _nodes;
        g.resize(_nodes);
        nowi.resize(_nodes);
        for (int i = 0; i < _nodes; i ++) g[i].clear();
        dist.resize(_nodes);
    }
    void add_Edge(int _from, int _to, int _cap) {
        g[_from].push_back( edge(_to, g[_to].size(), _cap) );
        g[_to].push_back( edge(_from, g[_from].size() - 1, 0));
    }
    bool dinic_bfs() {
        fill(dist.begin(), dist.end(), -1);
        int qt = 0;
        dist[src] = 0, q[qt ++] = src;
        for (int qh = 0; qh < qt; qh ++) {
            int u = q[qh];
            for (int i = 0; i < g[u].size(); i ++) {
                edge e = g[u][i];
                if (e.cap) {
                    int v = e.to;
                    if (dist[v] < 0) dist[v] = dist[u] + 1, q[qt ++] = v;
                }
            }
        } return dist[dst] >= 0;
    }
    int dinic_dfs(int u, int f) {
        if (u == dst) return f;
        int ret = 0;
        for (vector<edge>::iterator &it = nowi[u]; it != g[u].end(); it ++) if (it->cap) {
            int v = it->to;
            if (dist[v] == dist[u] + 1) {
                int tmp = dinic_dfs(v, min(f, it->cap) );
                it->cap -= tmp, f -= tmp, ret += tmp, g[v][it->rev].cap +=
                tmp;
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
} D;

int ans = 0;
int n, m;
void func(int q) {
	D.init(n + 3);
	for (int j = 1, t; j <= n; j += 2) {
		t = 0;
		while (a[j] % q == 0) a[j] /= q, t ++;
		D.add_Edge(n + 1, j, t);
	}
	for (int j = 2, t; j <= n; j += 2) {
		t = 0;
		while (a[j] % q == 0) a[j] /= q, t ++;
		D.add_Edge(j, n + 2, t);
	}
	for (int i = 1; i <= m; i ++) D.add_Edge(l[i], r[i], inf);
	ans += D.maxFlow(n + 1, n + 2);
}


int main() {
	prime();
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d", &l[i], &r[i]);
		if (l[i] % 2 == 0) swap(l[i], r[i]);
	}
	for (int i = 0; i < tot; i ++) func(p[i]);
	for (int i = 1; i <= n; i += 2) if (a[i] > 1) func(a[i]);
	cout<<ans;
    return 0;
}