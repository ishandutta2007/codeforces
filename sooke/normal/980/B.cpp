#include <cstdio>
#include <cstring>
#define Maxn 105

int n, m;
char g[5][Maxn];

int main() {
	scanf("%d%d", &n, &m);
	memset(g, '.', sizeof(g));
	if (m == 1) {
		g[2][n / 2 + 1] = '#';
	} else if (m & 1) {
		g[2][n / 2 + 1] = '#';
		m--;
		for (int i = n / 2; i >= 1; i--) {
			if (m == 0) {
				break;
			}
			for (int j = 2; j <= 3; j++) {
				m -= 2;
				g[j][i] = '#';
				g[j][n + 1 - i] = '#';
				if (m == 0) {
					break;
				}
			}
		}
	} else {
		for (int i = 2; i <= m / 2 + 1; i++) {
			g[2][i] = '#';
			g[3][i]	= '#';
		}
	}
	printf("YES\n");
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= n; j++) {
			putchar(g[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// By Sooke.
// CF980B Marlin.