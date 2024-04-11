#include <iostream>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;
const ll MAXM = 5;

int sg[MAXN << 2][2][1 << MAXM], n, q, m;
bool lz[MAXN << 2], A[MAXN];

void merge(int a[2][1 << MAXM], int b[2][1 << MAXM], int c[2][1 << MAXM]) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < (1 << m); j++) {
			int mask = b[i][j];
			c[i][j] = a[i][mask];
		}
	}
}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) {
		for (int mask = 1; mask < (1 << m); mask++) // 0 -> W, 1 -> L
			sg[v][0][mask] = sg[v][1][mask] = (((mask << 1) | (1 << m)) ^ (1 << m)); 
		sg[v][A[l] ^ 1][0] = 1;	
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		merge(sg[v << 1], sg[v << 1 | 1], sg[v]);
	}
}

void push(int v) {
	if (lz[v]) {
		if ((v << 1 | 1) < (MAXN << 2)) lz[v << 1] ^= 1, lz[v << 1 | 1] ^= 1;
		swap(sg[v][0], sg[v][1]);
		lz[v] = false;
	}
}

void update(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] ^= 1;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, l, mid, v << 1);
	update(ql, qr, mid + 1, r, v << 1 | 1);
	merge(sg[v << 1], sg[v << 1 | 1], sg[v]);
}

int query(int ql, int qr, int ans, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql <= l && qr >= r) return sg[v][0][ans];
	
	int mid = (l + r) >> 1;
	if (mid + 1 <= qr) ans = query(ql, qr, ans, mid + 1, r, v << 1 | 1);
	if (ql <= mid) ans = query(ql, qr, ans, l, mid, v << 1);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		A[i] = x & 1;
	}

	build();
	while (q--) {
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1) {
			ll d;
			cin >> d;
			if (d & 1) update(l, r);
		} else {
			cout << (query(l, r, 0) & 1) + 1 << endl;
		}
	}
	return 0;
}