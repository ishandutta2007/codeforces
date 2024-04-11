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

const ll MAXN = 5e5 + 10;
const ll INF = 8e18;

ll sg[MAXN], n, x, A[MAXN], ps[MAXN];

void update(ll ind, ll val, int l = 0, int r = n, int v = 1) {
	if (l == r) sg[v] = val;
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) update(ind, val, l, mid, v << 1);
		else update(ind, val, mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

int query(ll x, int l = 0, int r = n, int v = 1) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (sg[v << 1 | 1] > x) return query(x, mid + 1, r, v << 1 | 1);
	return query(x, l, mid, v << 1);
}

inline void solve() {
	// clearrrrrrrrrrrrrrr
	fill(sg, sg + MAXN, -INF);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	cin >> x;

	int lst = 0, ans = 0;
	ps[0] = 0;
	for (int i = 1; i <= n; i++) {
		ps[i] = ps[i - 1] + A[i] - x;
		if (sg[1] > ps[i]) {
			ll ind = query(ps[i]);
			ind++;
			if (ind > lst) lst = i, ans++;
		}

		update(i - 1, ps[i - 1]);
	}

	cout << n - ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}