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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll m, n;
	cin >> m >> n;
	if (m == 1) return cout << 1 << endl, 0;
	vector<ll> v;
	for (int i = 0; i < n; i++) {
		cout << m << endl;
		ll x;
		cin >> x;
		if (x == 0) return 0;
		if (x == 1) v.push_back(-1);
		else v.push_back(1);
	}

	ll L = 1, R = m;
	ll q = 0;
	while (L < R) {
		ll mid = (L + R) / 2;
		cout << mid << endl;
		ll x;
		cin >> x;
		x *= v[q];
		if (x > 0) L = mid + 1;
		else if (x == 0) return 0;
		else R = mid - 1;
		q++;
		q %= n;	
	}

	cout << L << endl;
	return 0;
}