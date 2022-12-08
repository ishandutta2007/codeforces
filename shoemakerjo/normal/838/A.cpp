#include <bits/stdc++.h>

using namespace std;

bool isPrime(int k) {
	for (int i = 2; i <= sqrt(k); i++) {
		if (k%i == 0) return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	bool grid[n][m];
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < m; j++) {
			grid[i][j] = (line[j] == '1');
		}
	}
	int dp[n][m]; //stores number of 1's to the left and to the right
	for (int i = n-1; i >=0; i--) {
		for (int j = m-1; j >= 0; j--) {
			dp[i][j] = 0;
			if (i < n-1) dp[i][j] += dp[i+1][j];
			if (j < m-1) dp[i][j] += dp[i][j+1];
			if (i < n-1 && j < m-1) {
				dp[i][j] -= dp[i+1][j+1];
			}
			if (grid[i][j]) dp[i][j]++;
		}
	}
	int ans = n*m;
	for (int k = 2; k <= n; k++) {
		if (!isPrime(k)) continue;
		int tot = 0;
		for (int i = 0; i < n; i+=k) {
			for (int j = 0; j < m; j+=k) {
				int one = dp[i][j];
				if (i + k < n) {
					one -= dp[i+k][j];
				}
				if (j + k < m) {
					one -= dp[i][j+k];
				}
				if (i+k < n && j + k < m) {
					one += dp[i+k][j+k];
				}
				tot += min(one, k*k-one);
			}
		}
		ans = min(ans, tot);
	}
	cout << ans << endl;
	cin >> n;
}