#include <bits/stdc++.h>
using namespace std;

const int N = 1100;
const int inf = 1e9;

int dp[N][N][2], pa[N][N][2], k, flag = 0;

void output (int x, int y) {
	if (x == 1 && y == 1) return ;
	if (pa[x][y][k]) output(x, y - 1), cout << 'R';
	else output(x - 1, y), cout << 'D';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[0][i][0] = dp[i][0][0] = dp[0][i][1] = dp[i][0][1] = inf;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> k;
			if (k) {
				for ( ; !(k % 2); k /= 2) dp[i][j][0]++;
				for ( ; !(k % 5); k /= 5) dp[i][j][1]++;
			} else flag = i;
			for (k = 0; k < 2; k++) {
				if ((pa[i][j][k] = dp[i][j - 1][k] < dp[i - 1][j][k])) dp[i][j][k] += dp[i][j - 1][k];
				else dp[i][j][k] += dp[i - 1][j][k];
			}
		}
	}
	k = dp[n][n][1] < dp[n][n][0];
	if (flag && dp[n][n][k] > 1) {
		cout << 1 << endl;
		for (int i = 1; i < flag; i++) cout << 'D';
		for (int i = 1; i < n; i++) cout << 'R';
		for (int i = flag; i < n; i++) cout << 'D';
		cout << endl;
	} else {
		cout << dp[n][n][k] << endl;
		output(n, n);
	}
	return 0;
}