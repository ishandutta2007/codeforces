#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, x, y; long long dp[300009]; string s;
int main() {
	cin >> n >> x >> y >> s;
	int num = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1]) ++num;
	}
	dp[2] = y;
	dp[3] = min(dp[2] + x, dp[1] + y + (s[0] == '0' ? min(x, y) : 0));
	for (int i = 4; i <= num; ++i) {
		dp[i] = dp[i - 2] + min(x, y);
	}
	cout << (num >= 2 || s[0] == '1' ? dp[num] : y) << '\n';
	return 0;
}