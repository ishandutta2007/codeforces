#include <stdio.h>
#include <string.h>

#define N 111

int n, m, color[N], stx[N], enx[N], sty[N], eny[N], vis[N][N], nei[N][N];
char c, s[N][N];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d %c", &n, &m, &c);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (s[i][j] == '.' || vis[i][j]) continue;
			color[++cnt] = s[i][j];
			stx[cnt] = i; sty[cnt] = j;
			for (int k = i; k < n; k ++) if (s[k][j] == s[i][j]) enx[cnt] = k;
			for (int k = j; k < m; k ++) if (s[i][k] == s[i][j]) eny[cnt] = k;
			for (int I = stx[cnt]; I <= enx[cnt]; I ++)
				for (int J = sty[cnt]; J <= eny[cnt]; J ++) vis[I][J] = 1;
		}
	}
	int king = 0;
	for (int i = 1; i <= cnt; i ++) if (color[i] == c) king = i;
	if (sty[king]) for (int i = stx[king]; i <= enx[king]; i ++) nei[i][sty[king]-1] = 1;
	if (eny[king] < m) for (int i = stx[king]; i <= enx[king]; i ++) nei[i][eny[king]+1] = 1;
	if (stx[king]) for (int j = sty[king]; j <= eny[king]; j ++) nei[stx[king]-1][j] = 1;
	if (enx[king] < n) for (int j = sty[king]; j <= eny[king]; j ++) nei[enx[king]+1][j] = 1;
	int ans = 0;
	for (int k = 1; k <= cnt; k ++) {
		bool ok = 0;
		for (int i = stx[k]; i <= enx[k]; i ++) {
			for (int j = sty[k]; j <= eny[k]; j ++) {
				if (nei[i][j]) {ok = 1; break;}
			}
			if (ok) break;
		}
		if (ok) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}