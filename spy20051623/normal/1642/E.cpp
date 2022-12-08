#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
struct node {
	int l, r, s, t, m;
} tr[N << 2];
#define T tr[n]
#define LS tr[n<<1]
#define RS tr[n<<1|1]

void build(int n, int l, int r) {
	T.l = l, T.r = r, T.s = 0, T.t = 0, T.m = 1e9;
	if (l == r) return;
	int m = (l + r) >> 1;
	build(n << 1, l, m);
	build(n << 1 | 1, m + 1, r);
}

void upd(int n, int l, int r) {
	if (T.l >= l && T.r <= r) {
		T.t = 1;
		T.s = T.r - T.l + 1;
		return;
	}
	if (T.t || T.l > r || T.r < l) return;
	upd(n << 1, l, r);
	upd(n << 1 | 1, l, r);
	T.s = LS.s + RS.s;
	if (T.s == T.r - T.l + 1) T.t = 1;
}

int qryP(int x) {
	int n = 1;
	while (T.l != T.r) {
		if (T.t) return 1;
		int m = (T.l + T.r) >> 1;
		if (x <= m) n = n << 1;
		else n = n << 1 | 1;
	}
	return T.t;
}

int qryL(int tot, int x) {
	if (x < 1) return 1;
	int n = 1;
	while (T.l != T.r && !T.t) {
		int m = (T.l + T.r) >> 1;
		if (x <= m) n = n << 1;
		else n = n << 1 | 1;
	}
	if (!T.t) return T.l;
	n >>= 1;
	while (n && (x <= (T.l + T.r) >> 1 || LS.t)) n >>= 1;
	if (!n) return 1;
	n = n << 1;
	while (T.l != T.r) {
		if (RS.t) n = n << 1;
		else n = n << 1 | 1;
	}
	return T.l + 1;
}

int qryR(int tot, int x) {
	if (x > tot) return tot;
	int n = 1;
	while (T.l != T.r && !T.t) {
		int m = (T.l + T.r) >> 1;
		if (x <= m) n = n << 1;
		else n = n << 1 | 1;
	}
	if (!T.t) return T.l;
	n >>= 1;
	while (n && (x > (T.l + T.r) >> 1 || RS.t)) n >>= 1;
	if (!n) return tot;
	n = n << 1 | 1;
	while (T.l != T.r) {
		if (LS.t) n = n << 1 | 1;
		else n = n << 1;
	}
	return T.l - 1;
}

void updV(int n, int x, int k) {
	if (T.l == T.r) {
		T.m = min(T.m, k);
		return;
	}
	int m = (T.l + T.r) >> 1;
	if (x <= m) updV(n << 1, x, k);
	else updV(n << 1 | 1, x, k);
	T.m = min(LS.m, RS.m);
}

int qryV(int n, int l, int r) {
	if (T.l >= l && T.r <= r) return T.m;
	if (T.l > r || T.r < l) return 1e9;
	return min(qryV(n << 1, l, r), qryV(n << 1 | 1, l, r));
}

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
	while (q--) {
		int o;
		cin >> o;
		if (!o) {
			int x, y, k;
			cin >> x >> y >> k;
			if (!k) upd(1, x, y);
			else updV(1, x, y);
		} else {
			int x;
			cin >> x;
			if (qryP(x)) {
				cout << "NO\n";
				continue;
			}
			int l = !qryP(x - 1) ? x : qryL(n, x - 1), r = !qryP(x + 1) ? x : qryR(n, x + 1);
			int m = qryV(1, l, r);
			if (m <= r) cout << "YES\n";
			else cout << "N/A\n";
		}
	}
	return 0;
}