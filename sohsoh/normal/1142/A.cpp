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

ll x = INF, y = -1 * INF, n, k;

void upd(ll l) {
	ll mv = n * k / __gcd(n * k, l);
	x = min(x, mv);
	y = max(y, mv);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll a, b;
	cin >> n >> k >> a >> b;
	vector<ll> v1, v2;
	for (ll i = 0; i < k; i++) {
		if (min(i, k - i) == a) v1.push_back(i);
		if (min(i, k - i) == b) v2.push_back(i);
	}
	
	for (int i = 0; i < n; i++) {
		ll l = i * k;
		if (b - a >= 0) upd(l + b - a);
		if (k - b - a >= 0) upd(l + k - b - a);
		if (b - k - a >= 0) upd(l + b - k - a);
		if (a - b >= 0) upd(l + a - b);
	}

	cout << x << sep << y << endl;
	return 0;
}