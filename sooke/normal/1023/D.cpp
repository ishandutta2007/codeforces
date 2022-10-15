#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

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

std::vector<int> vc[MAXN];
int n, q, zr, a[MAXN], sl[MAXN], sr[MAXN];

struct SegmentTree {
	int min[MAXN << 2];
	void build(int u, int l, int r) {
		if (l == r) {
			min[u] = a[l];
		} else {
			int mid = l + r >> 1;
			build(u << 1, l, mid);
			build(u << 1 | 1, mid + 1, r);
			min[u] = MIN(min[u << 1], min[u << 1 | 1]);
		}
	}
	void query(int u, int l, int r, int pl, int pr, int &res) {
		if (l == pl && r == pr) {
			res = MIN(res, min[u]);
		} else {
			int mid = l + r >> 1;
			if (pr <= mid) {
				query(u << 1, l, mid, pl, pr, res);
			} else if (pl > mid) {
				query(u << 1 | 1, mid + 1, r, pl, pr, res);
			} else {
				query(u << 1, l, mid, pl, mid, res);
				query(u << 1 | 1, mid + 1, r, mid + 1, pr, res);
			}
		}
	}
} tr;

bool check() {
	for (int i = 1; i <= n; i++) {
		if (sl[a[i]] == 0) {
			sl[a[i]] = i;
		}
		sr[a[i]] = i;
	}
	if (sl[q] == 0) {
		return false;
	}
	tr.build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		if (sl[i] != 0) {
			int res = i;
			tr.query(1, 1, n, sl[i], sr[i], res);
			if (res < i) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	bool flag = false;
	n = read(), q = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] == q) {
			flag = true;
		}
		if (a[i] == 0) {
			zr = i;
		} else {
			vc[a[i]].push_back(i);
		}
	}
	if (zr == 0) {
		if (check()) {
			printf("YES\n");
			for (int i = 1; i <= n; i++) {
				printf("%d ", a[i]);
			}
		} else {
			printf("NO\n");
		}
		return 0;
	}
	if (flag == false) {
		a[zr] = q;
		vc[q].push_back(zr);
	}
	a[0] = a[n + 1] = -1;
	for (int i = q; i >= 1; i--) {
		for (int j = 0; j < vc[i].size(); j++) {
			int u = vc[i][j], pos = u;
			while (a[pos - 1] == 0) {
				a[--pos] = i;
			}
			while (a[pos + 1] == 0) {
				a[++pos] = i;
			}
		}
	}
	if (check()) {
		printf("YES\n");
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
	} else {
		printf("NO\n");
	}
	return 0;
}

// By Sooke.
// CF1023D Array Restoration.