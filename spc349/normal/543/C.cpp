#include <bits/stdc++.h>
using namespace std;

int c[30][30];
int dp[1 << 20];
string a[30];
int cnt[30], mmm[30], maxj[30], sum[30];

int main () {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		int minj = 0x3f3f3f3f;
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			minj = min(minj, c[i][j]);
		}
		for (int mask = (1 << n) - 1; mask >= 0; mask--) {
			if (mask >> i & 1) dp[mask] = min(dp[mask], dp[mask ^ 1 << i] + minj);
		}
	}
	for (int j = 0; j < m; j++) {
		memset(cnt, 0, sizeof(cnt)), memset(mmm, 0, sizeof(mmm));
		memset(sum, 0, sizeof(sum)), memset(maxj, -1, sizeof(maxj));
		for (int i = 0; i < n; i++) {
			cnt[a[i][j] - 'a']++, mmm[a[i][j] - 'a'] |= 1 << i;
			sum[a[i][j] - 'a'] += c[i][j], maxj[a[i][j] - 'a'] = max(maxj[a[i][j] - 'a'], c[i][j]);
		}
		for (int i = 0; i < 26; i++) {
			if (!cnt[i]) continue;
			int tmp = mmm[i], val = sum[i] - maxj[i];
			for (int mask = (1 << n) - 1; mask >= 0; mask--) {
				dp[mask | tmp] = min(dp[mask | tmp], dp[mask] + val); 
			}
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}