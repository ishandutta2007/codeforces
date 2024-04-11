#include <cstdio>
#include <algorithm>

#define D 19
#define N 200100
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

typedef __int64 LL;

struct itv {
	int l, r, id;
	itv (int l = 0, int r = 0) : l(l), r(r) {}
	void input(int i) { scanf("%d %d", &l, &r), id = i; }
	bool operator < (const itv &I) const { return l != I.l ? l < I.l : r > I.r; }
} a[N], A[N];

int left[N], right[N];
int rmq[D][N];

int query(int l, int r) {
	int cnt = r - l + 1, i;
	if (cnt <= 0) return -1;
	for (i = 0; (1 << i) <= cnt; i ++);
	i --;
	int tp1 = rmq[i][l];
	int tp2 = rmq[i][r - (1 << i) + 1];
	if (A[tp1].r - A[tp1].l > A[tp2].r - A[tp2].l) return tp1;
	return tp2;
}

main() {
//	freopen("A_m.in", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) a[i].input(i);
	sort(a, a + n);
	int nn = 0;
	A[nn ++] = a[0];
	for (int i = 1; i < n; i ++) if (A[nn - 1].r < a[i].r) A[nn ++] = a[i];
	n = nn;
	for (int i = 0; i < n; i ++) {
		left[i] = A[i].l;
		right[i] = A[i].r;
	}
	for (int i = 0; i < n; i ++) rmq[0][i] = i;
	for (int j = 1; (1 << j) <= n; j ++) {
		int k = 1 << (j - 1);
		for (int i = 0; i + (1 << j) - 1 < n; i ++) {
			int tp1 = rmq[j - 1][i];
			int tp2 = rmq[j - 1][i + k];
			if (A[tp1].r - A[tp1].l > A[tp2].r - A[tp2].l) rmq[j][i] = tp1;
			else rmq[j][i] = tp2;
		}
	}
	LL Max = 0;
	int u, v;
	for (int i = 0; i < m; i ++) {
		int L, R, C;
		scanf("%d %d %d", &L, &R, &C);
		if (R < A[0].l) continue;
		if (A[n - 1].r < L) continue;
		int lo = lower_bound(left, left + n, L) - left;
		int hi = upper_bound(right, right + n, R) - right - 1;
		if (lo && L <= A[lo - 1].r) {
			LL tmp = (LL)(min(R, A[lo - 1].r) - L) * C;
			if (Max < tmp) Max = tmp, u = A[lo - 1].id, v = i;
		}
		if (hi + 1 < n && A[hi + 1].l <= R) {
			LL tmp = (LL)(R - max(L, A[hi + 1].l)) * C;
			if (Max < tmp) Max = tmp, u = A[hi + 1].id, v = i;
		}

		int uu = query(lo, hi);
		if (uu < 0) continue;
		int len = A[uu].r - A[uu].l;
		LL tmp = (LL)len * C;
		if (Max < tmp) Max = tmp, u = A[uu].id, v = i;
	}
	if (!Max) puts("0");
	else {
		printf("%I64d\n", Max);
		printf("%d %d\n", u + 1, v + 1);
	}
}