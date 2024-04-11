/*
    Soheil Mohammadkhani
    Test contest on vim :)
*/
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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], B[MAXN];

ll solve() {
	ll n;
	cin >> n;
	map<ll, ll> mp;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (mp.find(x) == mp.end()) mp.insert({x, 0});
		mp[x]++;
	}

	ll ans = 0;
	for (int s = 0; s <= 2 * n; s++) {
		ll k = 0;
		for (pll e : mp) {
			ll p = s - e.X;
			if (mp.find(p) == mp.end()) continue;
			if (p == e.X) k += 2 * floor(e.Y / ld(2));
			else k += min(e.Y, mp[p]);
		}


		ans = max(ans, k / 2);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}

// Save your code before compile and sumbit :)