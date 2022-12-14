#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 18;
int n, t, Q, p[N], q[N], cnt[N], leaf[N];
pair<double, int> add[N << 1], del[N << 1];
double sum[N << 1];

void pushup(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	add[u] = max(add[u << 1], add[u << 1 | 1]);
	del[u] = max(del[u << 1], del[u << 1 | 1]);
}
void build(int u, int l, int r) {
	if (l == r) {
		add[u] = {p[l] / (1. + q[l]), l};
		del[u] = {-1e10, l};
		leaf[l] = u;
		return;
	}
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(int pos) {
	int u = leaf[pos];
	sum[u] = p[pos] * min(0.5, 1. * cnt[pos] / (cnt[pos] + q[pos]));
	add[u].first = p[pos] * min(0.5, (cnt[pos] + 1.) / (cnt[pos] + 1 + q[pos])) - sum[u];
	del[u].first = !cnt[pos] ? -1e10 : p[pos] * min(0.5, (cnt[pos] - 1.) / (cnt[pos] - 1 + q[pos])) - sum[u];
	while (u >>= 1) pushup(u);
}

int main() {
	scanf("%d%d%d", &n, &t, &Q);
	for (int i = 1; i <= n; ++i) scanf("%d", p + i);
	for (int i = 1; i <= n; ++i) scanf("%d", q + i);
	build(1, 1, n);
	while (t--) {
		int pos = add[1].second;
		++cnt[pos];
		modify(pos);
	}
	for (int x, y; Q--;) {
		scanf("%d%d", &x, &y);
		if (x == 1) ++q[y];
		else --q[y];
		modify(y);
		while (add[1].first + del[1].first > 0) {
			int a = add[1].second, b = del[1].second;
			++cnt[a], --cnt[b];
			modify(a), modify(b);
		}
		printf("%.9lf\n", sum[1]);
	}
}