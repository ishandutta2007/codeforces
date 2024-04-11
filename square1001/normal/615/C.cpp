#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
string s, t; int llcp[2109][2109], rlcp[2109][2109], dp[2109], ansl[2109], ansr[2109];
int main() {
	cin >> s >> t;
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = t.size() - 1; j >= 0; j--) {
			if (s[i] == t[j]) llcp[i][j] = llcp[i + 1][j + 1] + 1;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = t.size() - 1; j >= 0; j--) {
			if (s[i] == t[j]) rlcp[i + 1][j] = rlcp[i][j + 1] + 1;
		}
	}
	for (int i = t.size() - 1; i >= 0; i--) {
		dp[i] = 1012345678;
		for (int j = 0; j < s.size(); j++) {
			if (dp[i] > dp[i + llcp[j][i]] + 1) {
				dp[i] = dp[i + llcp[j][i]] + 1;
				ansl[i] = j;
				ansr[i] = j + llcp[j][i] - 1;
			}
		}
		for (int j = 1; j <= s.size(); j++) {
			if (dp[i] > dp[i + rlcp[j][i]] + 1) {
				dp[i] = dp[i + rlcp[j][i]] + 1;
				ansl[i] = j - 1;
				ansr[i] = j - rlcp[j][i];
			}
		}
	}
	if (dp[0] == inf) cout << -1 << endl;
	else {
		cout << dp[0] << endl;
		int pos = 0;
		while (pos < t.size()) {
			cout << ansl[pos] + 1 << ' ' << ansr[pos] + 1 << endl;
			pos += abs(ansr[pos] - ansl[pos]) + 1;
		}
	}
	return 0;
}