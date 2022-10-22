#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> plll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define int			ll

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;

int lz[MAXN], n, cnt[MAXN], ps[MAXN];
pair<pll, pll> sg[MAXN];

inline plll merge(plll a, plll b) {
	return {min(a.X, b.X), min(a.Y, b.Y)};
}

void build(int l = 0, int r = n, int v = 1) {
	lz[v] = 0;
	if (l == r) sg[v] = {{INF, l}, {INF, l}};
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

inline void push(int v) {
	sg[v].X.X -= lz[v];
	sg[v].Y.X -= lz[v];

	if ((v << 1 | 1) < MAXN)
		lz[v << 1] += lz[v], lz[v << 1 | 1] += lz[v];
	lz[v] = 0;
}

void update(int ql, int qr, int val, int l = 0, int r = n, int v = 1) {
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
	sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
}

void pointset(int ind, int val1, int val2, int l = 0, int r = n, int v = 1) {
	push(v);
	if (l == r) sg[v] = {{val1, l}, {val2, l}};
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) pointset(ind, val1, val2, l, mid, v << 1), push(v << 1 | 1);
		else pointset(ind, val1, val2, mid + 1, r, v << 1 | 1), push(v << 1);
		sg[v] = merge(sg[v << 1], sg[v << 1 | 1]);
	}
}

inline ll cost(ll a) {
	if (a == 0) return 1;
	ll ind = __lg(a);
	if (a == (1ll << ind)) return 0;
	return ((1ll << (ind + 1)) - a);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < n + 10; i++) cnt[i] = 0;

		cin >> n;
		build();
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			cnt[x]++;
		}

		ll ans = 2 + cost(n);
		pointset(0, cost(0), cost(0) + cost(0));
		for (int i = 1; i <= n; i++) {
			int x = cnt[i];
			ps[i] = ps[i - 1] + x;
			
			pointset(i, cost(0), cost(0) + cost(ps[i]));
			update(0, i - 1, x);

			while (sg[1].X.X < 0) {
				int ind = sg[1].X.Y;
				pointset(ind, cost(ps[i] - ps[ind]), cost(ps[ind]) + cost(ps[i] - ps[ind]));
			}

			ans = min(ans, sg[1].Y.X + cost(n - ps[i]));
		}

		cout << ans << endl;
	}
	return 0;
}