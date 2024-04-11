#include <bits/stdc++.h>

using namespace std;

int vis[100005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(vis, 0, (n + 5) << 2);
	int a, b, c;
	while (m--) {
		scanf("%d%d%d", &a, &b, &c);
		vis[b] = 1;
	}
	int x = -1;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			x = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (i != x) printf("%d %d\n", x, i);
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