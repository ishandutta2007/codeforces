#include <bits/stdc++.h>
using namespace std;

struct dat {
	int a, b, c;
	dat(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
	bool operator < (const dat &tmp) const {
		return a != tmp.a ? a < tmp.a : b != tmp.b ? b < tmp.b : c < tmp.c;
	}
};

#define N 500500

typedef long long ll;

int h;

struct segment_tree {

private:
	int n, a[N], mx[N<<2], reset[N<<2];
	ll sum[N<<2];

	void push_up(int id) {
		mx[id] = max(mx[id<<1], mx[id<<1^1]);
		sum[id] = sum[id<<1] + sum[id<<1^1];
	}

	void build(int l, int r, int id) {
		if (l == r) {
			mx[id] = a[l];
			sum[id] = a[l];
			return;
		}
		int m = l + r >> 1;
		build(l, m, id << 1);
		build(m + 1, r, id << 1 ^ 1);
		push_up(id);
	}

	void push_down(int l, int r, int id) {
		if (!reset[id]) return;
		mx[id<<1] = mx[id<<1^1] = reset[id];
		int m = l + r >> 1;
		sum[id<<1] = 1ll * reset[id] * (m - l + 1);
		sum[id<<1^1] = 1ll * reset[id] * (r - m);
		reset[id<<1] = reset[id<<1^1] = reset[id];
		reset[id] = 0;
	}

	void modify(int L, int R, int val, int l, int r, int id) {
		if (R < l || r < L) return;
		if (L <= l && r <= R) {
			mx[id] = val;
			sum[id] = 1ll * val * (r - l + 1);
			reset[id] = val;
			return;
		}
		push_down(l, r, id);
		int m = l + r >> 1;
		modify(L, R, val, l, m, id << 1);
		modify(L, R, val, m + 1, r, id << 1 ^ 1);
		push_up(id);
	}

	int get(int l, int r, int val, int id) {
		if (l == r) return l;
		push_down(l, r, id);
		int m = l + r >> 1;
		if (mx[id<<1^1] > val) return get(m + 1, r, val, id << 1 ^ 1);
		return get(l, m, val, id << 1);
	}

	ll query(int L, int R, int l, int r, int id) {
		if (R < l || r < L) return 0;
		if (L <= l && r <= R) return sum[id];
		push_down(l, r, id);
		int m = l + r >> 1;
		return query(L, R, l, m, id << 1) + query(L, R, m + 1, r, id << 1 ^ 1);
	}

public:
	void build(int *val, int sz) {
		n = sz;
		for (int i = 1; i <= n; i ++) a[i] = val[i];
		build(1, n, 1);
	}

	void update(int x, int val) {
		int y = 0;
		if (mx[1] > val) y = get(1, n, val, 1);
		modify(y + 1, x, val, 1, n, 1);
	}

	ll query(int x, int y) {
		if (x > n || y > h) return 0;
		int m = get(1, n, y - 1, 1);
		ll rlt = 1ll * (n - x + 1) * (h - y + 1);
		if (m < x) return rlt;
		rlt -= query(x, m, 1, n, 1) - 1ll * (m - x + 1) * (y - 1);
		return rlt;
	}
} T;

int n, p, q, r, mxb[N], mxc[N], val[N];
dat d[N];

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d %d", &n, &p, &q, &r);
	for (int i = 1; i <= n; i ++) scanf("%d %d %d", &d[i].a, &d[i].b, &d[i].c);
	d[++n] = dat(0, 0, 0);
	sort(d + 1, d + n + 1);
	for (int i = n; i >= 1; i --) {
		mxb[i] = max(mxb[i+1], d[i].b), mxc[i] = max(mxc[i+1], d[i].c);
	}
	for (int i = 1; i <= q; i ++) val[i] = 0;
	T.build(val, q);
	h = r;
	long long ans = 0;
	d[n+1].a = p;
	for (int i = 1; i <= n; i ++) {
		T.update(d[i].b, d[i].c);
		int len = d[i+1].a - d[i].a;
		if (!len) continue;
		ans += 1ll * len * T.query(mxb[i+1] + 1, mxc[i+1] + 1);
	}
	printf("%I64d\n", ans);
	return 0;
}