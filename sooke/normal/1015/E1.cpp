#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

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

inline bool star() {
	char c = getchar();
	while (c != '.' && c != '*') {
		c = getchar();
	}
	return c == '*';
}
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

#define MAXN 1005

vector<int> A, B, C;
int n, m, sl[MAXN][MAXN], sr[MAXN][MAXN], su[MAXN][MAXN], sd[MAXN][MAXN];
bool a[MAXN][MAXN];

struct SegmentTree {
	bool tag[MAXN << 2];
	void modify(int d, int l, int r, int pl, int pr) {
		if (l == pl && r == pr) {
			tag[d] = true;
			return;
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
		}
	}
	int query(int d, int l, int r, int p) {
		if (l == r) {
			return tag[d];
		} else {
			int mid = l + r >> 1;
			if (p <= mid) {
				return query(d << 1, l, mid, p) || tag[d];
			} else {
				return query(d << 1 | 1, mid + 1, r, p) || tag[d];
			}
		}
	}
} Ta[MAXN], Tb[MAXN];

inline bool check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && Ta[i].query(1, 1, m, j) == false && Tb[j].query(1, 1, n, i) == false) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = star();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j]) {
				sl[i][j] = sl[i][j - 1] + 1;
			} else {
				sl[i][j] = 0;
			}
		}
		for (int j = m; j >= 1; j--) {
			if (a[i][j]) {
				sr[i][j] = sr[i][j + 1] + 1;
			} else {
				sr[i][j] = 0;
			}
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (a[i][j]) {
				su[i][j] = su[i - 1][j] + 1;
			} else {
				su[i][j] = 0;
			}
		}
		for (int i = n; i >= 1; i--) {
			if (a[i][j]) {
				sd[i][j] = sd[i + 1][j] + 1;
			} else {
				sd[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int s = MIN(MIN(sl[i][j], sr[i][j]), MIN(su[i][j], sd[i][j]));
			if (s >= 2) {
				A.push_back(i);
				B.push_back(j);
				C.push_back(s);
				Ta[i].modify(1, 1, m, j - s + 1, j + s - 1);
				Tb[j].modify(1, 1, n, i - s + 1, i + s - 1);
			}
		}
	}
	if (check()) {
		printf("%d\n", A.size());
		for (int i = 0; i < A.size(); i++) {
			printf("%d %d %d\n", A[i], B[i], C[i] - 1);
		}
	} else {
		printf("-1\n");
	}
	return 0;
}

// By Sooke.