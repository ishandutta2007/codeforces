#include <bits/stdc++.h>

using namespace std;

char s[5005], t[5005];
int nxt1[5005][26], nxt2[5005][26], dp[5005][5005];
int res;

int dfs(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 2;
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		if (nxt1[x][i] != -1 && nxt2[y][i] != -1) {
			ans = max(ans, dfs(nxt1[x][i], nxt2[y][i]) - (nxt1[x][i] - x - 1) - (nxt2[y][i] - y - 1));
		}
	}
	dp[x][y] += ans;
	res = max(res, dp[x][y]);
	return dp[x][y];
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s%s", s + 1, t + 1);
	for (int i = 0; i < 26; ++i) {
		nxt1[n][i] = -1;
		for (int j = n; j >= 1; --j) {
			if (s[j] == 'a' + i) nxt1[j - 1][i] = j;
			else nxt1[j - 1][i] = nxt1[j][i];
		}
		nxt2[m][i] = -1;
		for (int j = m; j >= 1; --j) {
			if (t[j] == 'a' + i) nxt2[j - 1][i] = j;
			else nxt2[j - 1][i] = nxt2[j][i];
		}
	}
	memset(dp, -1, sizeof dp);
	for (int i = 0; i < 26; ++i) {
		for (int x = 0; nxt1[x][i] != -1; x = nxt1[x][i]) {
			for (int y = 0; nxt2[y][i] != -1; y = nxt2[y][i]) {
				dfs(nxt1[x][i], nxt2[y][i]);
			}
		}
	}
	printf("%d\n", res);
	return 0;
}