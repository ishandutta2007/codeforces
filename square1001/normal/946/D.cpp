#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, p, dp[509][509];
int main() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		vector<int> v;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') v.push_back(j);
		}
		fill(dp[i], dp[i] + p + 1, 1 << 30);
		int x = v.size();
		for (int j = 0; j <= x; ++j) {
			int mn = 1 << 30;
			if (j == x) mn = 0;
			else {
				for (int k = x - j - 1; k < x; ++k) {
					mn = min(mn, v[k] - v[k - (x - j - 1)] + 1);
				}
			}
			for (int k = j; k <= p; ++k) {
				dp[i][k] = min(dp[i][k], dp[i - 1][k - j] + mn);
			}
		}
	}
	cout << dp[n][p] << '\n';
	return 0;
}