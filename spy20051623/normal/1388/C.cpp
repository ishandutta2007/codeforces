#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int s[N], a[N], sz[N];
vector<int> g[N];

bool dfs(int p, int f) {
	sz[p] = 0;
	int sum = 0;
	for (int i: g[p]) {
		if (i == f) continue;
		if (!dfs(i, p)) return false;
		sz[p] += sz[i];
		sum += s[i];
	}
	int v = (sz[p] - sum) / 2 + a[p];
	if (s[p] + a[p] < sum || (s[p] + a[p] - sum & 1) || s[p] + a[p] - sum > v * 2) return false;
	sz[p] += a[p];
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (dfs(1, 0)) cout << "yes\n";
	else cout << "no\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}