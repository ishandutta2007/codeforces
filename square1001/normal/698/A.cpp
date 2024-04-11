#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int n, a[109], dp[109][3]; bool vis[109][3];
int solve(int pos, int pre) {
	if (pos == n) return 0;
	if (vis[pos][pre]) return dp[pos][pre];
	int ret = solve(pos + 1, 2) + 1;
	if (pre != 0 && a[pos] & 1) ret = min(ret, solve(pos + 1, 0));
	if (pre != 1 && a[pos] & 2) ret = min(ret, solve(pos + 1, 1));
	vis[pos][pre] = true;
	dp[pos][pre] = ret;
	return ret;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << solve(0, 2) << endl;
	return 0;
}