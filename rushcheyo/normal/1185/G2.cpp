#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
int n, T, t[55], g[55], cnt[3], f[3][55][55][55];
vector<vector<vector<vector<int>>>> dp;

void inc(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }

int main() {
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", t + i, g + i), --g[i];
		++cnt[g[i]];
	}
	dp.resize(cnt[0] + 1);
	for (int a = 0; a <= cnt[0]; ++a) {
		dp[a].resize(cnt[1] + 1);
		for (int b = 0; b <= cnt[1]; ++b) {
			dp[a][b].resize(cnt[2] + 1);
			for (int c = 0; c <= cnt[2]; ++c)
				dp[a][b][c].resize(T + 1);
		}
	}

	dp[0][0][0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int a = cnt[0]; a >= (g[i] == 0); --a)
			for (int b = cnt[1]; b >= (g[i] == 1); --b)
				for (int c = cnt[2]; c >= (g[i] == 2); --c)
					for (int j = T; j >= t[i]; --j)
						inc(dp[a][b][c][j], dp[a - (g[i] == 0)][b - (g[i] == 1)][c - (g[i] == 2)][j - t[i]]);
	int ans = 0;
	f[0][0][0][0] = f[1][0][0][0] = f[2][0][0][0] = 1;
	for (int a = 0; a <= cnt[0]; ++a)
		for (int b = 0; b <= cnt[1]; ++b)
			for (int c = 0; c <= cnt[2]; ++c) {
				if (a)
					f[0][a][b][c] = 1LL * a * (f[1][a - 1][b][c] + f[2][a - 1][b][c]) % P;
				if (b)
					f[1][a][b][c] = 1LL * b * (f[0][a][b - 1][c] + f[2][a][b - 1][c]) % P;
				if (c)
					f[2][a][b][c] = 1LL * c * (f[0][a][b][c - 1] + f[1][a][b][c - 1]) % P;
				ans = (ans + (0LL + f[0][a][b][c] + f[1][a][b][c] + f[2][a][b][c]) * dp[a][b][c][T]) % P;
			}
	ans = (P + 1LL) / 2 * ans % P;
	printf("%d\n", ans);
	return 0;
}