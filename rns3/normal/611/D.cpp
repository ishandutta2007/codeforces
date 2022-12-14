#include <cstdio>
#include <algorithm>

using namespace std;

#define N 5005

const int MOD = 1000000007;

char s[N];
int lcp[N][N];

int dp[N][N];

main() {
	//freopen("D.in", "r", stdin);
	int n;
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = n; i; i --) {
		for (int j = n; j; j --) {
			if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
			else lcp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			dp[i][j] = dp[i][j - 1];
			int ii = i - j;
			if (s[ii + 1] == '0') continue;
            int jj = min(j - 1, ii);
            dp[i][j] += dp[ii][jj];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
            if (j <= ii) {
            	int iii = ii - j;
				int LCP = lcp[iii + 1][ii + 1];
				if (LCP >= j) continue;
				else if (s[iii + LCP + 1] < s[ii + LCP + 1]) {
					dp[i][j] += dp[ii][j] - dp[ii][j - 1];
					if (dp[i][j] >= MOD) dp[i][j] -= MOD;
					else if (dp[i][j] < 0) dp[i][j] += MOD;
				}
            }
		}
		dp[i][i] = dp[i][i - 1] + 1;
		if (dp[i][i] >= MOD) dp[i][i] -= MOD;
	}
	printf("%d\n", dp[n][n]);
}