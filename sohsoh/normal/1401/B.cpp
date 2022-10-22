/*
    Soheil Mohammadkhani
    OK, im back :)
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

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) {
		ll x1, x2, x3, y1, y2, y3;
		cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
		ll ans = min(x3, y2) * 2;
		ll x = min(x3, y2);
		x3 -= x;
		y2 -= x;
		ans -= max(0ll, min(y3 - x1 - x3, x2) * 2);
		cout << ans << endl;
	}
	
	return 0;
}