#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t, n, a[N];
int dp[N][2];
void upd(int &x, int y) {
	x = min(x, y);
}
int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++)
			scanf("%d", &a[i]);
		for (int i = 0; i <= n; i ++) dp[i][0] = dp[i][1] = 1e9;
		dp[0][0] = 0;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 2; j ++) {
	
				if (i + 1 <= n) {
					int add = 0;
					if (j == 0 && a[i+1] == 1) add ++;
					upd(dp[i+1][j^1], dp[i][j] + add);
				}
				if (i + 2 <= n) {
					int add = 0;
					if (j == 0 && a[i+1] == 1) add ++;
					if (j == 0 && a[i+2] == 1) add ++;
					upd(dp[i+2][j^1], dp[i][j] + add);
				}
			}
		}
		printf("%d\n", min(dp[n][0], dp[n][1]));
	}
}