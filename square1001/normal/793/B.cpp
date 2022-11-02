#include <cstdio>
#pragma warning(disable : 4996)
int H, W, sx, sy, gx, gy; char c[1009][1009];
bool solve1(int x, int ay, int by) {
	if (ay > by) ay ^= by, by ^= ay, ay ^= by;
	for (int i = ay; i <= by; i++) {
		if (c[x][i] == '*') return false;
	}
	return true;
}
bool solve2(int y, int ax, int bx) {
	if (ax > bx) ax ^= bx, bx ^= ax, ax ^= bx;
	for (int i = ax; i <= bx; i++) {
		if (c[i][y] == '*') return false;
	}
	return true;
}
int main() {
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; i++) {
		scanf("%s", c[i]);
		for (int j = 0; j < W; j++) {
			if (c[i][j] == 'S') sx = i, sy = j;
			if (c[i][j] == 'T') gx = i, gy = j;
		}
	}
	bool ret = false;
	for (int i = 0; i < H; i++) {
		// (sx, sy) -> (i, sy) -> (i, gy) -> (gx, gy)
		if (solve2(sy, sx, i) && solve1(i, sy, gy) && solve2(gy, i, gx)) ret = true;
	}
	for (int i = 0; i < W; i++) {
		// (sx, sy) -> (sx, i) -> (gx, i) -> (gx, gy)
		if (solve1(sx, sy, i) && solve2(i, sx, gx) && solve1(gx, i, gy)) ret = true;
	}
	printf(ret ? "YES\n" : "NO\n");
	return 0;
}