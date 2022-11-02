#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int>dp(n);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = dp[a[i] - 1] + 1;
	}
	for (int i = 0; i < n; i++) {
		//cout << dp[i] << " ";
	}
	sort(dp.begin(), dp.end());
	int cnt = 1;
	int ans = 0;
	for (int i = 1; i < n; i++) {
		if (dp[i] == dp[i - 1]) {
			cnt += 1;
		}
		else {
			ans += cnt % 2;
			cnt = 1;
		}
	}
	ans += cnt % 2;
	cout << ans;
	return 0;
}