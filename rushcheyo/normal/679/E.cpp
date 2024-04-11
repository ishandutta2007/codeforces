#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
int n, q;
ll val[N << 2], mn[N << 2], add[N << 2];

ll nxt(ll x) {
	ll y = 1;
	while (y < x) y *= 42;
	return y;
}
void push_add(int u, ll v) {
	mn[u] -= v, add[u] += v;
	if (val[u] != -1) val[u] += v;
}
void push_cov(int u, ll v, ll v_) {
	add[u] = 0, val[u] = v, mn[u] = v_;
}
void pushdown(int u) {
	if (add[u]) {
		push_add(u << 1, add[u]);
		push_add(u << 1 | 1, add[u]);
		add[u] = 0;
	}
	if (val[u] != -1) {
		push_cov(u << 1, val[u], mn[u]);
		push_cov(u << 1 | 1, val[u], mn[u]);
	}
}
void pushup(int u) {
	mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
	if (val[u << 1] == val[u << 1 | 1]) val[u] = val[u << 1];
	else val[u] = -1;
}
void build(int u, int l, int r) {
	if (l == r) {
		scanf("%lld", val + u);
		mn[u] = nxt(val[u]) - val[u];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
ll query(int u, int l, int r, int pos) {
	if (l == r) return val[u];
	int mid = l + r >> 1;
	pushdown(u);
	return pos <= mid ? query(u << 1, l, mid, pos) : query(u << 1 | 1, mid + 1, r, pos);
}
void cover(int u, int l, int r, int ql, int qr, ll v, ll v_) {
	if (l >= ql && r <= qr) {
		push_cov(u, v, v_);
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (ql <= mid) cover(u << 1, l, mid, ql, qr, v, v_);
	if (qr > mid) cover(u << 1 | 1, mid + 1, r, ql, qr, v, v_);
	pushup(u);
}
void update(int u, int l, int r, int ql, int qr, ll v) {
	if (l >= ql && r <= qr) {
		push_add(u, v);
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (ql <= mid) update(u << 1, l, mid, ql, qr, v);
	if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(u);
}
void dfs(int u, int l, int r) {
	if (mn[u] >= 0) return;
	if (val[u] != -1) {
		mn[u] = nxt(val[u]) - val[u];
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	dfs(u << 1, l, mid);
	dfs(u << 1 | 1, mid + 1, r);
	pushup(u);
}

int main() {
	scanf("%d%d", &n, &q);
	build(1, 1, n);
	for (int op; q--;) {
		scanf("%d", &op);
		if (op == 1) {
			int i;
			scanf("%d", &i);
			printf("%lld\n", query(1, 1, n, i));
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			if (op == 2) cover(1, 1, n, l, r, x, nxt(x) - x);
			else {
				do {
					update(1, 1, n, l, r, x);
					dfs(1, 1, n);
				} while (mn[1] <= 0);
			}
		}
	}
	return 0;
}