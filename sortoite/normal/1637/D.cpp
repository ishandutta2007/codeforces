#include<bits/stdc++.h>
using namespace std;
const int N = 111, M = 1e4 + 10;
int dp[N][M], crr;
int a[N], b[N];
int solve() {
	int n, sum = 0, tot = 0, sq = 0; scanf("%d", &n);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 1; i <= n; i ++) scanf("%d", b + i);
	crr ++;
	dp[0][0] = crr;
	for(int i = 1; i <= n; i ++) {
		sum += max(a[i], b[i]);
		tot += a[i] + b[i];
		sq += a[i] * a[i] + b[i] * b[i];
		for(int j = 0; j <= sum; j ++) {
			if((j >= a[i] && dp[i - 1][j - a[i]] == crr) || (j >= b[i] && dp[i - 1][j - b[i]] == crr)) dp[i][j] = crr;
		}
	}
	int ans = 2e9;
	for(int i = 0; i <= sum; i ++) {
		if(dp[n][i] == crr) {
			ans = min(ans, i * i + (tot - i) * (tot - i));
		}
	}
	return ans + (n - 2) * sq;
}
int main() {
#ifdef TRUE
	freopen("in.in", "r", stdin);
#endif
	int T; cin >> T;
	while(T --) {
		cout << solve() << endl;
	}
	return 0;
}