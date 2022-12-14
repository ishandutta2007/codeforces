//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 205, M = N * N;
#define prev some

int read() { int x; cin >> x; return x; }

int prev[M], mark[N], head[N], from[M], cap[M], to[M], ec, a[N][N], b[N][N], red[N][N], block[N][N], dis[N][N], cnt, dred[N], seen[N];
pair<int, int> q[N];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void add_edge(int u, int v, int uv, int vu) {
	from[ec] = u, to[ec] = v, cap[ec] = uv, prev[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prev[ec] = head[v], head[v] = ec++;
}

int dfs(int v, int sink, int flow = 2e9) {
	if (v == sink)
		return flow;
	if (mark[v]++)
		return 0;
	for (int e = head[v]; ~e; e = prev[e]) if (cap[e]) {
		int u = to[e];
		int x = dfs(u, sink, min(flow, cap[e]));
		if (x) {
			cap[e] -= x;
			cap[e ^ 1] += x;
			return x;
		}
	}
	return 0;
}

int max_flow(int source, int sink) {
	int res = 0;
	while (true) {
		memset(mark, 0, sizeof mark);
		int add = dfs(source, sink);
		res += add;
		if (!add)
			break;
	}
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), dt = read();
	memset(head, -1, sizeof head);
	memset(dis, 63, sizeof dis);
	rep(i, N)
		dis[i][i] = 0;
	rep(x, n)
		rep(y, n) {
			char foo;
			cin >> foo;
			if (foo == 'Y')
				block[x][y] = 1;
			else if (foo == 'Z')
				red[x][y] = 1;
			else
				a[x][y] = foo - '0';
		}
	rep(x, n)
		rep(y, n) {
			char foo;
			cin >> foo;
			if (foo != 'Y' && foo != 'Z') {
				b[x][y] = foo - '0';
				rep(d, 4) {
					int i = x + dx[d], j = y + dy[d];
					if (i >= 0 && j >= 0 && i < n && j < n && !block[i][j] && !red[i][j]) {
						dis[x * n + y][i * n + j] = 1;
					}
				}
			}
		}
	int m = n * n;
	rep(k, m)
		rep(i, m)
			rep(j, m)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	int h = 0, t = 0;
	memset(dred, 63, sizeof dred);
	rep(i, n)
		rep(j, n)
			if (red[i][j]) {
				q[t++] = {i, j};
				dred[i * n + j] = 0;
			}
	while (h != t) {
		auto cur = q[h++];
		int x = cur.first, y = cur.second;
		rep(d, 4) {
			int i = x + dx[d], j = y + dy[d];
			if (i >= 0 && j >= 0 && i < n && j < n && !block[i][j] && !red[i][j] && dred[i * n + j] > 1e9) {
				dred[i * n + j] = dred[x * n + y] + 1;
				q[t++] = {i, j};
			}
		}
	}
	int sink = N - 1, source = N - 2;
	rep(cur, m) {
		memset(seen, 0, sizeof seen);
		h = 0;
		t = 0;
		int sx = cur / n, sy = cur % n;
		if (block[sx][sy] || red[sx][sy])
			continue;
		q[t++] = {sx, sy};
		seen[cur] = 1;
		while (h != t) {
			int x = q[h].first, y = q[h++].second;
			if (dis[cur][x * n + y] <= dt)
				add_edge(cur << 1, (x * n + y) << 1 | 1, 1000, 0);
			if (dis[cur][x * n + y] == dred[x * n + y])
				continue;
			rep(d, 4) {
				int i = x + dx[d], j = y + dy[d], id = i * n + j;
				if (i >= 0 && j >= 0 && i < n && j < n && !block[i][j] && !red[i][j] && dis[cur][id] <= dred[id] && dis[cur][id] <= dt && dis[cur][id] > dis[cur][x * n + y] && !seen[id]) {
					q[t++] = {i, j};
					seen[id] = 1;
				}
			}
		}
	}
	rep(i, m)
		add_edge(source, i << 1, a[i / n][i % n], 0);
	rep(i, m)
		add_edge(i << 1 | 1, sink, b[i / n][i % n], 0);
	cout << max_flow(source, sink);
}