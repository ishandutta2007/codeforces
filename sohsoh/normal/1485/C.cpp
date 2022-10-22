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

ll x, y;

inline int solve() {
	cin >> x >> y;
	ll b = 1;
       	ll ans = 0;

	while (x / (b + 1) >= b - 1 && b <= y) {
		ans += b - 1;
		b++;
	}
	
	ll c = x / (b + 1);
	while (c && b <= y) {
		ll L = b, R = y;
		while (L < R) {
			ll mid = (L + R + 1) >> 1;
			if (x / (mid + 1) >= c) L = mid;
			else R = mid - 1;	
		}

		ll mx_b = L;

		L = b, R = y;
		while (L < R) {
			ll mid = (L + R) >> 1;
			if (x / (mid + 1) > c) L = mid + 1;
			else R = mid;	
		}

		ll mn_b = L;	
		if (x / (mn_b + 1) != c || x / (mx_b + 1) != c) {
			c--;
			continue;
		}
		
		ans += c * (mx_b - mn_b + 1);
		c--;
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