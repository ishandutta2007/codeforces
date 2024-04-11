#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	ll cur;
	int twos[n], fives[n];
	for (int i = 0; i < n; i++) {
		twos[i] = 0;
		fives[i] = 0;
		cin >> cur;
		while (cur % 2 == 0) {
			twos[i]++;
			cur = cur /2;
		}
		while (cur %5 == 0) {
			fives[i]++;
			cur = cur/5;
		}
	}
	int dp[k+1][5001];
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < 5001; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	int ans = 0;
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = k; j >= 1; j--) {
			for (int l = fives[i]; l <= 5000; l++) {
				// cout << i << " " << j << " " << l;
				temp = dp[j-1][l-fives[i]];
				if (temp < 0) continue;
				dp[j][l] = max(dp[j][l],  temp + twos[i]);

			}
		}
	}
	for (int i = 0; i <= 5000; i++) {
		// cout << i << " " << min(i, dp[n-1][i]) << endl;
		if (dp[k][i] == -1) continue;
		ans = max(ans, min(i, dp[k][i]));
	}
	cout << ans << endl;
	cin >> n;
}