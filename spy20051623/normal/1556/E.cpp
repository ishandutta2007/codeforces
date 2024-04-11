#include <bits/stdc++.h>

using namespace std;

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]
#define N 100005

struct tree {
	int l, r;
	long long mx, mn;
} tr[N << 2];

int a[N], b[N], c[N];
long long d[N];

void build(int n, int l, int r) {
	T.l = l, T.r = r;
	if (l == r) {
		T.mx = T.mn = d[l];
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	T.mx = max(LS.mx, RS.mx);
	T.mn = min(LS.mn, RS.mn);
}

long long qry(int n, int l, int r, int t) {
	if (T.l >= l && T.r <= r) {
		if (t) return T.mx;
		else return T.mn;
	}
	if (T.l > r || T.r < l) {
		if (t) return -1e18;
		else return 1e18;
	}
	if (t) return max(qry(n << 1, l, r, t), qry(n << 1 | 1, l, r, t));
	else return min(qry(n << 1, l, r, t), qry(n << 1 | 1, l, r, t));
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	for (int i = 1; i <= n; ++i) {
		c[i] = a[i] - b[i];
		d[i] = d[i - 1] + c[i];
	}
	build(1, 1, n);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (d[l - 1] != d[r]) {
			printf("-1\n");
			continue;
		}
		printf("%lld\n", max(abs(d[l - 1] - qry(1, l, r, 0)), abs(d[l - 1] - qry(1, l, r, 1))));
	}
	return 0;
}