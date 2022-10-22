#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
//#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n;

ll cross(ll x) {
	ll y = x + n / 2, lx, ly;
	if (y > n) y = x - n / 2;
	cout << "? " << x << endl;
	cin >> lx;
	cout << "? " << y << endl;
	cin >> ly;
	return lx - ly;
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll q = 29;
	cin >> n;
	ll L = 1, R = 1 + n / 2, lx, ly;
	cout << "? " << L << endl;
	cin >> lx;
	cout << "? " << R << endl;
	cin >> ly;
	ll t = lx;
	lx = lx - ly;
	ly = ly - t;
	if (lx == 0) return cout << "! " << L << endl, 0;

	while (q--) {
		ll mid = (L + R) / 2;
		t = cross(mid);
		if (t == 0) return cout << "! " << mid << endl, 0; 
		if (t < 0) {
			if (lx < 0) L = mid + 1;
			else R = mid + 1;
		} else {
			if (lx > 0) L = mid + 1;
			else R = mid - 1;
		}
	}

	cout << "! " << -1 << endl;
	return 0;
}