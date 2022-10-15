#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define SQR(x) ((x) * (x))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define LOWBIT(x) ((x) & -(x))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define SWAP(x, y) ((x) ^= (y), (y) ^= (x), (x) ^= (y))
#define MAXINT 2147483647
#define MAXLOL 9223372036854775807
#define INF MAXINT
#define lol long long

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

#define MAXN 300005

int n, m, a[MAXN], dov[MAXN << 2];

struct SegmentTree {
	lol sum[MAXN << 2];
	int mx[MAXN << 2];
	inline void pushUp(int d) {
		sum[d] = sum[d << 1] + sum[d << 1 | 1];
		mx[d] = MAX(mx[d << 1], mx[d << 1 | 1]);
	}
	void build(int d, int l, int r) {
		if (l == r) {
			sum[d] = mx[d] = a[l];
		} else {
			int mid = l + r >> 1;
			build(d << 1, l, mid);
			build(d << 1 | 1, mid + 1, r);
			pushUp(d);
		}
	}
	void modify(int d, int l, int r, int pl, int pr) {
		if (mx[d] <= 2) {
			return;
		}
		if (l == r) {
			sum[d] = mx[d] = dov[sum[d]];
		} else {
			int mid = l + r >> 1;
			if (pr <= mid) {
				modify(d << 1, l, mid, pl, pr);
			} else if (pl > mid) {
				modify(d << 1 | 1, mid + 1, r, pl, pr);
			} else {
				modify(d << 1, l, mid, pl, mid);
				modify(d << 1 | 1, mid + 1, r, mid + 1, pr);
			}
			pushUp(d);
		}
	}
	lol query(int d, int l, int r, int pl, int pr) {
		if (pl == l && pr == r) {
			return sum[d];
		} else {
			int mid = l + r >> 1;
			if (pr <= mid) {
				return query(d << 1, l, mid, pl, pr);
			} else if (pl > mid) {
				return query(d << 1 | 1, mid + 1, r, pl, pr);
			} else {
				return query(d << 1, l, mid, pl, mid) + query(d << 1 | 1, mid + 1, r, mid + 1, pr);
			}
		}
	}
};

SegmentTree T;

inline void init(int d) {
	for (int i = 1; i <= d; i++) {
		for (int j = i; j <= d; j += i) {
			dov[j]++;
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	T.build(1, 1, n);
	init(T.mx[1]);
	for (int i = 1; i <= m; i++) {
		int opt = read(), l = read(), r = read();
		if (opt == 1) {
			T.modify(1, 1, n, l, r);
		} else {
			printf("%I64d\n", T.query(1, 1, n, l, r));
		}
	}
	return 0;
}

// By Sooke.
// CF920F SUM and REPLACE.