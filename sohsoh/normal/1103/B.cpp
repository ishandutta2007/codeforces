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

ll solve() {
	ll x = 0, y = 1;
	ll pp = 1;
	while (pp < MOD) pp *= 2;
	while (y <= pp) {
		cout << "? " << x << sep << y << endl;
		char c;
		cin >> c;
		if (c == 'x') break;
		x = y;
		y = 2 * x;
	}

	ll L = x + 1, R = y;
	while (L < R) {
		ll mid = (L + R) / 2;
		cout << "? " << x << sep << mid << endl; 
		char c;
		cin >> c;
		if (c == 'y') L = mid + 1;
		else R = mid;
	}

	cout << "! " << L << endl;
	return 0;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
		string s;
		cin >> s;
		if (s == "start") solve();
		else return 0;
	}
	return 0;
}