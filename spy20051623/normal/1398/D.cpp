#include <bits/stdc++.h>

using namespace std;

int a[205], b[205], c[205];
long long dp[205][205][205];

long long dfs(int x, int y, int z) {
	if (dp[x][y][z] != -1) return dp[x][y][z];
	if (int(!x) + int(!y) + int(!z) >= 2) return dp[x][y][z] = 0;
	if (x && y) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y - 1, z) + a[x - 1] * b[y - 1]);
	if (y && z) dp[x][y][z] = max(dp[x][y][z], dfs(x, y - 1, z - 1) + b[y - 1] * c[z - 1]);
	if (z && x) dp[x][y][z] = max(dp[x][y][z], dfs(x - 1, y, z - 1) + c[z - 1] * a[x - 1]);
	return dp[x][y][z];
}

void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	for (int i = 0; i < x; ++i) cin >> a[i];
	for (int i = 0; i < y; ++i) cin >> b[i];
	for (int i = 0; i < z; ++i) cin >> c[i];
	memset(dp, -1, sizeof dp);
	sort(a, a + x);
	sort(b, b + y);
	sort(c, c + z);
	cout << dfs(x, y, z) << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}