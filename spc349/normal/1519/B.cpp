#include <bits/stdc++.h>
using namespace std;

bitset <10010> dp[110][110];

int main() {
	dp[1][1][0] = 1;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			dp[i][j + 1] |= dp[i][j] << i;
			dp[i + 1][j] |= dp[i][j] << j;
		}
	}
	int T; cin >> T;
	while (T--) {
		int n, m, k; cin >> n >> m >> k;
		if (dp[n][m][k]) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}