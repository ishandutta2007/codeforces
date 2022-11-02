#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
int main() {
	int n;
	cin >> n;
	vector<long long> sum(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	vector<vector<long long> > dp(n + 1, vector<long long>(4, -inf));
	for (int i = 0; i <= n; ++i) {
		if (i >= 1) {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 1][2];
			dp[i][3] = dp[i - 1][3];
		}
		else dp[i][0] = 0;
		dp[i][1] = max(dp[i][1], dp[i][0] + sum[i] * 2);
		dp[i][2] = max(dp[i][2], dp[i][1] - sum[i] * 2);
		dp[i][3] = max(dp[i][3], dp[i][2] + sum[i] * 2);
	}
	int pos = n, row = 3;
	vector<int> ans;
	while (pos != 0 || row != 0) {
		if (row >= 1 && dp[pos][row] - dp[pos][row - 1] == sum[pos] * (row == 2 ? -2 : 2)) {
			--row;
			ans.push_back(pos);
		}
		else --pos;
	}
	cout << ans[2] << ' ' << ans[1] << ' ' << ans[0] << endl;
	return 0;
}