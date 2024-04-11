#include <string>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int n, pl[79], dp[77][1048588]; string s;
bool equal(int l, int r, int x) {
	for (int i = l; i < r; i++) {
		if (i < r - 5 && s[i] == '1') return false;
		if (s[i] - 48 != (x & (1 << (r - i - 1)) ? 1 : 0)) return false;
	}
	return true;
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		pl[i] = -1;
		for (int j = i; j < n; j++) {
			if (s[j] == '1') {
				pl[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < 1048576; j++) {
			if (pl[i] == -1) continue;
			int x = 0;
			for (int k = pl[i]; k < n; k++) {
				x = x * 2 + s[k] - 48; if (x > 20) break;
				dp[k + 1][j | (1 << (x - 1))] += dp[i][j];
				if (dp[k + 1][j | (1 << (x - 1))] >= mod) dp[k + 1][j | (1 << (x - 1))] -= mod;
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 20; j++) {
			ret += dp[i][(1 << j) - 1];
			if (ret >= mod) ret -= mod;
		}
	}
	cout << ret << endl;
	return 0;
}