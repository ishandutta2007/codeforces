#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int dp[n+1][m+1];
	vector<vector<int>> nums;
	for (int i = 0; i <= n; i++) {
		vector<int> b;
		nums.push_back(b);
		for (int j = 0; j <=m; j++) {
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		int ct, cur;
		cin >> ct;
		for (int j = 0; j < ct; j++) {
			cin >> cur;
			nums[i].push_back(cur);
		}
	}
	int si;
	for (int i = 1; i <= n; i++) {

		si = nums[i].size();
		int pref[si+1];
		pref[0] = 0;
		for (int k = 1; k<=si; k++) {
			pref[k] = pref[k-1]+nums[i][k-1];
		}
		int suc[si+1];
		suc[0] = 0;
		for (int k = 1; k <= si; k++) {
			suc[k] = suc[k-1] + nums[i][si-k];
		}	
		for (int j = 0; j <= m; j++) {
			dp[i][j] = dp[i-1][j];
		}
		for (int j = 0; j <= si; j++) {
			//take j from this row
			
			int best = 0;
			for (int k = 0; k <= j; k++) {
				best = max(best, pref[k] + suc[j-k]);
			}

			for (int k = 0; k <= m; k++) {
				if (k - j >= 0) {
					dp[i][k] = max(dp[i][k], best + dp[i-1][k-j]);
				}
			}
		}
	}
	cout << dp[n][m] << endl;
	// cin >> si;
}