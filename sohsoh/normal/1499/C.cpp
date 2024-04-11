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

ll C[MAXN];

inline int solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> C[i];
	ll ans = INF;
	ll h_sum = C[1], v_sum = 0, h_min = C[1], v_min = INF;
	for (int i = 2; i <= n; i++) {
		if (i & 1) {
			h_sum += C[i];
			h_min = min(h_min, C[i]);
			ans = min(ans, v_sum + h_sum + (n - i / 2 - 1) * h_min + (n - i / 2) * v_min);
		} else {
			v_sum += C[i];
			v_min = min(v_min, C[i]);
			ans = min(ans, v_sum + h_sum + (n - i / 2) * v_min + (n - i / 2) * h_min);
		}
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}