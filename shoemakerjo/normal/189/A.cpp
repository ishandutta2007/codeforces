#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int dp[n+1];
	dp[n] = 1;
	for (int i = n-1; i >= 0; i--) {
		dp[i] = 0;
		if (i+a <= n && dp[i+a] > 0) {
			dp[i] = max(dp[i], dp[i+a]+1);
		}
		if (i+b <= n && dp[i+b] > 0) {
					dp[i] = max(dp[i], dp[i+b]+1);
		}
		if (i+c <= n && dp[i+c] > 0) {
					dp[i] = max(dp[i], dp[i+c]+1);
		}
	}

	cout << dp[0]-1 << '\n';
//	for (int i = 0; i <= n; ++i) {
//		cout << dp[i] << " ";
//	}
}