#include <bits/stdc++.h>

using namespace std;

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

const int N = 2e5 + 5;

struct tree {
	int l, r;
	int lm, rm;
	long long sum;
} tr[N << 2];

int a[N];

void push_up(int n) {
	T.sum = LS.sum + RS.sum;
	T.lm = LS.lm, T.rm = RS.rm;
	if (a[LS.r] <= a[RS.l]) {
		if (LS.lm == LS.r - LS.l + 1) T.lm += RS.lm;
		if (RS.rm == RS.r - RS.l + 1) T.rm += LS.rm;
		T.sum += 1ll * LS.rm * RS.lm;
	}
}

void build(int n, int l, int r) {
	T.l = l, T.r = r;
	if (l == r) {
		T.lm = T.rm = T.sum = 1;
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	push_up(n);
}

void upd(int n, int x, int k) {
	if (T.l == T.r) {
		a[x] = k;
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	push_up(n);
}

long long qry(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.sum;
	if (T.l > r || T.r < l) return 0;
	int m = (T.l + T.r) >> 1;
	if (r <= m) return qry(n << 1, l, r);
	if (l > m) return qry(n << 1 | 1, l, r);
	long long res = qry(n << 1, l, r) + qry(n << 1 | 1, l, r);
	if (a[LS.r] <= a[RS.l]) {
		int ll = min(m - l + 1, LS.rm), rr = min(r - m, RS.lm);
		res += 1ll * ll * rr;
	}
	return res;
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	build(1, 1, n);
	while (q--) {
		int t, x, y;
		scanf("%d%d%d", &t, &x, &y);
		if (t == 1) upd(1, x, y);
		else printf("%lld\n", qry(1, x, y));
	}
	return 0;
}