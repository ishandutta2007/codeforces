#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

#define N 666

int n, m, d[N][N], cur[N];
const int inf = 1e9;
vector <pii> que[N];
vector <pii> adj[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) d[i][j] = inf;
    while (m --) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		d[u][v] = d[v][u] = w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
    }
    for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++)
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	int q;
	scanf("%d", &q);
	while (q --) {
		int u, v, l;
		scanf("%d %d %d", &u, &v, &l);
		que[u].emplace_back(v, l);
		que[v].emplace_back(u, l);
	}
	int ans = 0;
	for (int u = 1; u <= n; u ++) {
		for (int i = 1; i <= n; i ++) cur[i] = -inf;
		for (int i = 1; i <= n; i ++) {
			int x = d[u][i];
			for (auto p : que[i]) {
				int v = p.first;
				cur[v] = max(cur[v], p.second - x);
			}
		}
		for (auto p : adj[u]) {
			int v = p.first;
			bool good = false;
			for (int i = 1; i <= n; i ++) if (p.second + d[v][i] <= cur[i]) good = true;
			if (good) ans ++;
		}
	}
	printf("%d\n", ans >> 1);

    return 0;
}