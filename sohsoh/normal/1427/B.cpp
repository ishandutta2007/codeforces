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

ll A[MAXN], n;

ll solve() {
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<ll> v;
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] != s[i - 1]) {
			if (s[i] == 'W') v.push_back(cnt);
			cnt = 0;
		}

		cnt++;
	}

	if (s.back() == 'L') v.push_back(cnt);
	ll ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'W') {
			ans++;
			if (i > 0 && s[i - 1] == 'W') ans++;
		}
	}

	ll beg = 0, en = 0;
	if (ans == 0) {
		if (k > 0) cout << 1 + 2 * min(n - 1, k - 1) << endl;
		else cout << 0 << endl;
		return 0;
	}
	if (s[0] == 'L') beg = v[0], v.erase(v.begin());
	if (s.back() == 'L') en = v.back(), v.pop_back();
	sort(all(v));
	for (ll u : v) {
		if (u <= k) ans += 2 * u + 1, k -= u;
		else {
			ans += 2 * k;
			k = 0;
		}
	}

	ll x = min(beg, k);
	ans += 2 * x;
	k -= x;
	x = min(en, k);
	k -= x;
	ans += 2 * x;
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