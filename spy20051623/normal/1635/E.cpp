#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int k[N], x[N], y[N], f[N], in[N], ans[N];
vector<int> g[N], gg[N];

bool dfs(int p, int x) {
	if (f[p] != -1) return f[p] == x;
	f[p] = x;
	for (int i: g[p]) if (!dfs(i, x ^ 1)) return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	fill(f, f + N, -1);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> k[i] >> x[i] >> y[i];
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	for (int i = 1; i <= n; ++i) {
		if (f[i] != -1) continue;
		if (!dfs(i, 0)) {
			cout << "NO\n";
			return 0;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (k[i] == 1) {
			if (!f[x[i]]) gg[y[i]].push_back(x[i]), ++in[x[i]];
			else gg[x[i]].push_back(y[i]), ++in[y[i]];
		} else {
			if (!f[x[i]]) gg[x[i]].push_back(y[i]), ++in[y[i]];
			else gg[y[i]].push_back(x[i]), ++in[x[i]];
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (!in[i]) q.push(i);
	}
	int tot = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		ans[p] = n - tot++;
		for (int i: gg[p]) {
			--in[i];
			if (!in[i]) q.push(i);
		}
	}
	if (tot < n) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << "LR"[f[i]] << ' ' << ans[i] << '\n';
	}
	return 0;
}