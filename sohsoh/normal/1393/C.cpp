/*
    Soheil Mohammadkhani
    final test contest on vim
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

	ll mx = 0, mx_cnt = 0, s = 0;
	for (pll e : mp) {
		if (e.Y > mx) {
			mx_cnt = 1;
			mx = e.Y;
		} else if (e.Y == mx) {
			mx_cnt++;
		}

		s += e.Y;
	}

	s -= mx;
	s -= mx_cnt;
	s++;
	s /= (mx - 1);
	cout << s << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}