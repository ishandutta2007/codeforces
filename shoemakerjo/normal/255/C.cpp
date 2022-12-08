#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int nums[n];
	vector<int> nu;
	set<int> seen;
	map<int, int> rank;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		if (seen.find(nums[i])!=seen.end()) continue;
		nu.push_back(nums[i]);
	}
	sort(nu.begin(), nu.end());
	for (int i = 0; i < n; i++) {
		rank[nu[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		nums[i] = rank[nums[i]];
	}

	int ans = 1;
	int dp[n][n];
	for (int i = 0; i < n; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1;
		}
		for (int j = 0; j < i; j++) {
			dp[i][nums[j]] = max(dp[i][nums[j]], dp[j][nums[i]] + 1);
			ans = max(ans, dp[i][nums[j]]);
		}
	}
	cout << ans << "\n";
	// cin >> n;
}