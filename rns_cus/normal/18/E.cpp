#include <bits/stdc++.h>
using namespace std;
#define N 505
#define M 27
#define inf 1e9

int n, m, f[N][M][M], bf1[N][M][M], bf2[N][M][M], prt1[N], prt2[N];
char s[N][N];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	for (int i = 0; i < n; i ++) {
		for (int a = 0; a < 26; a ++) {
			for (int b = 0; b < 26; b ++) if (b != a) {
				f[i][a][b] = inf;
				int add = 0;
				for (int j = 0; j < m; j ++) {
					if (j & 1) {
						if (s[i][j] != 'a' + b) add ++;
					}
					else {
						if (s[i][j] != 'a' + a) add ++;
					}
				}
				if (!i) {
					f[i][a][b] = add; continue;
				}
				for (int c = 0; c < 26; c ++) if (c != a) {
					for (int d = 0; d < 26; d ++) if (d != c && d != b) {
						if (f[i][a][b] > f[i-1][c][d] + add) {
							f[i][a][b] = f[i-1][c][d] + add;
							bf1[i][a][b] = c, bf2[i][a][b] = d;
						}
					}
				}
			}
		}
	}
	int ans = inf, A, B;
	for (int a = 0; a < 26; a ++) {
		for (int b = 0; b < 26; b ++) if (b != a) {
			if (ans > f[n-1][a][b]) {
				ans = f[n-1][a][b];
				A = a, B = b;
			}
		}
	}
	prt1[n-1] = A, prt2[n-1] = B;
	for (int i = n - 2; i >= 0; i --) {
		prt1[i] = bf1[i+1][A][B], prt2[i] = bf2[i+1][A][B];
		A = prt1[i], B = prt2[i];
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (j & 1) printf("%c", 'a' + prt2[i]);
			else printf("%c", 'a' + prt1[i]);
		}
		puts("");
	}
	return 0;
}
//18-e