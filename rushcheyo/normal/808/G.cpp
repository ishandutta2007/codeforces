#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
char s[N], t[N];
int n, m, dp[2][N], ch[N][26], fail[N];

void upd(int &a, int b) { if (a < b) a = b; }

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 0; i < m; i++) ch[i][t[i + 1] - 'a'] = i + 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 26; j++)
			if (ch[i][j]) fail[ch[i][j]] = ch[fail[i]][j];
			else ch[i][j] = ch[fail[i]][j];
	}
	memset(dp[0], -1, sizeof dp[0]);
	dp[0][0] = 0;
	int lst = 1, now = 0;
	for (int i = 0; i < n; i++) {
		lst ^= 1, now ^= 1;
		memset(dp[now], -1, sizeof dp[now]);
		for (int j = 0; j <= m; j++) {
			if (dp[lst][j] == -1) continue;
			if (s[i + 1] == '?')
				for (int k = 0; k < 26; k++)
					upd(dp[now][ch[j][k]], dp[lst][j] + (ch[j][k] == m));
			else {
				int k = s[i + 1] - 'a';
				upd(dp[now][ch[j][k]], dp[lst][j] + (ch[j][k] == m));
			}
		}
	}
	printf("%d\n", *max_element(dp[now], dp[now] + m + 1));
	return 0;
}