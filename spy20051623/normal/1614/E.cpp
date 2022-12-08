#include <bits/stdc++.h>

using namespace std;
const int lb = -1e7, rb = 1e9 + 1e7;
const int N = 2e5 + 5;
const int mod = 1e9 + 1;
struct node {
	int l, r, v, ls, rs, lx, rx;
} tr[N << 6];
#define T tr[n]
#define LS tr[tr[n].ls]
#define RS tr[tr[n].rs]
int tot;

void push_down(int n) {
	int m = (T.l + T.r) >> 1;
	if (!T.ls) T.ls = ++tot, tr[tot] = {T.l, m, 0, 0, 0, T.l, m};
	if (!T.rs) T.rs = ++tot, tr[tot] = {m + 1, T.r, 0, 0, 0, m + 1, T.r};
	LS.v += T.v, RS.v += T.v;
	LS.lx += T.v, LS.rx += T.v;
	RS.lx += T.v, RS.rx += T.v;
	T.v = 0;
}

void upd(int n, int l, int r, int k) {
	if (T.l >= l && T.r <= r) {
		T.v += k;
		T.lx += k;
		T.rx += k;
		return;
	}
	if (T.l > r || T.r < l) return;
	push_down(n);
	upd(T.ls, l, r, k);
	upd(T.rs, l, r, k);
	T.lx = LS.lx, T.rx = RS.rx;
}

int qry(int n, int x) {
	if (T.l == T.r) return T.v;
	push_down(n);
	int m = (T.l + T.r) >> 1;
	if (x <= m) return qry(T.ls, x);
	else return qry(T.rs, x);
}

int find(int n, int x, int f) {
	if (T.l == T.r) return T.l;
	push_down(n);
	if (f == -1) {
		if (LS.rx >= x) return find(T.ls, x, -1);
		else return find(T.rs, x, -1);
	} else {
		if (RS.lx <= x) return find(T.rs, x, 1);
		else return find(T.ls, x, 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int lastans = 0;
	int n;
	scanf("%d", &n);
	tr[0] = {lb, rb, 0, 0, 0};
	for (int i = 0; i < n; ++i) {
		int t;
		scanf("%d", &t);
		int ll = find(0, t, -1), rr = find(0, t, 1);
		upd(0, lb, ll - 1, 1);
		upd(0, rr + 1, rb, -1);
		int k;
		scanf("%d", &k);
		while (k--) {
			int x;
			scanf("%d", &x);
			x = (x + lastans) % mod;
			lastans = x + qry(0, x);
			printf("%d\n", lastans);
		}
	}
	return 0;
}