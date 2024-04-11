#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define L 10

int f[N][N][L][L], n, m, a[N][N], cons[L];
bool v[N][N];

void prep() {
	cons[0] = 1;
	for (int i = 1; i < L; i ++) cons[i] = cons[i-1] << 1;
    for (int i = 1; i <= n; i ++) a[i][m] = v[i][m];
    for (int j = 1; j <= m; j ++) a[n][j] = v[n][j];
    for (int i = n - 1; i >= 1; i --) for (int j = m - 1; j >= 1; j --) if (v[i][j]) {
		a[i][j] = min(min(a[i+1][j+1], a[i][j+1]), a[i+1][j]) + 1;
    }
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) f[i][j][0][0] = a[i][j];
    for (int p = 0; p < L; p ++) for (int q = 0; q < L; q ++) {
    	if (!p && !q) continue;
        for (int i = 1; i <= n - cons[p] + 1; i ++) for (int j = 1; j <= m - cons[q] + 1; j ++) {
			if (p) f[i][j][p][q] = max(f[i][j][p-1][q], f[i+cons[p-1]][j][p-1][q]);
			else f[i][j][p][q] = max(f[i][j][p][q-1], f[i][j+cons[q-1]][p][q-1]);
        }
    }
}

int func(int x, int y, int xx, int yy) {
	int p, q;
	p = 31 - __builtin_clz(xx - x + 1);
	q = 31 - __builtin_clz(yy - y + 1);
	int rlt = max(max(f[x][y][p][q], f[x][yy-cons[q]+1][p][q]), max(f[xx-cons[p]+1][y][p][q],f[xx-cons[p]+1][yy-cons[q]+1][p][q]));
	return rlt;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%d", &v[i][j]);
	prep();
	int x, y, xx, yy, T;
	scanf("%d", &T);
	while (T --) {
		scanf("%d %d %d %d", &x, &y, &xx, &yy);
		int st = 0, en = min(xx - x, yy - y) + 2, mid;
		while (st < en - 1) {
			mid = (st + en) / 2;
			if (func(x, y, xx - mid + 1, yy - mid + 1) >= mid) st = mid;
			else en = mid;
		}
        printf("%d\n", st);
	}
	return 0;
}