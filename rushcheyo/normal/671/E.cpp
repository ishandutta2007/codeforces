#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100005;
const ll inf = 1ll << 60;
int n, k, w[N], g[N], st[N], top;
ll cl[N], cr[N], add[N * 3], mna[N * 3], mnb[N * 3];

void pushup(int u) {
	mnb[u] = min(mnb[u << 1], mnb[u << 1 | 1]);
}
void build(int u, int l, int r) {
	mnb[u] = inf;
	if (l == r) {
		mna[u] = cr[l];
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	mna[u] = min(mna[u << 1], mna[u << 1 | 1]);
	pushup(u);
}
void push(int u, ll v) {
	mnb[u] += v, add[u] += v;
}
void pushdown(int u) {
	if (add[u]) {
		push(u << 1, add[u]);
		push(u << 1 | 1, add[u]);
		add[u] = 0;
	}
}
void update(int u, int l, int r, int ql, int qr, ll v) {
	if (l >= ql && r <= qr) { push(u, v); return; }
	int mid = l + r >> 1;
	pushdown(u);
	if (ql <= mid) update(u << 1, l, mid, ql, qr, v);
	if (qr > mid) update(u << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(u);
}
void update(int u, int l, int r, int pos) {
	if (l == r) {
		mnb[u] = cr[l];
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (pos <= mid) update(u << 1, l, mid, pos);
	else update(u << 1 | 1, mid + 1, r, pos);
	pushup(u);
}
int query(int u, int l, int r, int ql, int qr, ll mn) {
	if (ql > qr || ql > r || qr < l) return 0;
	if (l == r) return l;
	int mid = l + r >> 1;
	pushdown(u);
	if (mna[u << 1 | 1] - min(mn, mnb[u << 1]) <= k) {
		int tmp = query(u << 1 | 1, mid + 1, r, ql, qr, min(mn, mnb[u << 1]));
		if (tmp) return tmp;
	}
	return query(u << 1, l, mid, ql, qr, mn);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; ++i) cin >> w[i];
	for (int i = 1; i <= n; ++i) cin >> g[i];
	for (int i = 1; i <= n; ++i) cl[i] = cl[i - 1] + g[i - 1] - w[i - 1], cr[i] = cr[i - 1] - g[i] + w[i - 1];
	build(1, 1, n);
	int ans = 0;
	for (int i = n; i; --i) {
		update(1, 1, n, i);
		while (top && cl[i] <= cl[st[top]]) {
			if (top > 1) update(1, 1, n, st[top - 1] - 1, n, cl[st[top]] - cl[st[top - 1]]);
			--top;
		}
		st[++top] = i;
		if (top > 1) update(1, 1, n, st[top - 1] - 1, n, cl[st[top - 1]] - cl[i]);
		int l = 1, r = top;
		while (l < r) {
			int mid = l + r >> 1;
			if (cl[i] - cl[st[mid]] <= k) r = mid;
			else l = mid + 1;
		}
		ans = max(ans, query(1, 1, n, i, (r == 1 ? n : st[r - 1] - 1), inf) - i + 1);
	}
	cout << ans << endl;
}