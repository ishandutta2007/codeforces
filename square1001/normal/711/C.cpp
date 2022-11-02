#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 101234567891234567;
int n, m, t, c[109]; long long p[109][109], dp[109][109][109]; bool vis[109][109][109];
long long solve(int pos, int beauty, int cur) {
	if (pos == -1) return beauty == t ? 0 : inf;
	if (vis[pos][beauty][cur]) return dp[pos][beauty][cur];
	long long ret = inf;
	for (int i = 1; i <= m; i++) {
		if (c[pos] != 0 && c[pos] != i) continue;
		long long res = solve(pos - 1, beauty + (cur == i ? 0 : 1), i);
		ret = min(ret, res + (c[pos] == 0 ? p[pos][i - 1] : 0));
	}
	vis[pos][beauty][cur] = true;
	return dp[pos][beauty][cur] = ret;
}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> p[i][j];
		}
	}
	long long ret = solve(n - 1, 0, m + 1);
	cout << (ret != inf ? ret : -1) << endl;
	return 0;
}