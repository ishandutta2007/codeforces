#include <bits/stdc++.h>

using namespace std;

const int N = 300005, inf = 0x3f3f3f3f;
int n, a[N], tag[N << 2], mn[N << 2], mn_cnt[N << 2];

void upd(int u, int v) {
	mn[u] += v, tag[u] += v;
}
void pushdown(int u) {
	if (tag[u]) {
		upd(u << 1, tag[u]);
		upd(u << 1 | 1, tag[u]);
		tag[u] = 0;
	}
}
void pushup(int u) {
	mn[u] = min(mn[u << 1], mn[u << 1 | 1]);
	mn_cnt[u] = 0;
	if (mn[u] == mn[u << 1])
		mn_cnt[u] = mn_cnt[u << 1];
	if (mn[u] == mn[u << 1 | 1])
		mn_cnt[u] += mn_cnt[u << 1 | 1];
}
void build(int u, int l, int r) {
	mn[u] = inf, mn_cnt[u] = r - l + 1;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}
void update(int u, int l, int r, int ql, int qr, int v) {
	if (l >= ql && r <= qr) {
		upd(u, v);
		return;
	}
	int mid = l + r >> 1;
	pushdown(u);
	if (ql <= mid)
		update(u << 1, l, mid, ql, qr, v);
	if (qr > mid)
		update(u << 1 | 1, mid + 1, r, ql, qr, v);
	pushup(u);
}

int main() {
	scanf("%d", &n);
	for (int i = 1, r; i <= n; ++i)
		scanf("%d", &r), scanf("%d", a + r);
	build(1, 1, n);
	static int st1[N], st2[N], top1, top2;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		update(1, 1, n, i, i, -inf);
		update(1, 1, n, 1, i, -1);
		for (; top1 && a[i] >= a[st1[top1]]; --top1)
			update(1, 1, n, st1[top1 - 1] + 1, st1[top1], -a[st1[top1]]);
		update(1, 1, n, st1[top1] + 1, i, a[i]);
		st1[++top1] = i;
		for (; top2 && a[i] <= a[st2[top2]]; --top2)
			update(1, 1, n, st2[top2 - 1] + 1, st2[top2], a[st2[top2]]);
		update(1, 1, n, st2[top2] + 1, i, -a[i]);
		st2[++top2] = i;
		if (mn[1] == -1)
			ans += mn_cnt[1];
	}
	printf("%lld\n", ans);
	return 0;
}