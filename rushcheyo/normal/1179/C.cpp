#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, m, q, a[N], b[N], tag[N << 2], mn[N << 2];

void pushup(int x) { mn[x] = min(mn[x << 1], mn[x << 1 | 1]); }
void upd(int x, int v) { tag[x] += v, mn[x] += v; }
void pushdown(int x) {
	if (tag[x]) {
		upd(x << 1, tag[x]);
		upd(x << 1 | 1, tag[x]);
		tag[x] = 0;
	}
}
void update(int x, int l, int r, int ql, int qr, int v) {
	if (l >= ql && r <= qr) { upd(x, v); return; }
	int mid = l + r >> 1;
	pushdown(x);
	if (ql <= mid) update(x << 1, l, mid, ql, qr, v);
	if (qr > mid) update(x << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(x);
}
int query(int x, int l, int r) {
	if (l == r) return l;
	int mid = l + r >> 1;
	pushdown(x);
	if (mn[x << 1 | 1] < 0) return query(x << 1 | 1, mid + 1, r);
	return query(x << 1, l, mid);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		update(1, 0, 1000000, 0, a[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", b + i);
		update(1, 0, 1000000, 0, b[i], 1);
	}
	scanf("%d", &q);
	while (q--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			update(1, 0, 1000000, 0, a[x], 1);
			update(1, 0, 1000000, 0, a[x] = y, -1);
		} else {
			update(1, 0, 1000000, 0, b[x], -1);
			update(1, 0, 1000000, 0, b[x] = y, 1);
		}
		if (mn[1] >= 0)
			puts("-1");
		else
			printf("%d\n", query(1, 0, 1000000));
	}
}