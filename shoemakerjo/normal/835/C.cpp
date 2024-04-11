#include <iostream>

using namespace std;

int main() {
	int n, q, c;
	cin >> n >> q >> c;
	int dp[101][101][c+1];
	for (int i = 0; i <=100; i++) {
		for (int j = 0; j <=100; j++) {
			for (int k = 0; k <=c; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	int x, y, s;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> s;
		dp[x][y][s]++;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <=100; j++) {
			for (int k = 0; k <= c; k++) {
				dp[i][j][k] += dp[i-1][j][k] + dp[i][j-1][k];
				dp[i][j][k] -= dp[i-1][j-1][k];
			}
		}
	}
	// cout << "---->   " << dp[100][100][0] << endl;
	int t, x1, x2, y1, y2;
	int temp, ans;
	int ct[c+1];
	for (int i = 0; i < q; i++) {
		ans = 0;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		
		for (int j = 0; j <= c; j++) {
			ct[j] = 0;
		}
		for (int j = 0; j <= c; j++) {
			ct[j] += dp[x2][y2][j];
			// cout << ct[j] << endl;
			ct[j] -= dp[x1-1][y2][j];
			ct[j] -= dp[x2][y1-1][j];
			ct[j] += dp[x1-1][y1-1][j];
			temp = (j+t)%(c+1);
			ans += ct[j]*temp;
			// cout << ct[j] << endl;
			// cout << "ans: " << ans << endl;
		}
		cout << ans << endl;
	}
	// cin >> n;
}