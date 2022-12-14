#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int q, n, dir, x, y;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		x = -1, y = 0, dir = 1;
		scanf("%d", &n);
		int grid[2][n];
		char c;
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < n; ++k) {
				scanf(" %c", &c);
				grid[j][k] = c - '0';
			}
		}
		while (true) {
			if (dir == 1) x += 1;
			else if (dir == 2) y += 1;
			else  y -= 1;
			if (grid[y][x] == 1 || grid[y][x] == 2);
			else {
				if (dir == 1) {
					if (y == 1) dir = 3;
					else dir = 2;
				} else dir = 1;
			}
			if (x == n && y == 1) break;
			else if (x == n) goto hell;
			else if (y < 0 || y > 1) goto hell;
		}
		printf("YES\n");
		goto heaven;
		hell: printf("NO\n");
		heaven:;
	}
	return 0;
}