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
	ll n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	ll x = 0, y = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (y - x <= 10 * k) {
			x *= 2ll;
			y *= 2ll;
			if (s[i] == 'b') x++;
			if (t[i] == 'b') y++;	
		}

		ans += min(y - x + 1, k);
		y = y - x;
		x = 0;
	}

	cout << ans << endl;
	return 0;
}