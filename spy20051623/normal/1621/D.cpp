#include <bits/stdc++.h>

using namespace std;
using piii = pair<long long, pair<int, int>>;
long long a[505][505], vis[505][505];
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const long long inf = 1e18;
int n;

long long bfs() {
	priority_queue<piii, vector<piii>, greater<piii>> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if ((i == 1 || i == n) && (j == 1 || j == n)) {
				q.emplace(0, make_pair(i, j));
			}
		}
	}
	for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j) {
			if (i > n || j > n) vis[i][j] = inf;
			else vis[i][j] = 0;
		}
	}
	long long ans = inf;
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		long long s = p.first;
		int x = p.second.first, y = p.second.second;
		for (auto i: d) {
			int xx = x + i[0], yy = y + i[1];
			if (xx < 1) xx = n + n;
			if (xx > n + n) xx = 1;
			if (yy < 1) yy = n + n;
			if (yy > n + n) yy = 1;
			if (xx > n && yy > n) {
				if ((xx == n + 1 || xx == n + n) && (yy == n + 1 || yy == n + n))
					ans = min(ans, s);
			} else if (s + a[xx][yy] < vis[xx][yy]) {
				vis[xx][yy] = s + a[xx][yy];
				q.emplace(vis[xx][yy], make_pair(xx, yy));
			}
		}
	}
	return ans;
}

long long dfs(int x, int y) {
	if (x > n && y > n) return 0;
	long long ans = 1e18;
	for (auto i: d) {
		int xx = x + i[0], yy = y + i[1];
		if (xx < 1) xx = n + n;
		if (xx > n + n) xx = 1;
		if (yy < 1) yy = n + n;
		if (yy > n + n) yy = 1;
		if (vis[xx][yy]) continue;
		vis[xx][yy] = 1;
		ans = min(ans, dfs(xx, yy));
		vis[xx][yy] = 0;
	}
	return ans + a[x][y];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n + n; ++i) {
		for (int j = 1; j <= n + n; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			vis[i][j] = 1;
		}
	}
	long long sum = 0;
	for (int i = n + 1; i <= n + n; ++i) {
		for (int j = n + 1; j <= n + n; ++j) {
			sum += a[i][j];
			a[i][j] = 0;
		}
	}
	long long ans = bfs() + sum;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			ans = min(ans, dfs(i, j));
//		}
//	}
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