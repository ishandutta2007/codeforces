#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807LL
#define INF MAXINT
#define lol long long
#define lod long double

inline int read() {
	char c = getchar();
	int n = 0, f = 0;
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return f ? -n : n;
}

#define MAXN 200005
#define P 1000000007

int n, m, a[MAXN], v[MAXN];
lol ans;

struct SegmentTree {
	int siz, root[MAXN], lson[MAXN << 7], rson[MAXN << 7], sum[MAXN << 7];
	lol val[MAXN << 7];
	inline void pushUp(int u) {
		sum[u] = sum[lson[u]] + sum[rson[u]];
		val[u] = val[lson[u]] + val[rson[u]];
	}
	void modify(int &u, int l, int r, int p, int k, int kv) {
		if (u == 0) {
			u = ++siz;
		}
		if (l == r) {
			sum[u] += k;
			val[u] += kv;
		} else {
			int mid = l + r >> 1;
			if (p <= mid) {
				modify(lson[u], l, mid, p, k, kv);
			} else {
				modify(rson[u], mid + 1, r, p, k, kv);
			}
			pushUp(u);
		}
	}
	void querySum(int u, int l, int r, int pl, int pr, int &res) {
		if (u > 0) {
			if (l == pl && r == pr) {
				res += sum[u];
			} else {
				int mid = l + r >> 1;
				if (pr <= mid) {
					querySum(lson[u], l, mid, pl, pr, res);
				} else if (pl > mid) {
					querySum(rson[u], mid + 1, r, pl, pr, res);
				} else {
					querySum(lson[u], l, mid, pl, mid, res);
					querySum(rson[u], mid + 1, r, mid + 1, pr, res);
				}
			}
		}
	}
	void queryVal(int u, int l, int r, int pl, int pr, lol &res) {
		if (u > 0) {
			if (l == pl && r == pr) {
				res += val[u];
			} else {
				int mid = l + r >> 1;
				if (pr <= mid) {
					queryVal(lson[u], l, mid, pl, pr, res);
				} else if (pl > mid) {
					queryVal(rson[u], mid + 1, r, pl, pr, res);
				} else {
					queryVal(lson[u], l, mid, pl, mid, res);
					queryVal(rson[u], mid + 1, r, mid + 1, pr, res);
				}
			}
		}
	}
} tr;

void modify(int u, int p, int k, int kv) {
	for (int i = u; i <= n; i += LOWBIT(i)) {
		tr.modify(tr.root[i], 1, n, p, k, kv);
	}
}
int querySum(int l, int r, int pl, int pr) {
	int add = 0, del = 0;
	if (l <= r && pl <= pr) {
		for (int i = r; i >= 1; i ^= LOWBIT(i)) {
			tr.querySum(tr.root[i], 1, n, pl, pr, add);
		}
		for (int i = l - 1; i >= 1; i ^= LOWBIT(i)) {
			tr.querySum(tr.root[i], 1, n, pl, pr, del);
		}
	}
	return add - del;
}
lol queryVal(int l, int r, int pl, int pr) {
	lol add = 0, del = 0;
	if (l <= r && pl <= pr) {
		for (int i = r; i >= 1; i ^= LOWBIT(i)) {
			tr.queryVal(tr.root[i], 1, n, pl, pr, add);
		}
		for (int i = l - 1; i >= 1; i ^= LOWBIT(i)) {
			tr.queryVal(tr.root[i], 1, n, pl, pr, del);
		}
	}
	return add - del;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = i, v[i] = 1;
		modify(i, a[i], 1, v[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans += 1LL * querySum(i + 1, n, 1, a[i] - 1) * v[i] + queryVal(i + 1, n, 1, a[i] - 1);
		ans %= P;
	}
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		if (l != r) {
			if (l > r) {
				SWAP(l, r);
			}
			ans -= 1LL * querySum(l + 1, r - 1, 1, a[l] - 1) * v[l] + queryVal(l + 1, r - 1, 1, a[l] - 1);
			ans += 1LL * querySum(l + 1, r - 1, a[l] + 1, n) * v[l] + queryVal(l + 1, r - 1, a[l] + 1, n);
			ans -= 1LL * querySum(l + 1, r - 1, a[r] + 1, n) * v[r] + queryVal(l + 1, r - 1, a[r] + 1, n);
			ans += 1LL * querySum(l + 1, r - 1, 1, a[r] - 1) * v[r] + queryVal(l + 1, r - 1, 1, a[r] - 1);
			if (a[l] < a[r]) {
				ans += v[l] + v[r];
			} else {
				ans -= v[l] + v[r];
			}
			modify(l, a[l], -1, -v[l]);
			modify(r, a[r], -1, -v[r]);
			SWAP(a[l], a[r]);
			SWAP(v[l], v[r]);
			modify(l, a[l], 1, v[l]);
			modify(r, a[r], 1, v[r]);
		}
		printf("%I64d\n", ans >> 1);
	}
	return 0;
} //