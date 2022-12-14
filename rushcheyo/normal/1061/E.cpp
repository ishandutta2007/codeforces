#include <bits/stdc++.h>
using namespace std;

const int N = 505, INF = 0x3f3f3f3f;
int n, rt[2], q[2], fa[2][N], w[N], sum[2][N], a[2][N], b[2][N], cons[2][N];
vector<int> e[2][N];

void dfs(int id, int u) {
	for (int v : e[id][u])
		if (v != fa[id][u]) {
			fa[id][v] = u;
			dfs(id, v);
		}
}

namespace flow {
	const int V = 2 * N, E = 6 * N;
	int S, T, tot = 1, nxt[E], fst[V], to[E], flow[E], cost[E], dis[V], pre[V];
	void addedge(int u, int v, int w, int c) {
		nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; flow[tot] = w; cost[tot] = c;
		nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; flow[tot] = 0; cost[tot] = -c;
	}
	bool bfs() {
		queue<int> q;
		static bool inq[V];
		for (int i = 1; i <= T; i++) dis[i] = -INF;
		q.push(S), inq[S] = true, dis[S] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop(); inq[u] = false;
			for (int i = fst[u]; i; i = nxt[i])
				if (flow[i] > 0 && dis[to[i]] < dis[u] + cost[i]) {
					dis[to[i]] = dis[u] + cost[i];
					pre[to[i]] = i;
					if (!inq[to[i]]) q.push(to[i]), inq[to[i]] = true;
				}
		}
		return dis[T] != -INF;
	}
	pair<int, int> mcmf() {
		int f = 0, c = 0;
		while (bfs()) {
			int mn = INF;
			for (int i = T; i != S; i = to[pre[i] ^ 1]) mn = min(mn, flow[pre[i]]);
			f += mn, c += mn * dis[T];
			for (int i = T; i != S; i = to[pre[i] ^ 1]) flow[pre[i]] -= mn, flow[pre[i] ^ 1] += mn;
		}
		return make_pair(f, c);
	}
}

int main() {
	scanf("%d%d%d", &n, rt, rt + 1);
	for (int i = 1; i <= n; i++) scanf("%d", w + i);
	for (int id = 0; id < 2; id++) {
		for (int i = 1, u, v; i < n; i++) {
			scanf("%d%d", &u, &v);
			e[id][u].push_back(v), e[id][v].push_back(u);
		}
		dfs(id, rt[id]);
	}
	for (int id = 0; id < 2; id++) {
		scanf("%d", q + id);
		for (int i = 1; i <= q[id]; i++) {
			scanf("%d%d", a[id] + i, b[id] + i);
			cons[id][a[id][i]] = i;
		}
	}
	if (b[0][cons[0][rt[0]]] != b[1][cons[1][rt[1]]])
		return puts("-1"), 0;
	for (int i = 1; i <= n; i++) {
		int x = i;
		while (!cons[0][x]) x = fa[0][x];
		int y = i;
		while (!cons[1][y]) y = fa[1][y];
		flow::addedge(cons[0][x], q[0] + cons[1][y], 1, w[i]);
	}
	flow::S = q[0] + q[1] + 1, flow::T = q[0] + q[1] + 2;
	for (int id = 0; id < 2; id++)
		for (int i = 1; i <= q[id]; i++)
			if (a[id][i] != rt[id]) {
				int x = fa[id][a[id][i]];
				while (!cons[id][x]) x = fa[id][x];
				sum[id][cons[id][x]] += b[id][i];
			}
	for (int i = 1; i <= q[0]; i++) {
		if (sum[0][i] > b[0][i]) return puts("-1"), 0;
		flow::addedge(flow::S, i, b[0][i] - sum[0][i], 0);
	}
	for (int i = 1; i <= q[1]; i++) {
		if (sum[1][i] > b[1][i]) return puts("-1"), 0;
		flow::addedge(q[0] + i, flow::T, b[1][i] - sum[1][i], 0);
	}
	pair<int, int> ret = flow::mcmf();
	if (ret.first != b[0][cons[0][rt[0]]])
		puts("-1");
	else
		printf("%d\n", ret.second);
	return 0;
}