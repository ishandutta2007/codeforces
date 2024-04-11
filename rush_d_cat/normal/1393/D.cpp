#include <bits/stdc++.h>
using namespace std;
const int N = 2002;
typedef long long LL;
char s[N][N];
int n, m;
bool flag[N][N];
int U[N][N], D[N][N];
int dp[4][N][N];
LL solve() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] != s[i-1][j]) U[i][j] = 1;
			else {
				U[i][j] = U[i-1][j] + 1; 
			}
		}
	}

	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j] != s[i+1][j]) D[i][j] = 1;
			else {
				D[i][j] = D[i+1][j] + 1;
			}
		}
	}

	LL ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (s[i][j-1] != s[i][j]) {
				dp[0][i][j] = 1;
			} else {
				dp[0][i][j] = min(dp[0][i][j-1] + 1, U[i][j]);
			}
			if (s[i][j-1] != s[i][j]) {
				dp[2][i][j] = 1;
			} else {
				dp[2][i][j] = min(dp[2][i][j-1] + 1, D[i][j]);
			}
		}
		for (int j = m; j >= 1; j --) {
			if (s[i][j+1] != s[i][j]) {
				dp[1][i][j] = 1;
			} else {
				dp[1][i][j] = min(dp[1][i][j+1] + 1, U[i][j]);
			}
			if (s[i][j+1] != s[i][j]) {
				dp[3][i][j] = 1;
			} else {
				dp[3][i][j] = min(dp[3][i][j+1] + 1, D[i][j]);
			}
			//printf("%d %d: %d %d %d %d\n", i, j, dp[0][i][j], dp[1][i][j], dp[2][i][j], dp[3][i][j]);
			ans += min(min(dp[0][i][j], dp[1][i][j]), min(dp[2][i][j], dp[3][i][j]));
			//printf("::: %d %d: %d\n", i, j,  (min(dp[0][i][j], dp[1][i][j]), min(dp[2][i][j], dp[3][i][j])));
		}
	}
	return ans;

}



int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
	}
	cout << solve() << endl;
}