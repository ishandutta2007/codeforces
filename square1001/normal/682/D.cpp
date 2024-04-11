#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, p; string s, t; int match[1009][1009], dp[13][1009][1009];
int main() {
	cin >> n >> m >> p >> s >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) match[i + 1][j + 1] = match[i][j] + 1;
		}
	}
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int r = match[j + 1][k + 1];
				dp[i + 1][j + 1][k + 1] = max({ dp[i + 1][j][k + 1], dp[i + 1][j + 1][k], dp[i][j - r + 1][k - r + 1] + r });
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ret = max(ret, dp[p][i][j]);
		}
	}
	cout << ret << endl;
	return 0;
}