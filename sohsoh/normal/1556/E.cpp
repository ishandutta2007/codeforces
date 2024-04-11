// orz
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;

int n, q;
ll d[MAXN], ps[MAXN];
pll sg[MAXN];

inline pll merge(pll a, pll b) {
	a.X = min(a.X, b.X);
	a.Y = max(a.Y, b.Y);
	return a;
} 

void build(int l = 0, int r = n, int v = 1) {
	if (l == r) sg[v] = {ps[l], ps[l]};
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

pll query(int ql, int qr, int l = 0, int r = n, int v = 1) {
	if (ql > r || qr < l) return {INF, -INF};
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return merge(query(ql, qr, l, mid, v << 1),
			query(ql, qr, mid + 1, r, v << 1 | 1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> d[i];
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		d[i] -= x;
	}

	for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + d[i]; 

	build();
	while (q--) {
		int l, r;
		cin >> l >> r;
		
		if (ps[r] - ps[l - 1] != 0) {
			cout << -1 << endl;
			continue;
		}

		pll f = query(l, r);
		f.X -= ps[l - 1];
		f.Y -= ps[l - 1];

		if (f.Y > 0) cout << -1 << endl;
		else cout << -1 * f.X << endl;
	}
	return 0;
}