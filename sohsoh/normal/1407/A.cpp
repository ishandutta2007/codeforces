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

ll A[MAXN], n;

ll solve() {
	cin >> n;
	vector<ll> O, Z;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x) O.push_back(i);
		else Z.push_back(i);
	}

	if (O.size() <= n / 2) {
		ll x = n - O.size();
		cout << x << endl;
		for (int i = 0; i < x; i++) cout << 0 << sep;
		cout << endl;
	} else {
		ll x = n - Z.size();
		x -= x % 2;
		cout << x << endl;
		for (int i = 0; i < x; i++) cout << 1 << sep;
		cout << endl;	
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}