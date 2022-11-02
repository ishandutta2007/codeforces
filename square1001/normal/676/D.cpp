#include <queue>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 }, inf = 1012345678;
int H, W, sx, sy, gx, gy, dist[1009][1009][4]; bool b[1009][1009][4]; char s[1009], e[] = "*^> v| L< -D RU+";
struct state { int x, y, d; };
int main() {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		scanf("%s", s);
		for (int j = 0; j < W; j++) {
			for (int k = 0; k < 16; k++) {
				if (s[j] == e[k]) {
					for (int l = 0; l < 4; l++) {
						if (k & (1 << l)) b[i][j][l] = true;
						dist[i][j][l] = inf;
					}
				}
			}
		}
	}
	scanf("%d %d %d %d", &sx, &sy, &gx, &gy); sx--, sy--, gx--, gy--;
	queue<state> que; que.push(state{ sx, sy, 0 }); dist[sx][sy][0] = 0;
	while (!que.empty()) {
		state u = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			int tx = u.x + dx[i], ty = u.y + dy[i];
			if (0 <= tx && tx < H && 0 <= ty && ty < W && b[u.x][u.y][(i - u.d) & 3] && b[tx][ty][(i - u.d + 2) & 3] && dist[tx][ty][u.d] == inf) {
				dist[tx][ty][u.d] = dist[u.x][u.y][u.d] + 1;
				que.push(state{ tx, ty, u.d });
			}
		}
		if (dist[u.x][u.y][(u.d + 1) & 3] == inf) {
			dist[u.x][u.y][(u.d + 1) & 3] = dist[u.x][u.y][u.d] + 1;
			que.push(state{ u.x, u.y, (u.d + 1) & 3 });
		}
	}
	int ret = *min_element(dist[gx][gy], dist[gx][gy] + 4);
	printf("%d\n", ret == inf ? -1 : ret);
	return 0;
}