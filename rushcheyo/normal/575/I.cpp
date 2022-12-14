#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
int n, m, tot, t[3][2 * 5005], ans[6 * N];
struct node {
	int op, x, y1, y2, v, id;
} q[6 * N];
bool operator<(const node &a, const node &b) {
	return a.x < b.x || (a.x == b.x && a.op < b.op);
}
 
void rect(int t, int y1, int y2, int x1, int x2, int v) {
	if (y1 > y2 || x1 > x2) return;
	q[++tot] = {t, x1, y1, y2, v};
	q[++tot] = {t, x2 + 1, y1, y2, -v};
}
 
void dir1(int a, int b, int len, int v) {
	rect(2, 1, a + b + len, b, b + len, v);
	rect(1, 1, a - 1, b, b + len, -v);
}
void dir2(int a, int b, int len, int v) {
	rect(3, 1, a + len - b + n, b - len, b, v);
	rect(1, 1, a - 1, b - len, b, -v);
}
 
void upd(int *t, int x, int y) {
	for (; x; x &= x - 1) t[x] += y;
}
int qry(int *t, int x) {
	int s = 0; for (; x <= 2 * n; x += x & -x) s += t[x]; return s;
}
void solve(int l, int r) {
	if (l == r) { q[l].id = l; return; }
	int mid = l + r >> 1;
	solve(l, mid);
	solve(mid + 1, r);
	inplace_merge(q + l, q + mid + 1, q + r + 1);
	for (int i = l; i <= r; ++i) {
		if (q[i].id <= mid && q[i].op <= 3)
			upd(t[q[i].op - 1], q[i].y2, q[i].v), upd(t[q[i].op - 1], q[i].y1 - 1, -q[i].v);
		if (q[i].id > mid && q[i].op == 4)
			ans[q[i].id] += qry(t[0], q[i].y1) + qry(t[1], q[i].y1 + q[i].x) + qry(t[2], q[i].y1 - q[i].x + n);
	}
	for (int i = l; i <= r; ++i)
		if (q[i].id <= mid && q[i].op <= 3)
			upd(t[q[i].op - 1], q[i].y2, -q[i].v), upd(t[q[i].op - 1], q[i].y1 - 1, q[i].v);
}
 
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int dir, a, b, len;
			scanf("%d%d%d%d", &dir, &a, &b, &len);
			if (dir == 1) dir1(a, b, len, 1);
			else if (dir == 2) dir2(a, b, len, 1);
			else if (dir == 3) rect(1, a - len, a, b, b + len, 1), dir2(a - len, b + len, len - 1, -1);
			else rect(1, a - len, a, b - len, b, 1), dir1(a - len, b - len, len - 1, -1);
		} else {
			int x, y;
			scanf("%d%d", &x, &y);
			q[++tot] = {4, y, x};
		}
	}
	solve(1, tot);
	sort(q + 1, q + 1 + tot, [](const node &a, const node &b) { return a.id < b.id; });
	for (int i = 1; i <= tot; ++i) if (q[i].op == 4) printf("%d\n", ans[i]);
	return 0;
}