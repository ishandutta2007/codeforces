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

const ll MAXN = 2e6 + 10;
const ll INF = 1e18;

pair<ll, int> sg[MAXN];
ll lz[MAXN], n, q, A[MAXN];

void build(int l = 1, int r = n, int v = 1) {
	if (l == r) sg[v] = {0, l};
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

inline void push(int v) {
	sg[v].X += lz[v];
	lz[v << 1] += lz[v];
	lz[v << 1 | 1] += lz[v];

	lz[v] = 0;
}

void update(int ql, int qr, ll val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);
	sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
}

void point_update(int ind, ll val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (l == r) sg[v].X += val;
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) point_update(ind, val, l, mid, v << 1), push(v << 1 | 1);
		else point_update(ind, val, mid + 1, r, v << 1 | 1), push(v << 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

inline void f(int i, int x) {
	x = x - A[i];
	point_update(i, x);
	if (i < n) update(i + 1, n, -x);
	A[i] += x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	build();
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		f(i, x);
	}

	while (q--) {
		int p, x;
		cin >> p >> x;
		f(p, x);

		vector<int> vec;
		while (sg[1].X > 0) {
			vec.push_back(sg[1].Y);
			point_update(sg[1].Y, -INF);
		}

		cout << (sg[1].X < 0 ? -1 : sg[1].Y) << endl;
		for (int e : vec)
			point_update(e, INF);
	}
	return 0;
}