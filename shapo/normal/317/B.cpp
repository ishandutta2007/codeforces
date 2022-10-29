#include <cstdio>

#define maxn 135

int cnt[2][maxn][maxn];
int tm;
int res;
int i, j, l, r, t, b;
int nl, nr, nt, nb;

inline int min(int a, int b) {return (a < b) ? a : b;}
inline int max(int a, int b) {return (a > b) ? a : b;}

int ok(int tm) {
	res = 0;
	for (i = l; i <= r; ++i)
		for (j = t; j <= b; ++j)
			cnt[!tm][i][j] = cnt[tm][i][j];
	nt = t, nr = r, nl = l, nb = b;
	for (i = l; i <= r; ++i)
		for (j = t; j <= b; ++j)
			if (cnt[tm][i][j] >= 4) {
				cnt[!tm][i][j] -= 4;
				cnt[!tm][i + 1][j]++, cnt[!tm][i - 1][j]++,
				cnt[!tm][i][j + 1]++, cnt[!tm][i][j - 1]++;
				res = 1;
				nl = min(nl, i - 1), nr = max(nr, i + 1);
				nt = min(nt, j - 1), nb = max(nb, j + 1);
			}
	t = nt, b = nb, l = nl, r = nr;
	return res;
}

int main() {
	int n, q, x, y;
	scanf("%d%d", &n, &q);
	tm = 0;
	l = r = t = b = maxn / 2 - 1;
	cnt[tm][maxn / 2 - 1][maxn / 2 - 1] = n;
	while (ok(tm)) tm = !tm;
	for (i = 0; i < q; ++i) {
		scanf("%d%d", &x, &y);
		if (x + maxn / 2 - 1 >= 0 && x + maxn / 2 - 1 < maxn
			&& y + maxn / 2 - 1 >= 0 && y + maxn / 2 - 1 < maxn)
			printf("%d\n", cnt[tm][x + maxn / 2 - 1][y + maxn / 2 - 1]);
		else
			printf("0\n");
	}
	return 0;
}