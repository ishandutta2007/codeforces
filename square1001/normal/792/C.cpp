#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
string s; int a[100009], dp[100009][3];
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) a[i] = s[i] - 48;
	dp[0][0] = dp[0][1] = dp[0][2] = -999999999;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 3; j++) {
			dp[i + 1][j] = max(dp[i][j], dp[i][(j - a[i] + 9) % 3] + 1);
			if (a[i] != 0 && j % 3 == a[i] % 3) dp[i + 1][j] = max(dp[i + 1][j], 1);
		}
	}
	if (dp[s.size()][0] < 0) {
		if (s.find('0') != string::npos) cout << 0 << endl;
		else cout << -1 << endl;
	}
	else {
		int m = 0; string ret;
		for (int i = s.size() - 1; ; i--) {
			int lc = dp[i][m], rc = dp[i][(m - a[i] + 9) % 3];
			if (rc + 1 == dp[i + 1][m]) ret += s[i], m = (m - a[i] + 9) % 3;
			else if (a[i] != 0 && m % 3 == a[i] % 3 && ret.size() + 1 == dp[s.size()][0]) {
				ret += s[i];
				break;
			}
		}
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}