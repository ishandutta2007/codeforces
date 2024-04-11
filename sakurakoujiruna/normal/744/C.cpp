#include <bits/stdc++.h>
using namespace std;

const int N = 16;

int c[N], r[N], b[N];
int dp[1 << N][(N + 2) * (N + 2)];

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 0; i < n; i ++) {
		char t; cin >> t;
		if(t == 'R') c[i] = 0;
		else c[i] = 1;
		cin >> r[i] >> b[i];
	}
	for(int i = 0; i < 1 << N; i ++)
		for(int j = 0; j < (N + 2) * (N + 2); j ++)
			dp[i][j] = -4e8L;

	dp[(1 << n) - 1][0] = 0;
	for(int k = (1 << n) - 1; k > 0; k --) {
		int br = 0, bb = 0;
		for(int i = 0; i < n; i ++) {
			if((k >> i) & 1) continue;
			if(c[i]) bb ++;
			else br ++;
		}
		for(int i = 0; i < n; i ++) if((k >> i) & 1) {
			int cr = min(br, r[i]);
			int cb = min(bb, b[i]);
			for(int j = 0; j <= n * n; j ++) if(dp[k][j] >= 0) {
				dp[k ^ (1 << i)][j] = max(dp[k ^ (1 << i)][j], dp[k][j]);
				dp[k ^ (1 << i)][j + cr] = max(dp[k ^ (1 << i)][j + cr],
					dp[k][j] + cb);
			}
		}
	}

	int sr = accumulate(r, r + n, 0);
	int sb = accumulate(b, b + n, 0);

	int ans = max(sr, sb);
	for(int i = 0; i <= n * n; i ++)
		ans = min(ans, max(sr - i, sb - dp[0][i]));

	ans = max(ans, 0);

	cout << ans + n << '\n';
	return 0;
}