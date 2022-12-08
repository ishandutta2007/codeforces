#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
struct node {
	int l, r, v;
} tr[N << 2];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]
int a[N], s[50];

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.v = (1 << 30) - 1;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void push_down(int n) {
	LS.v &= T.v, RS.v &= T.v;
	T.v = (1 << 30) - 1;
}

void upd(int n, int l, int r, int k) {
	if (T.l >= l && T.r <= r) {
		T.v &= k;
		return;
	}
	if (T.l > r || T.r < l) return;
	push_down(n);
	upd(n << 1, l, r, k);
	upd(n << 1 | 1, l, r, k);
}

int qry(int n, int x) {
	if (T.l == T.r) return T.v;
	int m = (T.l + T.r) >> 1;
	push_down(n);
	if (x <= m) return qry(n << 1, x);
	else return qry(n << 1 | 1, x);
}

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	while (m--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		upd(1, l, r, x);
	}
	for (int i = 1; i <= n; ++i) {
		a[i] = qry(1, i);
	}
	memset(s, 0, sizeof s);
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 30; ++j) {
			if (a[i] >> j & 1) s[j] = (cnt + 1) % mod;
			else s[j] = s[j] * 2 % mod;
		}
		cnt = (cnt * 2 + 1) % mod;
	}
	long long ans = 0;
	for (int i = 0; i < 30; ++i) {
		ans += (1ll << i) * s[i] % mod;
	}
	ans %= mod;
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}