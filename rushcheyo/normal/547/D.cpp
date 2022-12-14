#include <bits/stdc++.h>
using namespace std;

const int N = 600005;
int n, x[N], y[N], tot = 1, nxt[2 * N], fst[N];
vector<int> v;
bool vis[N], deg[N];
char col[N];

void dfs(int u) {
	for (int e; e = fst[u];) {
		fst[u] = nxt[e];
		if (!vis[e / 2]) {
			vis[e / 2] = true;
			dfs(x[e / 2] + y[e / 2] - u);
			v.push_back(e / 2);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", x + i, y + i);
		deg[x[i]] ^= 1, deg[y[i] += 200000] ^= 1;
	}
	int m = n, lst = 0;
	for (int i = 1; i <= 200000; ++i)
		if (deg[i]) x[++m] = i, y[m] = 400001, deg[400001] ^= 1;
	for (int i = 200001; i <= 400000; ++i)
		if (deg[i]) x[++m] = i, y[m] = 400002;
	if (deg[400001]) x[++m] = 400001, y[m] = 400002;
	for (int i = 1; i <= m; ++i) {
		nxt[++tot] = fst[x[i]]; fst[x[i]] = tot;
		nxt[++tot] = fst[y[i]]; fst[y[i]] = tot;
	}
	v.reserve(m);
	for (int i = 1; i <= 400000; ++i)
		dfs(i);
	bool now = 0;
	for (int x : v) {
		now ^= 1;
		if (x <= n)
			col[x] = "rb"[now];
	}
	puts(col + 1);
}