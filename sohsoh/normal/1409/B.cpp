#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		ll e = a + b - x - y;
		if (e <= n) cout << x * y << endl;
		else {
			ll tx = min(a - x, n);
			ll ans1 = (a - tx) * max(y, (b - (n - tx)));
			tx = min(b - y, n);
			cout << min(ans1, (b - tx) * max((a - (n - tx)), x)) << endl;
		}

	}
	return 0;
}