#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0, f = 1; char c = getchar();
	while (c > '9' || c < '0') f = c == '-' ? -1 : 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x * f;
}

const int N = 1e6 + 10;
#define pb push_back
vector <int> E[N];
int n, m, deg[N], tot;
bool vis[N];

void dfs(int u) {
	vis[u] = 1;
	for (int i = 0; i < E[u].size(); i ++) {
		int v = E[u][i];
		if (!vis[v]) dfs(v);
	}
}

int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= m; i ++) {
		int u = rd(), v = rd();
		deg[u] ++, deg[v] ++;
		if (u != v) E[u].pb(v), E[v].pb(u);
		else tot ++;
	}
	for (int i = 1; i <= n; i ++) if (E[i].size()) dfs(i), i = n;
	long long ans = 0;
	for (int i = 1; i <= n; i ++) if (!vis[i] && deg[i]) return puts("0"), 0;
	for (int i = 1; i <= n; i ++) ans += 1ll * E[i].size() * (E[i].size() - 1) / 2;;
	ans = ans + 1ll * tot * (m - 1) - 1ll * tot * (tot - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}