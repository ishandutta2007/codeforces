#include <cstdio>
#include <algorithm>

using namespace std;

#define Inf 2147483647
#define Maxn 500005

inline int read() {
	char c = getchar();
	int n = 0;
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		n = (n << 1) + (n << 3) + (c ^ 48);
		c = getchar();
	}
	return n;
}

struct Que {
	int i, l, r;
};

bool Cmp(Que A, Que B) {
	return A.r < B.r;
}

Que Q[Maxn];
int n, m, res, _min, a[Maxn], pre[Maxn], col[Maxn], ans[Maxn];

struct SegmentTree {
	int c[Maxn << 2], s[Maxn << 2];
	inline void pushUp(int d) {
		c[d] = c[d << 1];
		s[d] = s[d << 1];
		if (c[d] > c[d << 1 | 1]) {
			c[d] = c[d << 1 | 1];
			s[d] = s[d << 1 | 1];
		}
	}
	void build(int d, int l, int r) {
		if (l == r) {
			c[d] = pre[l];
			s[d] = a[l];
		} else {
			int mid = l + r >> 1;
			build(d << 1, l, mid);
			build(d << 1 | 1, mid + 1, r);
			pushUp(d);
		}
	}
	void modify(int d, int l, int r, int p, int k) {
		if (l == r) {
			c[d] = k;
		} else {
			int mid = l + r >> 1;
			if (p <= mid) {
				modify(d << 1, l, mid, p, k);
			} else {
				modify(d << 1 | 1, mid + 1, r, p, k);
			}
			pushUp(d);
		}
	}
	void query(int d, int l, int r, int pl, int pr) {
		if (pl == l && pr == r) {
			if (_min > c[d]) {
				_min = c[d];
				res = s[d];
			}
		} else {
			int mid = l + r >> 1;
			if (pr <= mid) {
				query(d << 1, l, mid, pl, pr);
			} else if (pl > mid) {
				query(d << 1 | 1, mid + 1, r, pl, pr);
			} else {
				query(d << 1, l, mid, pl, mid);
				query(d << 1 | 1, mid + 1, r, mid + 1, pr);
			}
		}
	}
};

SegmentTree T;

int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		col[i] = -Inf;
	}
	for (int i = 1; i <= n; i++) {
		pre[i] = col[a[i]];
		col[a[i]] = i;
	}
	T.build(1, 1, n);
	m = read();
	for (int i = 1; i <= m; i++) {
		Q[i].l = read(), Q[i].r = read();
		Q[i].i = i;
	}
	sort(Q + 1, Q + m + 1, Cmp);
	for (int i = 1, j = 1; i <= n; i++) {
		if (pre[i] != -Inf) {
			T.modify(1, 1, n, pre[i], Inf);
		}
		while (j <= m && Q[j].r == i) {
			_min = Inf;
			T.query(1, 1, n, Q[j].l, Q[j].r);
			if (_min < Q[j].l) {
				ans[Q[j].i] = res;
			} else {
				ans[Q[j].i] = 0;
			}
			j++;
		}
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

// By Sooke.
// CF1000F One Occurrence.