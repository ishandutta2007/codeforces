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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, q, A[MAXN], ps[MAXN];

inline int solve() {
	vector<pll> v;
	cin >> n >> q;
	v.push_back({0, 0});
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		ps[i] = ps[i - 1] + A[i];
		if (v.back().X < ps[i]) v.push_back({ps[i], i});
	}

	ll tot = ps[n];
	while (q--) {
		ll x;
		cin >> x;
	
		if (tot <= 0 && v.back().X < x) {
			cout << -1 << sep;
			continue;
		}

		ll ans = 0;
		x -= v.back().X;
		if (tot > 0 && x > 0) {
			ans += (x + tot - 1) / tot;
			x -= ans * tot;
			ans *= n;
		}
		x += v.back().X;
		ans += lower_bound(all(v), make_pair(x, 0ll)) -> Y;
		cout << ans - 1 << sep;
	}

	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}