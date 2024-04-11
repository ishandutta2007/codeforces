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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		vector<ll> v;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			v.push_back(x);
		}

		if (n == 1) cout << 0 << endl;
		else {
			ll mn = *min_element(all(v)), mx = *max_element(all(v));
			vector<ll> v2;
			ll ans = mx - mn;
			for (int i = 0; i < n; i++) v2.push_back(v[i]);
			v2.erase(find(all(v2), mx));
			sort(all(v2));
			k--;
			ans += v2.back();
			v2.pop_back();
			ans += mn;
			reverse(all(v2));	
			for (int i = 0; i < min(k, (ll)v2.size()); i++) ans += v2[i];
			cout << ans << endl;
		}
	}
	return 0;
}