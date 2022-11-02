#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m; string s, t = "WDL"; bool dp[1009][2009];
int main() {
	cin >> n >> m >> s; dp[0][m] = true;
	for (int i = 0; i < n; i++) {
		for (int j = -m; j <= m; j++) {
			for (int k = -1; k <= 1; k++) {
				if (s[i] != '?' && s[i] != t[k + 1]) continue;
				if (-m < j + k && j + k < m && dp[i][j + k + m]) dp[i + 1][j + m] = true;
			}
		}
	}
	int pos = 0;
	if (dp[n][0]) pos = -m;
	else if (dp[n][2 * m]) pos = m;
	if (pos == 0) cout << "NO" << endl;
	else {
		string ret;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = -1; j <= 1; j++) {
				if (s[i] != '?' && s[i] != t[j + 1]) continue;
				if (-m < pos + j && pos + j < m && dp[i][pos + j + m]) {
					ret += t[j + 1];
					pos += j;
					break;
				}
			}
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}