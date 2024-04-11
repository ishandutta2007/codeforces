#include <cstdio>

const int MAXN = 5E2 + 10;

char s[MAXN][MAXN];
int f[MAXN][MAXN], g[MAXN][MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			f[i][j] = f[i][j - 1] + (s[i][j] == '.' && j < m && s[i][j + 1] == '.');
			g[i][j] = g[i][j - 1] + (s[i][j] == '.' && i < n && s[i + 1][j] == '.');
		}
		for (int j = 1; j <= m; ++j){
			f[i][j] += f[i - 1][j];
			g[i][j] += g[i - 1][j];
		}
	}

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i){
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		--r1, --c1;
		printf("%d\n", f[r2][c2 - 1] + f[r1][c1] - f[r2][c1] - f[r1][c2 - 1]
					+ g[r2 - 1][c2] + g[r1][c1] - g[r2 - 1][c1] - g[r1][c2]);
	}
	return 0;
}