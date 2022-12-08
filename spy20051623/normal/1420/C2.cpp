#include <bits/stdc++.h>

using namespace std;
const int N = 3e5 + 5;
long long a[N];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]
struct node {
	int l, r;
	long long amx, amn, bmx, bmn;
} tr[N << 2];

void pushup(int n) {
	T.amx = max(max(LS.amx, RS.amx), max(LS.amx - RS.bmn, LS.bmx + RS.amx));
	T.amn = min(min(LS.amn, RS.amn), min(LS.amn - RS.bmx, LS.bmn + RS.amn));
	T.bmx = max(max(LS.bmx, RS.bmx), max(LS.amx - RS.amn, LS.bmx + RS.bmx));
	T.bmn = min(min(LS.bmn, RS.bmn), min(LS.amn - RS.amx, LS.bmn + RS.bmn));
}

void build(int n, int l, int r) {
	T.l = l, T.r = r;
	if (l == r) {
		T.amn = T.amx = a[l];
		T.bmn = 1e18, T.bmx = -1e18;
		return;
	}
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
	pushup(n);
}

void upd(int n, int x, int k) {
	if (T.l == T.r) {
		T.amn = T.amx = k;
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) upd(n << 1, x, k);
	else upd(n << 1 | 1, x, k);
	pushup(n);
}

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, 1, n);
	cout << tr[1].amx << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;
		swap(a[l], a[r]);
		upd(1, l, a[l]);
		upd(1, r, a[r]);
		cout << tr[1].amx << '\n';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}