#include <cstdio>
#include <cstring>

const int MAXN = 1E3 + 10;
const int d[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int n, m, tot;
char s[MAXN][MAXN];
int vis[MAXN][MAXN];
int size[MAXN * MAXN];

bool inRange(int x, int y){
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

void BFS(int sx, int sy, int stamp){
	static int que[MAXN * MAXN][2];
	int l = 0, r = 1;
	int x0, y0, x, y;
	que[0][0] = sx;
	que[0][1] = sy;
	vis[sx][sy] = stamp;
	for (; l < r; ++l){
		x0 = que[l][0], y0 = que[l][1];
		for (int i = 0; i < 4; ++i){
			x = x0 + d[i][0], y = y0 + d[i][1];
			if (inRange(x, y) && s[x][y] == '.' && !vis[x][y]){
				que[r][0] = x;
				que[r][1] = y;
				vis[x][y] = stamp;
				++r;
			}
		}
	}
	size[stamp] = r;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", s[i] + 1);
	tot = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == '.' && !vis[i][j])
				BFS(i, j, ++tot);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] != '.'){
				int rec[4], cnt = 1;
				for (int k = 0; k < 4; ++k){
					int x = i + d[k][0], y = j + d[k][1];
					rec[k] = vis[x][y];
					cnt += size[rec[k]];
					for (int l = 0; l < k; ++l)
						if (rec[k] == rec[l]){
							cnt -= size[rec[k]];
							break;
						}
				}
				s[i][j] = '0' + cnt % 10;
			}
	for (int i = 1; i <= n; ++i)
		puts(s[i] + 1);
	return 0;
}