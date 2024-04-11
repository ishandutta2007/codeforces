#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[510][510];
vector <int> all[2];

int dfs(int x, int y) {
	if (x == n && y == 0) return 0;
	if (~dp[x][y]) return dp[x][y];
	int &res = dp[x][y] = 0x3f3f3f3f;
	for (int i = 0; i <= x; i++) {
		int j = k - i;
		if (j < 0 || j > y) continue;
		res = min(res, dfs(x - i + j, y + i - j) + 1);
	}
	return res;
}

int rec(int x, int y) {
	if (x == n && y == 0) return 0;
	for (int i = 0; i <= x; i++) {
		int j = k - i;
		if (j < 0 || j > y) continue;
		if (dfs(x, y) == dfs(x - i + j, y + i - j) + 1) {
			cout << "?";
			vector <int> t[2];
			for (int _ = 0; _ < i; _++) t[0].push_back(all[0].back()), all[0].pop_back(), cout << " " << t[0].back();
			for (int _ = 0; _ < j; _++) t[1].push_back(all[1].back()), all[1].pop_back(), cout << " " << t[1].back();
			cout << endl;
			int sum; cin >> sum;
			for (auto x : t[0]) all[1].push_back(x);
			for (auto x : t[1]) all[0].push_back(x);
			return sum ^ rec(x - i + j, y + i - j);
		}
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	if (dfs(0, n) == 0x3f3f3f3f) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) all[1].push_back(i);
	int ans = rec(0, n);
	cout << "! " << ans << endl;
	return 0;
}