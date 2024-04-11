#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 82;
int n, a[N], b[N], m, sum[N];
int dp[N][N * 2][N * N];

const int inf = 1e9;
void upd(int &x, int y) {
	x = min(x, y);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		//a[i] = rand() % 2;
	}	
	int B = n;
	int tot = 0;
	for (int i = 1; i <= n; i ++) if (a[i] == 0) ++ tot;

	vector<int> v;
	a[n + 1] = 1;
	for (int i = 1; i <= n + 1; i ++) {
		if (a[i] == 1) {
			int cnt = 0;
			int pos = i - 1;
			while (pos >= 1 && a[pos] == 0) {
				-- pos; cnt ++;
			}
			//printf("! %d %d\n", i, pos);
			v.push_back(cnt);
		}
	}

	for (int i = 0; i < v.size(); i ++) a[i + 1] = v[i];
	n = v.size();
	for (int i = 1; i <= n; i ++)
		sum[i] = sum[i-1] + a[i];

	//printf("# %d\n", n);

	for (int i = 0; i <= n; i ++) for (int j = 0; j < 2 * N; j ++) for (int k = 0; k <= B * (B - 1) / 2; k ++) dp[i][j][k] = inf;
	dp[1][B][0] = 0;
	for (int i = 1; i < n; i ++) {
		int lef = sum[i], rig = sum[n] - sum[i];
		int plef = sum[i-1], prig = sum[n] - sum[i-1];
		// i - i + 1
		for (int j = - prig; j <= plef; j ++) {
			for (int s = 0; s <= B * (B - 1) / 2; s ++) {
				
				if (dp[i][j+B][s] < inf) {
					//printf("dp[%d][%d][%d] = %d\n", i,j,s,dp[i][j+B][s]);
					// a[i] + j - x >= 0
					//printf("x in [%d, %d]\n", -rig, a[i] + j);
					for (int x = - rig; x <= a[i] + j; x ++) {
						int c = a[i] + j - x;
						if (s + abs(x) <= B*(B-1)/2)
						upd(dp[i+1][x+B][s+abs(x)], dp[i][j+B][s] + c * (c-1) / 2);
					}
				}
			}
		}
	}
	int pre = -inf;
	for (int i = 0; i <= B * (B - 1) / 2; i ++) {
		int ans = inf;
		int lef = sum[n-1], rig = sum[n] - sum[n-1];
		for (int j = - rig; j <= lef; j ++)
			if (a[n] + j >= 0)
				ans = min(ans, dp[n][j + B][i] + (a[n] + j) * (a[n] + j - 1) / 2);
		
		pre = max(pre, tot * (tot - 1) / 2 - ans);
		printf("%d ", pre);
	}
}