#include <bits/stdc++.h>
using namespace std;

#define N 111
#define M 10101

int n, a[N], b[N];
int dp[3*M][N];
const int inf = -1e9;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d %d", &a[i], &b[i]), a[i] *= 2;
    for (int i = 0; i < 2 * M; i ++) for (int j = 0; j < N; j ++) dp[i][j] = inf;
    for (int i = 2 * M; i < 3 * M; i ++) dp[i][0] = 0;
    for (int i = 0; i < 2 * M; i ++) dp[i][0] = i - 2 * M;
    for (int i = 1; i <= n; i ++) {
		for (int k = n; k >= 1; k --) for (int j = 0; j < 3 * M; j ++) {
			int c = j + b[i] - a[i];
			if (c >= 0 && c < 3 * M) {
				int p = dp[c][k-1];
				if (p != inf) dp[j][k] = max(dp[j][k], p + a[i]);
			}
		}
    }
    int up = 0;
    for (int i = 1; i <= n; i ++) up += b[i];
    for (int k = 1; k <= n; k ++) printf("%f ", 0.5 * dp[up+2*M][k]);

    return 0;
}