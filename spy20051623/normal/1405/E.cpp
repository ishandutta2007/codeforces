#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
struct node {
	int l, r, s;
} tr[N << 2];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.s = 0;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void upd(int n, int x) {
	if (T.l == T.r) {
		++T.s;
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x);
	else upd(n << 1 | 1, x);
	T.s = LS.s + RS.s;
}

int sum(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.s;
	if (T.l > r || T.r < l) return 0;
	return sum(n << 1, l, r) + sum(n << 1 | 1, l, r);
}

int qry(int n, int x, int k, int &sum) {
	if (T.l == T.r) return sum = T.s, T.s >= k ? T.l : 0;
	if (T.r <= x && T.s < k) return sum = T.s, 0;
	int m = (T.l + T.r) >> 1;
	int sl = 0, sr = 0;
	if (x > m) {
		int ans = qry(n << 1 | 1, x, k, sr);
		if (ans) return ans;
		else k -= sr;
	}
	int ans = qry(n << 1, x, k, sl);
	sum = sl + sr;
	return ans;
}

int a[N];

struct dt {
	int l, r, id, ans;
} d[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, q;
	cin >> n >> q;
	build(1, 1, n);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] = i - a[i];
	}
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		d[i].l = 1 + x;
		d[i].r = n - y;
		d[i].id = i;
	}
	sort(d, d + q, [&](dt &x, dt &y) { return x.r < y.r; });
	int cur = 0;
	for (int i = 0; i < q; ++i) {
		while (d[i].r != cur) {
			++cur;
			if (a[cur] >= 0) {
				int s;
				int t = qry(1, cur, a[cur], s);
				if (t) upd(1, t);
			}
		}
		d[i].ans = sum(1, d[i].l, d[i].r);
	}
	sort(d, d + q, [&](dt &x, dt &y) { return x.id < y.id; });
	for (int i = 0; i < q; ++i) {
		cout << d[i].ans << '\n';
	}
	return 0;
}