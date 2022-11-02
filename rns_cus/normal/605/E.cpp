#include <bits/stdc++.h>
using namespace std;
typedef double db;

#define N 1010
db rem[N], sum[N], p[N];
const db inf = 1e9;
bitset <N> vis;
int a[N][N], n;

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) scanf("%d", a[i] + j);
	}

	for (int i = 1; i < n; i ++) {
		rem[i] = sum[i] = 1;
		p[i] = inf;
	}

	for (int i = 1; i <= n; i ++) {
		int id = 0; db mn = inf;
		for (int u = 1; u <= n; u ++) if (!vis[u]) {
			if (mn > p[u]) { mn = p[u], id = u; }
		}
		vis[id] = true;
		for (int u = 1; u <= n; u ++) if (!vis[u]) {
			sum[u] += p[id] * rem[u] * a[u][id] / 100.;
			rem[u] = rem[u] * (1 - a[u][id] / 100.);
			p[u] = sum[u] / (1 - rem[u]);
		}
	}

	printf("%.6lf\n", p[1]);
}