#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> mat;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;
const mat FIB_BASE = {{1, 1}, {1, 0}};

mat operator* (mat a, mat b) {
	/*
	 *	a b       x y
	 *	c d	  w z
	 *
	 * */

	return {{(a.X.X * b.X.X + a.X.Y * b.Y.X) % MOD, (a.X.X * b.X.Y + a.X.Y * b.Y.Y) % MOD}, 
		{(a.Y.X * b.X.X + a.Y.Y * b.Y.X) % MOD, (a.Y.X * b.X.Y + a.Y.Y * b.Y.Y) % MOD}};
}

mat operator^ (mat a, ll b) {
	mat ans = {{1, 0}, {0, 1}};
	while (b) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}

	return ans;
}

mat operator+ (mat a, mat b) {
	return {{(a.X.X + b.X.X) % MOD, (a.X.Y + b.X.Y) % MOD},
		{(a.Y.X + b.Y.X) % MOD, (a.Y.Y + b.Y.Y) % MOD}};
}

ll lz[MAXN], n, q, A[MAXN];
mat sg[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = (FIB_BASE ^ A[l]);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
	}
}

inline void push(int v) {
	if (lz[v]) {
		sg[v] = sg[v] * (FIB_BASE ^ lz[v]);
		lz[v << 1] += lz[v];
		lz[v << 1 | 1] += lz[v];
		lz[v] = 0;
	}
}

void update(int ql, int qr, int x, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += x;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, x, l, mid, v << 1);
	update(ql, qr, x, mid + 1, r, v << 1 | 1);
	sg[v] = sg[v << 1] + sg[v << 1 | 1];
}

mat query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return {{0, 0}, {0, 0}};
	else if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return query(ql, qr, l, mid, v << 1) + 
		query(ql, qr, mid + 1, r, v << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> A[i];
	build();

	while (q--) {
		int c, l, r;
		cin >> c >> l >> r;
		if (c == 1) {
			int x;
			cin >> x;
			update(l, r, x);
		} else cout << query(l, r).X.Y << endl;
	}
	return 0;
}