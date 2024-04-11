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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 40;

ll cnt[LOG];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		fill(cnt, cnt + LOG, 0);
		ll n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			ll lst = 0;
			ll j = 0;
			while (x > 0) {
				if (x & 1) lst = j;
				x /= 2;
				j++;
			}

			cnt[lst]++;
		}

		ll ans = 0;
		for (int i = 0; i < LOG; i++) {
			ans += cnt[i] * (cnt[i] - 1) / 2;
		}

		cout << ans << endl;
	}
	return 0;
}