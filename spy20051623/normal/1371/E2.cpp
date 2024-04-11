#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 5;
int a[N], c[N << 1];
struct node {
	int l, r, t, mn, mx;
} tr[N << 3];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.t = 0;
	if (l == r) {
		T.mn = T.mx = c[l];
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	T.mn = min(LS.mn, RS.mn);
	T.mx = max(LS.mx, RS.mx);
}

void push_down(int n) {
	LS.t += T.t;
	RS.t += T.t;
	LS.mn += T.t;
	RS.mn += T.t;
	LS.mx += T.t;
	RS.mx += T.t;
	T.t = 0;
}

void upd(int n, int l, int r, int k) {
	if (T.l >= l && T.r <= r) {
		T.t += k;
		T.mn += k;
		T.mx += k;
		return;
	}
	if (T.l > r || T.r < l) return;
	push_down(n);
	upd(n << 1, l, r, k);
	upd(n << 1 | 1, l, r, k);
	T.mn = min(LS.mn, RS.mn);
	T.mx = max(LS.mx, RS.mx);
}

int qry_mn(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.mn;
	if (T.l > r || T.r < l) return 1e9;
	push_down(n);
	return min(qry_mn(n << 1, l, r), qry_mn(n << 1 | 1, l, r));
}

int qry_mx(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.mx;
	if (T.l > r || T.r < l) return -1;
	push_down(n);
	return max(qry_mx(n << 1, l, r), qry_mx(n << 1 | 1, l, r));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int mx = a[n - 1];
	for (int i = 0; i < n; ++i) {
		if (a[i] < mx - n + 1) ++c[1];
		else ++c[a[i] - mx + n];
	}
	for (int i = 1; i <= n + n; ++i) {
		c[i] += c[i - 1];
	}
	build(1, 1, n + n);
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		upd(1, n + i, n + i, -i);
	}
	for (int i = 0; i < n; ++i) {
		if (qry_mn(1, n - i, n + n - i - 1) >= 1 && qry_mx(1, n - i, n + n - i - 1) < p) v.push_back(mx - i);
		upd(1, n - i, n + n - i - 1, -1);
	}
	reverse(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i: v) cout << i << ' ';
	return 0;
}