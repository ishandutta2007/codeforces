#include <bits/stdc++.h>
using namespace std;
const int N = 4002;
int T, n;
int a[N], b[N], tot;
int dp[N][2002];

int main() {
	scanf("%d", &T);
	while (T --) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i ++) {
			scanf("%d", &a[i]);
		}
		int mx = 0;
		vector<int> vec;
		for (int i = 1; i <= 2 * n; i ++) {
			if (a[i] >= mx) {
				vec.push_back(i);
				//printf("# %d\n");
			}
			mx = max(mx, a[i]);
		}
		vec.push_back(2 * n + 1);

		tot = 0;
		for (int i = 0; i + 1 < vec.size(); i ++) {
			b[++tot] = vec[i + 1] - vec[i];
			//printf("tot = %d, b = %d\n", tot, b[tot]);
		}

		for (int i = 0; i <= tot; i ++) {
			for (int j = 0; j <= n; j ++) {
				dp[i][j] = 0;
			}
		}
		dp[0][0] = 1;
		for (int i = 0; i < tot; i ++) {
			for (int j = 0; j <= n; j ++) {
				if (dp[i][j]) {
					dp[i + 1][j] = 1;
					if (j + b[i+1] <= n)
					dp[i + 1][j + b[i + 1]] = 1;
				}
			}
		}
		printf("%s\n", dp[tot][n] ? "YES" : "NO");
	}
}