#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int h, w, x;
	scanf("%d %d", &h, &w);
	int val[h][w];
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) val[i][j] = -1;
	}
	for (int i = 0; i < h; ++i) {
		scanf("%d", &x);
		for (int j = 0; j < x; ++j) {
			if (val[i][j] == 0) {
				printf("0");
				return 0;
			} else val[i][j] = 1;
		}
		if (x == w) continue;
		else if (val[i][x] == 1) {
			printf("0");
			return 0;
		} else val[i][x] = 0;
	}
	for (int i = 0; i < w; ++i) {
		scanf("%d", &x);
		for (int j = 0; j < x; ++j) {
			if (val[j][i] == 0) {
				printf("0");
				return 0;
			} else val[j][i] = 1;
		}
		if (x == h) continue;
		else if (val[x][i] == 1) {
			printf("0");
			return 0;
		} else val[x][i] = 0;
	}
	int ans = 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (val[i][j] == -1) ans = (ans << 1) % 1000000007;
		}
	}
	printf("%d", ans);
	return 0;
}