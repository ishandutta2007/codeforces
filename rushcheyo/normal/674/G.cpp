#include <bits/stdc++.h>
using namespace std;

const int N = 150005;
int n, m, k, tag[N << 2];
struct arr {
	pair<int, int> dat[5];
	int size;
	arr() { size = 0; }
	const pair<int, int> &operator[](int x) const { return dat[x]; }
	pair<int, int> &operator[](int x) { return dat[x]; }
	void push_back(const pair<int, int> &p) { dat[size++] = p; }
};
arr T[N << 2];

void merge(arr &a, pair<int, int> b) {
	for (int i = 0; i < a.size; ++i)
		if (a[i].first == b.first) {
			a[i].second += b.second;
			return;
		}
	if (a.size < k) {
		a.push_back(b);
		return;
	}
	int mn = b.second;
	for (int i = 0; i < a.size; ++i)
		mn = min(mn, a[i].second);
	arr t;
	for (int i = 0; i < a.size; ++i)
		if (a[i].second -= mn) t.push_back(a[i]);
	if (b.second -= mn) t.push_back(b);
	a = t;
}
arr merge(arr a, const arr &b) {
	for (int i = 0; i < b.size; ++i) merge(a, b[i]);
	return a;
}
void pushup(int u) {
	T[u] = merge(T[u << 1], T[u << 1 | 1]);
}
void upd(int u, int l, int r, int x) {
	tag[u] = x;
	T[u].size = 1, T[u][0] = {x, r - l + 1};
}
void pushdown(int u, int l, int r, int mid) {
	if (tag[u]) {
		upd(u << 1, l, mid, tag[u]);
		upd(u << 1 | 1, mid + 1, r, tag[u]);
		tag[u] = 0;
	}
}
void build(int u, int l, int r) {
	if (l == r) {
		int x;
		scanf("%d", &x);
		T[u].size = 1, T[u][0] = {x, 1};
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void update(int u, int l, int r, int ql, int qr, int x) {
	if (l >= ql && r <= qr) {
		upd(u, l, r, x);
		return;
	}
	int mid = l + r >> 1;
	pushdown(u, l, r, mid);
	if (ql <= mid) update(u << 1, l, mid, ql, qr, x);
	if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, x);
	pushup(u);
}
arr query(int u, int l, int r, int ql, int qr) {
	if (l >= ql && r <= qr) return T[u];
	int mid = l + r >> 1;
	pushdown(u, l, r, mid);
	if (qr <= mid) return query(u << 1, l, mid, ql, qr);
	if (ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
	return merge(query(u << 1, l, mid, ql, qr), query(u << 1 | 1, mid + 1, r, ql, qr));
}

int main() {
	scanf("%d%d%d", &n, &m, &k), k = 100 / k;
	build(1, 1, n);
	for (int op, l, r, x; m--;) {
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1) {
			scanf("%d", &x);
			update(1, 1, n, l, r, x);
		} else {
			auto ans = query(1, 1, n, l, r);
			printf("%d", ans.size);
			for (int i = 0; i < ans.size; ++i) printf(" %d", ans[i].first);
			puts("");
		}
	}
}