#include <bits/stdc++.h>
using namespace std;

const int V = 105, E = 2 * 5 * V, inf = 0x3f3f3f3f;
int n, m, S, T, tot = 1, nxt[E], fst[V], to[E], f[E], cost[E], d[V], pre[V], ans;

void addedge(int u, int v, int w, int c) {
	nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v; f[tot] = w; cost[tot] = c;
	nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u; f[tot] = 0; cost[tot] = -c;
}

bool spfa() {
	queue<int> q;
	static bool inq[V];
	q.push(S);
	inq[S] = true;
	for (int i = 1; i <= T; i++) d[i] = inf;
	d[S] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop(); inq[u] = false;
		for (int i = fst[u]; i; i = nxt[i])
			if (f[i] > 0 && d[to[i]] > d[u] + cost[i]) {
				d[to[i]] = d[u] + cost[i];
				pre[to[i]] = i;
				if (!inq[to[i]]) {
					q.push(to[i]);
					inq[to[i]] = true;
				}
			}
	}
	return d[T] != inf;
}

void aug() {
	int fl = inf, c = 0;
	for (int u = T; u != S; u = to[pre[u] ^ 1]) fl = min(fl, f[pre[u]]), c += cost[pre[u]];
	for (int u = T; u != S; u = to[pre[u] ^ 1]) f[pre[u]] -= fl, f[pre[u] ^ 1] += fl;
	ans += fl * c;
}

int main() {
	cin >> n >> m;
	S = n + 1, T = n + 2;
	for (int i = 1; i <= m; ++i) {
		int u, v, c, f;
		cin >> u >> v >> c >> f;
		addedge(S, v, f, 0);
		addedge(u, T, f, 0);
		if (c >= f) {
			addedge(v, u, f, 1);
			addedge(u, v, c - f, 1);
			addedge(u, v, inf, 2);
		} else {
			ans += f - c;
			addedge(v, u, f - c, 0);
			addedge(v, u, c, 1);
			addedge(u, v, inf, 2);
		}
	}
	addedge(n, 1, inf, 0);
	while (spfa()) aug();
	cout << ans << '\n';
	return 0;
}