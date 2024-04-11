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

ll solve() {
	ll n, x;
	cin >> n >> x;
	string s;
	cin >> s;

	ll tot = count(all(s), '0') - count(all(s), '1');
	ll bal = 0, ans = 0;
	if (tot == 0) {
		for (int i = 0; i < n; i++) {
			if (bal == x) return cout << -1 << endl, 0;
			if (s[i] == '0') bal++;
			else bal--;
			if (bal == x) return cout << -1 << endl, 0;
		}

		return cout << 0 << endl, 0;
	}	

	if (x % tot == 0 && x / tot >= 0) ans++;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == '0') bal++;
		else bal--;
		if ((x - bal) % tot == 0 && (x - bal) / tot >= 0) ans++;
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}