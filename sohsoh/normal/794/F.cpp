//: // ////: ///  / : //// / :
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 8e5 + 10;
const ll MAXD = 11;

int n, q, A[MAXN];
ll sg[MAXN][MAXD], lz[MAXN][MAXD], tsg[MAXD];

inline void f(int v, int a, int b) {
	for (int i = 0; i < MAXD; i++)
		if (lz[v][i] == a)
			lz[v][i] = b;
	if (lz[v][a] == -1) lz[v][a] = b;
}

inline void push(int v) {
	for (int i = 0; i < MAXD; i++)
		tsg[i] = (lz[v][i] == -1 ? sg[v][i] : 0);

	for (int i = 0; i < MAXD; i++)
		if (lz[v][i] != -1)
			tsg[lz[v][i]] += sg[v][i];

	for (int i = 0; i < MAXD; i++) {
		sg[v][i] = tsg[i];
		if (lz[v][lz[v << 1][i]] > 0) lz[v << 1][i] = lz[v][lz[v << 1][i]];
		if (lz[v][lz[v << 1 | 1][i]] > 0) lz[v << 1 | 1][i] = lz[v][lz[v << 1 | 1][i]];
	}

	for (int i = 0; i < MAXD; i++) {
		if (lz[v << 1][i] == -1) lz[v << 1][i] = lz[v][i];
		if (lz[v << 1 | 1][i] == -1) lz[v << 1 | 1][i] = lz[v][i];
		lz[v][i] = -1;
	}
}

void update(int ql, int qr, int a, int b, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		f(v, a, b);
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, a, b, l, mid, v << 1);
	update(ql, qr, a, b, mid + 1, r, v << 1 | 1);
	for (int i = 0; i < MAXD; i++)
		sg[v][i] = sg[v << 1][i] + sg[v << 1 | 1][i];
}

ll query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) {
		ll ans = 0;
		for (int i = 0; i < MAXD; i++)
			ans += sg[v][i] * i;
		return ans;
	}

	int mid = (l + r) >> 1;
	return query(ql, qr, l, mid, v << 1) + 
		query(ql, qr, mid + 1, r, v << 1 | 1);
}

void build(int l = 1, int r = n, int v = 1) {
	for (int i = 0; i < MAXD; i++) lz[v][i] = -1;
	if (l == r) {
		ll t = 1;
		while (A[l]) {
			int d = A[l] % 10;
			sg[v][d] += t;
			A[l] /= 10;
			t = t * 10;
		}
	} else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		for (int i = 0; i < MAXD; i++)
			sg[v][i] = sg[v << 1][i] + sg[v << 1 | 1][i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	build();
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int l, r, a, b;
			cin >> l >> r >> a >> b;
			update(l, r, a, b);
		} else {
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}

	}
	return 0;
}