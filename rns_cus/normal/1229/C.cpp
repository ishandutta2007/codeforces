#include <bits/stdc++.h>
using namespace std;

#define N 100010

typedef long long ll;

int n, m;
vector <int> adj[N];
int in[N], out[N], deg[N];

int main() {
	scanf("%d %d", &n, &m);
	while (m --) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (u > v) swap(u, v);
		adj[u].push_back(v);
		deg[u] ++, deg[v] ++;
	}
	for (int i = 1; i <= n; i ++) out[i] = adj[i].size(), in[i] = deg[i] - out[i];
	ll ans = 0;
	for (int i = 1; i <= n; i ++) ans += 1ll * in[i] * out[i];
	printf("%I64d\n", ans);
	int q;
	scanf("%d", &q);
	while (q --) {
		int u;
		scanf("%d", &u);
		ans -= 1ll * in[u] * out[u];
		out[u] = 0, in[u] = deg[u];
		for (auto v : adj[u]) {
			ans += in[v] - out[v] - 1;
			out[v] ++, in[v] --;
			adj[v].push_back(u);
		}
		adj[u].clear();
		printf("%I64d\n", ans);
	}
}