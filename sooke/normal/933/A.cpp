#include <cstdio>
#include <cstring>
#define Max(x, y) ((x) > (y) ? (x) : (y))
#define Maxn 2005

int n, ans = 0, u[2][2][Maxn][Maxn], d[2][2][Maxn][Maxn];
bool a[Maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int t;
		scanf("%d", &t);
		a[i] = t == 2;
	}
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			u[0][0][i][i] = 0;
			u[0][1][i][i] = 0;
			u[1][1][i][i] = 1;
			d[0][0][i][i] = 0;
			d[1][0][i][i] = 1;
			d[1][1][i][i] = 1;
		} else {
			u[0][0][i][i] = 1;
			u[0][1][i][i] = 1;
			u[1][1][i][i] = 0;
			d[0][0][i][i] = 1;
			d[1][0][i][i] = 0;
			d[1][1][i][i] = 0;
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[j]) { 
				u[0][0][i][j] = u[0][0][i][j - 1];
				u[0][1][i][j] = Max(u[0][0][i][j - 1], u[0][1][i][j - 1]) + 1;
				u[1][1][i][j] = u[1][1][i][j - 1] + 1;
				d[0][0][i][j] = d[0][0][i][j - 1];
				d[1][0][i][j] = Max(d[1][1][i][j - 1], d[1][0][i][j - 1]);
				d[1][1][i][j] = d[1][1][i][j - 1] + 1;
			} else {
				u[0][0][i][j] = u[0][0][i][j - 1] + 1;
				u[0][1][i][j] = Max(u[0][0][i][j - 1], u[0][1][i][j - 1]);
				u[1][1][i][j] = u[1][1][i][j - 1];
				d[0][0][i][j] = d[0][0][i][j - 1] + 1;
				d[1][0][i][j] = Max(d[1][1][i][j - 1], d[1][0][i][j - 1]) + 1;
				d[1][1][i][j] = d[1][1][i][j - 1];
			}
		}
	}
	for (int i = 1 ; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int _u = 0; _u <= 1; _u++) {
				for (int v = 0; v <= 1; v++) if(_u <= v) {
					for (int w = 0; w <= 1; w++) if(v >= w) {
						for (int x = 0; x <= 1; x++) if(w >= x) {
							for (int y = 0; y <= 1; y++) if(x <= y) {
								for (int z = 0; z <= 1; z++) if(y <= z) {
									ans = Max(ans, u[_u][v][1][i] + d[w][x][i + 1][j] + d[y][z][j + 1][n]);
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

// By Sooke.
// CF933A A Twisty Movement.