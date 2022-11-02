#include <vector>
#include <iostream>
using namespace std;
const int64_t mod = 1000000000061; // prime
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, q, l, r, x;
	cin >> n >> q;
	vector<vector<int> > gl(n + 1), gr(n + 1);
	for (int i = 0; i < q; ++i) {
		cin >> l >> r >> x; --l;
		gl[l].push_back(x);
		gr[r].push_back(x);
	}
	vector<int64_t> dp(n + 1, 0); dp[0] = 1;
	vector<bool> ans(n + 1, false);
	for (int i = 0; i < n; ++i) {
		for (int j : gr[i]) {
			for (int k = 0; k <= n - j; ++k) {
				dp[k + j] -= dp[k];
				if (dp[k + j] < 0) dp[k + j] += mod;
			}
		}
		for (int j : gl[i]) {
			for (int k = n - j; k >= 0; --k) {
				dp[k + j] += dp[k];
				if (dp[k + j] >= mod) dp[k + j] -= mod;
			}
		}
		for (int j = 0; j <= n; ++j) {
			if (dp[j] != 0) ans[j] = true;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += (ans[i] ? 1 : 0);
	}
	cout << cnt << '\n';
	for (int i = 1; i <= n; ++i) {
		if (ans[i]) cout << i << ' ';
	}
	return 0;
}