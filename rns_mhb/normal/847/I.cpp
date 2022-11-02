#include <bits/stdc++.h>
using namespace std;

#define N 303

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

long long a[N][N];
int n, m, p, q;
char s[N][N];

bool ok(int &i, int &j) {
	if (i > n || i < 1 || j > m || j < 1) return 0;
	return s[i][j] != '*';
}

int vis[N][N], cnt;

int x[N*N], y[N*N], add[N*N];

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d %d %d\n", &n, &m, &q, &p);
	for (int i = 1; i <= n; i ++) gets(s[i] + 1);
	for (int ii = 1; ii <= n; ii ++) for (int jj = 1; jj <= m; jj ++) {
		if (s[ii][jj] >= 'A' && s[ii][jj] <= 'Z') {
			cnt ++;
			int now = (s[ii][jj] - 'A' + 1) * q;
			int e = 0;
			x[++e] = ii, y[e] = jj, vis[ii][jj] = cnt, add[e] = now;
			for (int f = 1, i, j, g, h; f <= e; f ++) {
				i = x[f], j = y[f];
				if (!add[f]) break;
				for (int k = 0; k < 4; k ++) {
					g = i + dx[k], h = j + dy[k];
					if (ok(g, h) && vis[g][h] != cnt) {
						x[++e] = g, y[e] = h, vis[g][h] = cnt, add[e] = add[f] / 2;
					}
				}
			}
			for (int i = 1; i <= e; i ++) a[x[i]][y[i]] += add[i];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (a[i][j] > p) ans ++;
	printf("%d\n", ans);

	return 0;
}