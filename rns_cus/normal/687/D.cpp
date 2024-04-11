#include <bits/stdc++.h>
using namespace std;
#define N 1010

struct edge {
	int x, y, w, id;
	bool operator < (const edge &b) const {return w > b.w;}
} e[N*N];

int n, m, q, l, r, root[N], d[N];

int find_root(int h) {
	if (h == root[h]) return h;
	int x = root[h];
	int y = find_root(x);
	d[h] = (d[h] + d[x]) % 2;
	return root[h] = y;
}

int solve() {
	for (int i = 1; i <= n; i ++) root[i] = i, d[i] = 0;
	for (int i = 1; i <= m; i ++) if (e[i].id >= l && e[i].id <= r) {
		int x = e[i].x, y = e[i].y;
		int a = find_root(x), b = find_root(y);
		if (a != b) {
			root[b] = a, d[b] = d[x] ^ d[y] ^ 1; continue;
		}
		if ((d[x] % 2) == (d[y] % 2)) return e[i].w;
	}
	return -1;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= m; i ++) scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].w), e[i].id = i;
	sort(e + 1, e + m + 1);
	while (q --) {
		scanf("%d %d", &l, &r);
		printf("%d\n", solve());
	}
	return 0;
}