#include <bits/stdc++.h>
using namespace std;

int a[9];

#define N 111

char s[N][N];
char c[N];
int n, m;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	int sx, sy, ex, ey;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) {
		if (s[i][j] == 'S') sx = i, sy = j;
		if (s[i][j] == 'E') ex = i, ey = j;
	}
	scanf("%s", c);
	int k = strlen(c);
	for (int i = 1; i <= 4; i ++) a[i] = i;
	int cnt = 0;
	do {
		bool flag = 1;
		int x = sx, y = sy;
		for (int i = 0; i < k && flag; i ++) {
			int dir = a[c[i]-'0'+1] - 1;
			x += dx[dir], y += dy[dir];
			if (x <= 0 || x > n || y <= 0 || y > m || s[x][y] == '#') flag = 0;
			if (x == ex && y == ey) break;
		}
		if (x != ex || y != ey) flag = 0;
		if (flag) cnt ++;
	} while (next_permutation(a + 1, a + 5));
	printf("%d\n", cnt);

	return 0;
}