#pragma GCC target("popcnt,tune=native")
#include <bits/stdc++.h>
using namespace std;

int n, m, dis[155];
struct edge {
	int a, b, d;
} e[155];
vector<int> g[155];
bool operator<(const edge &a, const edge &b) {
	return a.d < b.d;
}
struct matrix {
	bitset<155> bs[155];
} T, G;
matrix operator*(const matrix &a, const matrix &b) {
	matrix tb;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			tb.bs[i][j] = b.bs[j][i];
	matrix c;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			c.bs[i][j] = (a.bs[i] & tb.bs[j]).any();
	return c;
}
matrix power(matrix a, int x) {
	matrix ans;
	for (int i = 1; i <= n; ++i)
		ans.bs[i].reset(), ans.bs[i].set(i);
	for (; x; x >>= 1, a = a * a)
		if (x & 1) ans = ans * a;
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].d);
	sort(e + 1, e + 1 + m);
	for (int i = 1; i <= m; ++i)
		g[e[i].a].push_back(i);
	for (int i = 1; i <= n; ++i)
		T.bs[i].set(i);
	int ans = 1 << 30;
	for (int i = 1; i <= m; ++i) {
		T = T * power(G, e[i].d - e[i - 1].d);
		G.bs[e[i].a].set(e[i].b);
		queue<int> q;
		for (int j = 1; j <= n; ++j)
			if (T.bs[1][j]) dis[j] = 0, q.push(j);
			else dis[j] = -1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int t : g[u])
				if (t <= i && dis[e[t].b] == -1)
					dis[e[t].b] = dis[u] + 1, q.push(e[t].b);
		}
		if (dis[n] != -1)
			ans = min(ans, e[i].d + dis[n]);
	}
	if (ans == 1 << 30) puts("Impossible");
	else printf("%d\n", ans);
	return 0;
}