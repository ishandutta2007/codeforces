#include <bits/stdc++.h>

using namespace std;

int mp[505][505][4];
int dp[10][505][505];

const int inf = 0x3f3f3f3f;
const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	memset(mp, 63, sizeof mp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m - 1; ++j) {
			int p;
			scanf("%d", &p);
			mp[i][j][1] = mp[i][j + 1][3] = p;
		}
	}
	for (int i = 1; i <= n - 1; ++i) {
		for (int j = 1; j <= m; ++j) {
			int p;
			scanf("%d", &p);
			mp[i][j][2] = mp[i + 1][j][0] = p;
		}
	}
	if (k % 2) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int l = 1; l <= m; ++l) {
				int f = inf;
				for (int i1 = 0; i1 < 4; ++i1) {
					f = min(f, dp[i - 1][j + dir[i1][0]][l + dir[i1][1]] + 2 * mp[j][l][i1]);
				}
				dp[i][j][l] = f;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", dp[k][i][j]);
		}
		printf("\n");
	}
	return 0;
}