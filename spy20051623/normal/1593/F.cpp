#include <bits/stdc++.h>

using namespace std;

int x[50];
pair<int, int> dp[41][41][41][41];
int n, a, b;

void display(int i, int j, int k, int l) {
	if (!i) return;
	if (dp[i][j][k][l].first) display(i - 1, dp[i][j][k][l].second, k, l - 1);
	else display(i - 1, j, dp[i][j][k][l].second, l);
	printf("%c", dp[i][j][k][l].first ? 'R' : 'B');
}

void solve() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; ++i) scanf("%1d", &x[i]);
	memset(dp, -1, sizeof dp);
	dp[0][0][0][0].first = -2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a; ++j) {
			for (int k = 0; k < b; ++k) {
				for (int l = 0; l <= i; ++l) {
					if (dp[i][j][k][l].first != -1) {
						if (dp[i + 1][(j * 10 + x[i]) % a][k][l + 1].first == -1)
							dp[i + 1][(j * 10 + x[i]) % a][k][l + 1] = make_pair(1, j);
						if (dp[i + 1][j][(k * 10 + x[i]) % b][l].first == -1)
							dp[i + 1][j][(k * 10 + x[i]) % b][l] = make_pair(0, k);
					}
				}
			}
		}
	}
	for (int i = 0; i <= n / 2; ++i) {
		if (n / 2 + i < n) {
			if (dp[n][0][0][n / 2 + i].first != -1) {
				display(n, 0, 0, n / 2 + i);
				puts("");
				return;
			}
		}
		if (n / 2 - i > 0) {
			if (dp[n][0][0][n / 2 - i].first != -1) {
				display(n, 0, 0, n / 2 - i);
				puts("");
				return;
			}
		}
	}
	printf("-1\n");
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}