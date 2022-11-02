#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, d[N];
vector <int> v[N];
bool vis[N];

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		if (!vis[v[x][i]]) d[v[x][i]] = d[x] + 1, dfs(v[x][i]);
	}
}

int main() {
//	freopen("i.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i ++) if (vis[i]) {
		for (int j = 0; j < v[i].size(); j ++) ans = __gcd(ans, abs(d[i] + 1 - d[v[i][j]]));
	}
	if (!ans) ans = n;
	printf("%d\n", ans);
	int cnt = 0;
	for (int i = 1; i <= n; i ++) if (vis[i] && d[i] % ans == 0) cnt ++;
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i ++) if (vis[i] && d[i] % ans == 0) printf("%d ", i);
	puts("");
	return 0;
}