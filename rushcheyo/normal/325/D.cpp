#include <bits/stdc++.h>
using namespace std;

const int M = 3005;
const int D[8][2] = {
	{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};
int r, c, n, fa[M * M * 2], vis[M * M * 2];
bool del[M][M * 2];

#define id(i, j) ((i - 1) * c * 2 + j)

int find(int x) { return fa[x] < 0 ? x : fa[x] = find(fa[x]); }
void unite(int x, int y) {
	int s = find(x), t = find(y);
	if (s == t) return;
	if (fa[s] < fa[t]) swap(s, t);
	fa[t] += fa[s];
	fa[s] = t;
}

void spread(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int s = x + D[i][0], t = y + D[i][1];
		if (s < 1 || s > r) continue;
		if (t < 1) t = 2 * c;
		if (t > 2 * c) t = 1;
		if (del[s][t]) unite(id(x, y), id(s, t));
	}
}

int main() {
	scanf("%d%d%d", &r, &c, &n);
	if (c == 1) return puts("0"), 0;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= 2 * c; j++) fa[id(i, j)] = -1;
	int ans = 0;
	for (; n; n--) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int i = 0; i < 8; i++) {
			int s = x + D[i][0], t = y + D[i][1];
			if (s < 1 || s > r) continue;
			if (t < 1) t = 2 * c;
			if (!del[s][t]) continue;
			int tmp = find(id(s, t));
			vis[tmp] = n;
		}
		bool flag = false;
		for (int i = 0; i < 8 && !flag; i++) {
			int s = x + D[i][0], t = y + c + D[i][1];
			if (s < 1 || s > r) continue;
			if (t < 1) t = 2 * c;
			if (t > 2 * c) t = 1;
			if (!del[s][t]) continue;
			int tmp = find(id(s, t));
			if (vis[tmp] == n) flag = true;
		}
		if (flag) continue;
		ans++;
		spread(x, y);
		spread(x, y + c);
		del[x][y] = del[x][y + c] = true;
	}
	printf("%d\n", ans);
}