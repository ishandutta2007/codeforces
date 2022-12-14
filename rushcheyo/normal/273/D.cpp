#include <bits/stdc++.h>
using namespace std;

const int P = 1000000007;
const int N = 155;
typedef int mat[N][N];

int n, m;
mat dp[2][2], sum[2][2];

void add(int &x, int y) { x += y; if (x >= P) x -= P; }

int query(const mat &s, int r1, int r2, int c1, int c2) {
	if (r1 > r2 || c1 > c2) return 0;
	int ret = s[r2][c2];
	add(ret, P - s[r2][c1 - 1]);
	add(ret, P - s[r1 - 1][c2]);
	add(ret, s[r1 - 1][c1 - 1]);
	return ret;
}

void prefix() {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int l = 1; l <= m; l++)
				for (int r = 1; r <= m; r++) {
					int &a = sum[i][j][l][r];
					a = dp[i][j][l][r];
					add(a, sum[i][j][l - 1][r]), add(a, sum[i][j][l][r - 1]);
					add(a, P - sum[i][j][l - 1][r - 1]);
				}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int l = 1; l <= m; l++)
		for (int r = l; r <= m; r++)
			dp[0][0][l][r] = 1;
	int ans = n * (1 + m) * m / 2;
	for (int i = 2; i <= n; i++) {
		prefix();
		for (int l = 1; l <= m; l++)
			for (int r = l; r <= m; r++) {
				dp[0][0][l][r] = query(sum[0][0], l, r, l, r);
				int &a = dp[0][1][l][r];
				a = query(sum[0][0], l, r, r + 1, m);
				add(a, query(sum[0][1], l, r, r, m));
				int &b = dp[1][0][l][r];
				b = query(sum[0][0], 1, l - 1, l, r);
				add(b, query(sum[1][0], 1, l, l, r));
				int &c = dp[1][1][l][r];
				c = query(sum[0][0], 1, l - 1, r + 1, m);
				add(c, query(sum[0][1], 1, l - 1, r, m));
				add(c, query(sum[1][0], 1, l, r + 1, m));
				add(c, query(sum[1][1], 1, l, r, m));
				int tot = 0;
				for (int p = 0; p < 2; p++)
					for (int q = 0; q < 2; q++)
						add(tot, dp[p][q][l][r]);
				ans = (ans + (n - i + 1ll) * tot) % P;
			}
	}
	printf("%d\n", ans);
}