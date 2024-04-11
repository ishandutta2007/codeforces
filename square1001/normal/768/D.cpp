#include <iostream>
using namespace std;
int n, q, x; double dp[16009][2009];
int main() {
	cin >> n >> q;
	dp[0][0] = 1.0;
	for (int i = 0; i < 16000; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i + 1][j] = dp[i][j] * j / n + dp[i][j - 1] * (n - j + 1) / n;
		}
	}
	while (q--) {
		cin >> x;
		for (int i = 0; i <= 16000; i++) {
			if (dp[i][n] * 2000 >= x) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}