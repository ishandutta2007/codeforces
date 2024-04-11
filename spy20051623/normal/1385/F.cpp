#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
vector<int> g[N];
int cnt[N], vis[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) g[i].clear(), cnt[i] = vis[i] = 0;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (k == 1) {
		cout << n - 1 << '\n';
		return;
	}
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (g[i].size() == 1) q.push(i), vis[i] = 1;
	}
	int ans = 0;
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		vis[p] = 1;
		for (int i: g[p]) {
			if (!vis[i]) {
				++cnt[i];
				if (cnt[i] % k == 0) {
					++ans;
					if (cnt[i] == g[i].size() - 1) q.push(i);
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}