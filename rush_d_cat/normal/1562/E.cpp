#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 10;
char s[N];
int lcp[N][N], n;

int main() {
	int t; 
	scanf("%d", &t);
	while (t --) {
		scanf("%d%s", &n, s + 1);
		for (int i = 0; i <= n + 1; i ++) 
			for (int j = 0; j <= n + 1; j ++) 
				lcp[i][j] = 0;
	
		for (int i = n; i >= 1; i --) {
			for (int j = n; j >= 1; j --) {
				lcp[i][j] = ((s[i] == s[j]) ? (lcp[i+1][j+1] + 1): 0);
				//printf("lcp %d %d = %d\n", i, j, lcp[i][j]);
			}
		}
		//printf("# %d\n", lcp[2][6]);
		auto ok = [&](int i, int j) {
			// i < j, check suf[i] < suf[j];
			if (j + lcp[i][j] == n + 1) return false;
			return s[i + lcp[i][j]] < s[j + lcp[i][j]];
		};
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= n; i ++) {
			dp[i] = n - i + 1;
			for (int j = 1; j < i; j ++) {
				if (ok(j, i)) {
					dp[i] = max(dp[i], dp[j] + n - i + 1 - lcp[j][i]);
				}
			}
		}
		int ans = *max_element(dp.begin() + 1, dp.end());
		printf("%d\n", ans);
	}
}