#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	int dp[32] = {0};
	dp[0] = 1;
	for (int i = 1; i <= 30; i ++) {
		int w1 = dp[i-1];
		int w2 = (1<<(i-1)) + w1;
		if ((w1 + w2) % 2 == 0) dp[i] = w2; else dp[i] = w1;
	}
	while (t --) {
		int n;
		cin >> n;
		cout << dp[n] << "\n";
	}
}