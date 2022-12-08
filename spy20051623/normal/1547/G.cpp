#include <bits/stdc++.h>

using namespace std;

vector<int> g1[400005], g2[400005];
bool vis[400005];
stack<int> s;
bool f[400005];
int ans[400005];

void add(int x, int y) {
	g1[x].push_back(y);
	g2[y].push_back(x);
}

void dfs1(int p) {
	if (vis[p])return;
	vis[p] = true;
	for (int i:g2[p]) {
		dfs1(i);
	}
	s.push(p);
}

bool dfs2(int p, int x) {
	if (!vis[p])return false;
	vis[p] = false;
	bool res = false;
	for (int i:g1[p]) {
		if (i == x)res = true;
		else if (vis[i])res |= dfs2(i, x);
	}
	f[p] = res;
	return res;
}

void dfs3(int p, int x) {
	if (f[p])x = -1;
	ans[p] = x;
	for (int i:g1[p]) {
		if (ans[i] == -1)continue;
		if (ans[i] == 2 && x == -1)dfs3(i, -1);
		if (ans[i] == 1 && (x == -1 || x == 2))dfs3(i, x);
		if (ans[i] == 1 && x == 1)dfs3(i, 2);
		if (ans[i] == 0)dfs3(i, x);
	}
}

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; ++i) {
		dfs1(i);
	}
	memset(f, 0, sizeof f);
	while (!s.empty()) {
		dfs2(s.top(), s.top());
		s.pop();
	}
	memset(ans, 0, sizeof ans);
	dfs3(1, 1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		g1[i].clear();
		g2[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}