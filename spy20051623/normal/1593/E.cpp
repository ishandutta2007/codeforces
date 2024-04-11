#include <bits/stdc++.h>

using namespace std;

vector<int> g[400005];
int vis[400005], in[400005];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) g[i].clear();
	memset(vis, 0, (n + 5) << 2);
	memset(in, 0, (n + 5) << 2);
	int x, y;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue<int> q;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		in[i] = g[i].size();
		if (in[i] <= 1) {
			vis[i] = 1;
			++ans;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int p = q.front();
		q.pop();
		if (vis[p] >= k) continue;
		for (int i: g[p]) {
			if (!vis[i]) {
				--in[i];
				if (in[i] == 1) {
					vis[i] = vis[p] + 1;
					++ans;
					q.push(i);
				}
			}
		}
	}
	printf("%d\n", n - ans);
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