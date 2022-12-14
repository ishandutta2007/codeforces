#include <bits/stdc++.h>
using namespace std;
#define M 2555

int n;
int a[M][M];
bitset<M> R[M], C[M], T;

struct pnt{
	int v, x, y;
	pnt(int v = 0, int x = 0, int y = 0) : v(v), x(x), y(y){}
}p[M*M];
int cnt;
bool operator<(pnt a, pnt b) {
	return a.v != b.v ? a.v < b.v : a.x != b.x ? a.x < b.x : a.y < b.y;
}

bool solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] != a[j][i]) {
				return 0;
			}
			if (i == j && a[i][j]) {
				return 0;
			}
		}
	}
	for (int j, i = 0; i < cnt; i = j) {
		for (j = i; j < cnt && p[j].v == p[i].v; j++);
		for (int k = i; k < j; k++) {
			int x = p[k].x, y = p[k].y, v = p[k].v;
			T = R[x] & C[y];
			if (T.count()) {
				return 0;
			}
		}
		for (int k = i; k < j; k++) {
			int x = p[k].x, y = p[k].y, v = p[k].v;
			R[x][y] = 1;
			C[y][x] = 1;
		}
	}
	return 1;
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			p[cnt++] = pnt(a[i][j], i, j);
		}
	}
	sort(p, p + cnt);
	puts(solve() ? "MAGIC" : "NOT MAGIC");
	return 0;
}