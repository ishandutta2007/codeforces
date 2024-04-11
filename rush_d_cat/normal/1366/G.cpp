#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 10;
char s[N], t[N];
int pre[N], slen, tlen;
int dp[N][N];
int main() {
	scanf("%s%s", s+1, t+1);
	slen = strlen(s + 1), tlen = strlen(t + 1);
	int stk[N] = {0}, top = 0;
	for (int i = 1; i <= slen; i ++) {
		if (s[i] != '.') stk[++top] = i;
		else {
			if (top) {
				pre[i] = stk[top]; -- top;
			} else {
				pre[i] = 0;
			}
		}
	}
	for (int i = 0; i < N; i ++) for (int j = 0; j < N; j ++) dp[i][j] = 1e9;
	dp[0][0] = 0; 
	for (int i = 1; i <= slen; i ++) {
		for (int j = 0; j <= tlen; j ++) {
			if (s[i] == t[j] && j) {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
			}
			dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);

			if (pre[i]) {
				int laspos = pre[i];
				dp[i][j] = min(dp[laspos - 1][j], dp[i][j]);
			}
		}
	}
	printf("%d\n", dp[slen][tlen]);
}