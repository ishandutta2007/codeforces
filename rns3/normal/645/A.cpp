#include <bits/stdc++.h>
using namespace std;
#define M 30
char s[M][M], ss[M][M];
int a[M][M], b[M][M];
int vis[1000010], p[M];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
//freopen("A.in", "r", stdin);
	for (int i = 0; i < 2; i++) scanf("%s", s[i]);
	for (int i = 0; i < 2; i++) scanf("%s", ss[i]);
	p[0] = 1; for (int i = 1; i < 5; i++) p[i] = 10 * p[i-1];

	int A = 0, B = 0;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
		if (s[i][j] == 'X') a[i][j] = 3; else a[i][j] = s[i][j] - 'A';
		if (ss[i][j] == 'X') b[i][j] = 3; else b[i][j] = ss[i][j] - 'A';
		A += a[i][j] * p[i*2+j]; B += b[i][j] * p[i*2+j];
	}
	queue <int> q;
	q.push(A); vis[A] = 1;
	int sx, sy;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == B) return puts("YES"), 0;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
			a[i][j] = x % 10, x /= 10; if (a[i][j] == 3) sx = i, sy = j;
		}
		for (int k = 0; k < 4; k++) {
			int xx = sx + dx[k], yy = sy + dy[k];
			if (xx < 0 || yy < 0 || xx >= 2 || yy >= 2) continue;
			memcpy(b, a, sizeof(b));
			swap(b[xx][yy], b[sx][sy]);
			int y = 0;
			for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) y += b[i][j] * p[i*2+j];
			if (!vis[y]) q.push(y), vis[y] = 1;
		}
	}
	puts("NO");
}