#include <bits/stdc++.h>
using namespace std;
#define N 100100

typedef long long LL;

int n;
bool vis[N];
LL c[N], f[N], g[N];
vector <int> v[N];

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		dfs(y);
		f[x] = max(f[x], f[y]);
		g[x] = min(g[x], g[y]);
	}
	c[x] += f[x] + g[x];
	if (c[x] < 0) f[x] -= c[x];
	else g[x] -= c[x];
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 1; i <= n; i ++) scanf("%I64d", &c[i]);
	dfs(1);
	printf("%I64d\n", f[1] - g[1]);
	return 0;
}