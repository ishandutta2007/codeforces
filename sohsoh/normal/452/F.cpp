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

const ll MAXN = 12e5 + 10;
const ll MOD = 1e9 + 7;
const ll P = 31;

struct node {
	ll val = 0, val_r = 0, len = 0;
	node(ll val, ll val_r, ll len): val(val), val_r(val_r), len(len) {}
	node(ll x) {
		len = 1;
		val = x;
		val_r = x;
	}

	node() {}
} sg[MAXN];

ll pw[MAXN];
int n;

inline node merge(node a, node b) {
	if (!a.len) return b;
	if (!b.len) return a;

	return node((a.val * pw[b.len] + b.val) % MOD,
			(b.val_r * pw[a.len] + a.val_r) % MOD,
			a.len + b.len);
}

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(0);
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

void update(int ind, int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = node(1);
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, l, mid, v << 1);
		else update(ind, mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
	if (ql > r || qr < l) return node();
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * P % MOD;

	cin >> n;
	build();
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(x);
		int len = min(x, n - x + 1);
		if (query(x - len + 1, x).val_r != query(x, x + len - 1).val) return cout << "YES" << endl, 0;
	}

	cout << "NO" << endl;
	return 0;
}