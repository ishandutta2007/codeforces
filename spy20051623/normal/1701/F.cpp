#include <bits/stdc++.h>

const int N = 2e5 + 5;

struct node {
	int l, r;
	long long s, c, t;
} tr[N << 2];

#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

struct dt {
	long long s, c;

	dt operator+(dt o) const {
		return {s + o.s, c + o.c};
	}
};

void pushdown(int n) {
	LS.s += T.t * LS.c;
	RS.s += T.t * RS.c;
	LS.t += T.t;
	RS.t += T.t;
	T.t = 0;
}

void pushup(int n) {
	T.s = LS.s + RS.s;
	T.c = LS.c + RS.c;
}

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.s = 0, T.c = 0, T.t = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

dt upd(int n, int l, int r, int k) {
	if (T.l > r || T.r < l) return {0, 0};
	dt ans = {T.s, T.c};
	if (T.l >= l && T.r <= r) {
		T.s += k * T.c;
		T.t += k;
		return ans;
	}
	pushdown(n);
	ans = {0, 0};
	ans = ans + upd(n << 1, l, r, k);
	ans = ans + upd(n << 1 | 1, l, r, k);
	pushup(n);
	return ans;
}

void create(int n, int x, int f, int k) {
	if (T.l == T.r) {
		T.c += f;
		T.s += f * k;
		return;
	}
	pushdown(n);
	int m = (T.l + T.r) >> 1;
	if (x <= m) create(n << 1, x, f, k);
	else create(n << 1 | 1, x, f, k);
	pushup(n);
}

int d[N << 1];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int k) {
	for (; x < N << 1; x += lowbit(x)) d[x] += k;
}

int qry(int x) {
	int s = 0;
	for (; x > 0; x -= lowbit(x)) s += d[x];
	return s;
}

int a[N];

void solve() {
	int n, k;
	std::cin >> n >> k;
	build(1, 1, 200000);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		int p;
		std::cin >> p;
		a[p] ^= 1;
		if (a[p]) {
			add(p, 1);
			int l = std::max(1, p - k), r = p - 1, c = qry(p + k) - qry(p);
			dt q = upd(1, l, r, 1);
			ans += q.s;
			create(1, p, 1, c);
			ans += 1ll * c * (c - 1) / 2;
		} else {
			add(p, -1);
			int l = std::max(1, p - k), r = p - 1, c = qry(p + k) - qry(p);
			dt q = upd(1, l, r, -1);
			ans -= q.s - q.c;
			create(1, p, -1, c);
			ans -= 1ll * c * (c - 1) / 2;
		}
		std::cout << ans << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
}