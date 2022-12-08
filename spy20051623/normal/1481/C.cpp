#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];
int c[100005];
int d[100005];
vector<int> e[100005];
int f[100005];
int g[100005];
int n, m;

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &c[i]);
	}
	memset(d, 0, sizeof d);
	memset(g, 0, sizeof g);
	for (int i = 1; i <= n; ++i) {
		if (a[i] != b[i])
			e[b[i]].push_back(i);
		g[b[i]] = i;
	}
	bool ok = false;
	int k;
	memset(f, 0, sizeof f);
	for (int i = m - 1; i >= 0; --i) {
		if (d[c[i]] < e[c[i]].size()) {
			k = f[i] = e[c[i]][d[c[i]]++];
			ok = true;
		} else if (ok) {
			f[i] = k;
		} else if (g[c[i]]) {
			k = f[i] = g[c[i]];
			ok = true;
		} else {
			printf("NO\n");
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (d[i] < e[i].size()) {
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	for (int i = 0; i < m; ++i) {
		printf("%d ", f[i]);
	}
	printf("\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
		}
	}
	return 0;
}