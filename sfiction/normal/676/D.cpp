#include <cstdio>

const int MAXN = 1E3 + 10, MAXL = MAXN;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

char buf[MAXL];

int n, m;
int a[4][MAXN][MAXN];
int dis[4][MAXN][MAXN];
int que[MAXN * MAXN << 2][3];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%s", buf + 1);
		for (int j = 1; j <= m; ++j){
			a[0][i][j] = buf[j] == '+' ? 15 :
							buf[j] == '-' ? 10 :
							buf[j] == '|' ? 5 :
							buf[j] == '^' ? 1 :
							buf[j] == '>' ? 2 :
							buf[j] == '<' ? 8 :
							buf[j] == 'v' ? 4 :
							buf[j] == 'L' ? 7 :
							buf[j] == 'R' ? 13 :
							buf[j] == 'U' ? 14 :
							buf[j] == 'D' ? 11 :
							buf[j] == '*' ? 0 : 0;
			a[1][i][j] = (a[0][i][j] << 1 | a[0][i][j] >> 3) & 15;
			a[2][i][j] = (a[1][i][j] << 1 | a[1][i][j] >> 3) & 15;
			a[3][i][j] = (a[2][i][j] << 1 | a[2][i][j] >> 3) & 15;
		}
	}
	int sx, sy, ex, ey, ans = -1;
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	que[0][0] = sx, que[0][1] = sy, que[0][2] = 0;
	dis[0][sx][sy] = 1;
	for (int l = 0, r = 1; l < r; ++l){
		int x0 = que[l][0], y0 = que[l][1], z0 = que[l][2];
//		printf("%d %d %d %d\n", x0, y0, z0, dis[z0][x0][y0]);
		if (x0 == ex && y0 == ey){
			ans = dis[z0][x0][y0] - 1;
			break;
		}
		for (int i = 0; i < 4; ++i){
			int x = x0 + d[i][0], y = y0 + d[i][1];
			if (!dis[z0][x][y] && a[z0][x0][y0] >> i & 1 && a[z0][x][y] >> (i ^ 2) & 1){
				dis[z0][x][y] = dis[z0][x0][y0] + 1;
				que[r][0] = x, que[r][1] = y, que[r][2] = z0;
				++r;
			}
		}

		int z = z0 + 1 & 3;
		if (!dis[z][x0][y0]){
			dis[z][x0][y0] = dis[z0][x0][y0] + 1;
			que[r][0] = x0, que[r][1] = y0, que[r][2] = z;
			++r;
		}
	}
	printf("%d\n", ans);
	return 0;
}