#include <bits/stdc++.h>

using namespace std;

int vis[205];
vector<pair<int, int>> v;

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	memset(vis, 0, sizeof vis);
	int m = n - k;
	v.clear();
	for (int i = 0; i < k; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.emplace_back(x, y);
		vis[x] = vis[y] = 1;
	}
	int s = 0;
	for (int i = 1; i <= n + n; ++i) {
		if (s >= m)break;
		if (!vis[i]) {
			int j = i;
			for (int l = 0; l < m; ++l) {
				j = j % (n + n) + 1;
				while (vis[j])j = j % (n + n) + 1;
			}
			v.emplace_back(i, j);
			++s;
		}
	}
	int ans = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			int cnt = 0;
			int x = v[i].first, y = v[i].second;
			while (x != y) {
				x = x % (n + n) + 1;
				if (x == v[j].first || x == v[j].second)++cnt;
			}
			if (cnt == 1)++ans;
		}
	}
	printf("%d\n", ans);
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