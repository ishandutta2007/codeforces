#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const int N = 2002;
int n, m;
pair<int, int> a[N];
int c[N << 1];
int dp[N][1<<11], mx[N][11][1<<11], res[N];

int main() {
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i].first);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i].second);
	for (int i = 1; i <= n; i ++) 
		if (i <= n + 1 - i) swap(a[i], a[n + 1 - i]);
	for (int i = 1; i <= n + m; i ++) scanf("%d", &c[i]);

	for (int i = 0; i < N; i ++) {
		res[i] = - inf;
		for (int j = 0; j < 1<<11; j ++) {
			for (int k = 0; k < 11; k ++) mx[i][k][j] = -inf;
			dp[i][j] = -inf;
		}
	}
	dp[0][0] = 0; res[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 1 << 11; j ++) {
			if (j == 0) {
				dp[i][0] = max(dp[i][0], 0);
				for (int k = 1; k < i; k ++) {
					if (a[i].first - a[k].first > 10) {
						dp[i][0] = max(dp[i][0], res[k]);
					}
				}
			}
			if (j == 1) {
				dp[i][1] = max(dp[i][1], - a[i].second + c[a[i].first]);
				for (int k = 1; k < i; k ++) {
					if (a[i].first - a[k].first > 10) {
						dp[i][1] = max(dp[i][1], res[k] - a[i].second + c[a[i].first]);
					}
				}
			}
			for (int val = a[i].first; val >= max(a[i].first - 10, 1); val --) {
				int dt = a[i].first - val;

				{
					int pre = (j << dt) & ((1 << 11) - 1);
					if ((pre >> dt) == j) {
						dp[i][j] = max(dp[i][j], mx[val][dt][pre]);
					}
				}
				if (j) {
					int pre = ((j - 1) << dt) & ((1 << 11) - 1);
					if ((pre >> dt) == (j-1)) {
						int tmp = mx[val][dt][pre] - a[i].second + c[a[i].first];
						int num = j - 1;
						for (int k = 0; num >> k & 1; k ++) {
							tmp += c[a[i].first + k + 1];
						}
						dp[i][j] = max(dp[i][j], tmp);
					}
				}
			}
		}
		for (int j = 0; j < 1 << 11; j ++) {
			int val = 0;
			for (int k = 10; k >= 0; k --) {
				if (j >> k & 1) val += (1<<k);
				mx[a[i].first][k][val] = max(mx[a[i].first][k][val], dp[i][j]);
			}
			res[i] = max(res[i], dp[i][j]);
			//if(dp[i][j] > -100) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
		}
		//printf("%d, %d\n", i, res[i]);
	}
	cout << (*max_element(res + 1, res + 1 + n)) << endl;
}