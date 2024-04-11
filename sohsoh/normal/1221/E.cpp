/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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
	ll a, b;
	cin >> a >> b;
	ll bd = -1, cnt = 0;
	ll z = 0;
	
	ll n;
	string s;
	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++) {
		char c = s[i];
		if (c == '.') cnt++;
		else if (cnt > 0) {
			if (cnt >= b && cnt < a) return cout << "NO" << endl, 0;
			else if (cnt >= 2 * b) {
				if (bd >= 0) return cout << "NO" << endl, 0;
				else bd = cnt;
			} else if (cnt >= a) z++;

			cnt = 0;
		}
	}

	if (cnt > 0) {
		if (cnt >= b && cnt < a) return cout << "NO" << endl, 0;
		else if (cnt >= 2 * b) {
			if (bd >= 0) return cout << "NO" << endl, 0;
			else bd = cnt;
		} else if (cnt >= a) z++;
	}

	if (bd < 0) {
		if (z & 1) cout << "YES" << endl, 0;
		else cout << "NO" << endl;
		return 0;
	}

	for (ll i = 0; i <= bd - a; i++) {
		ll j = bd - a - i;
		ll x = 1;

		if (i < a && i >= b) continue;	
		if (j < a && j >= b) continue;	
		if (max(i, j) >= 2 * b) continue;
		if (i >= a) x++;
		if (j >= a) x++;
		
		if ((z + x) & 1) return cout << "YES" << endl, 0;
	}
	
	cout << "NO" << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();

	return 0;
}