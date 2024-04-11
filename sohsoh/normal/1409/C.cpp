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

ll solve() {
	ll n, x, y;
	vector<ll> ans;
	cin >> n >> x >> y;
	ll d = 1;
	for (int i = 1; i <= n - 1; i++) 
		if ((y - x) % i == 0)
			d = i;
	ll rem = n - d - 1;
	d = (y - x) / d;
	ll t = x - d;
	for (int i = x; i <= y; i += d) cout << i << sep;
	while (rem > 0 && t > 0) {
		cout << t << sep;
		rem--;
		t -= d;
	}

	t = y + d;
	while (rem > 0) {
		cout << t << sep;
		rem--;
		t += d;
	}	

	cout << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}