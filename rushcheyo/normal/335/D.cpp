#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned uint;

uint Rand() {
	static uint x = 19260817;
	return x ^= x << 13, x ^= x >> 17, x ^= x << 5;
}

const int N = 100005, M = 3005;
int n, x1[N], y1[N], x2[N], y2[N], ans[N], tot, sz[M][M];
vector<int> len[M];
uint v[M][M], s[M][M];

uint getxor(int x1, int y1, int x2, int y2) {
	return s[x2][y2] ^ s[x1][y2] ^ s[x2][y1] ^ s[x1][y1];
}

int getarea(int x1, int y1, int x2, int y2) {
	return sz[x2][y2] - sz[x1][y2] - sz[x2][y1] + sz[x1][y1];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 3000; i++)
		for (int j = 1; j <= 3000; j++) {
			s[i][j] = v[i][j] = Rand();
			s[i][j] ^= s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1];
		}
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", x1 + i, y1 + i, x2 + i, y2 + i);
		len[x1[i]].push_back(y1[i]);
		len[x1[i]].push_back(y2[i]);
		len[x2[i]].push_back(y1[i]);
		len[x2[i]].push_back(y2[i]);
		for (int x = x1[i] + 1; x <= x2[i]; x++)
			for (int y = y1[i] + 1; y <= y2[i]; y++)
				sz[x][y] = 1;
		int x = x1[i] + 1 + Rand() % (x2[i] - x1[i]),
			y = y1[i] + 1 + Rand() % (y2[i] - y1[i]);
		v[x][y] ^= getxor(x1[i], y1[i], x2[i], y2[i]);
	}
	for (int i = 0; i <= 3000; i++) {
		sort(len[i].begin(), len[i].end());
		len[i].erase(unique(len[i].begin(), len[i].end()), len[i].end());
		if (i == 0) continue;
		for (int j = 1; j <= 3000; j++) {
			s[i][j] = v[i][j] ^ s[i - 1][j] ^ s[i][j - 1] ^ s[i - 1][j - 1];
			sz[i][j] += sz[i - 1][j] + sz[i][j - 1] - sz[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		int x = x1[i], y = y1[i];
		for (auto l : len[x]) {
			int j = l - y;
			if (x + j > 3000) break;
			if (j <= 0) continue;
			if (getarea(x, y, x + j, y + j) < j * j) break;
			if (!getxor(x, y, x + j, y + j)) {
				for (int k = 1; k <= n; k++)
					if (x1[k] >= x && y1[k] >= y && x2[k] <= x + j &&
						y2[k] <= y + j)
					ans[++tot] = k;
				printf("YES %d\n", tot);
				for (int i = 1; i <= tot; i++)
					printf("%d%c", ans[i], " \n"[i == tot]);
				return 0;
			}
		}
	}
	puts("NO");
}