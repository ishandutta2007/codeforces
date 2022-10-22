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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll x = n / 3, md = n % 3;
		if (md == 0) cout << x << sep << 0 << sep << 0 << endl;
		if (md == 1) {
			if (x < 2) cout << -1 << endl;
			else {
				cout << x - 2 << sep << 0 << sep << 1 << endl;
			}
		} if (md == 2) {
			if (x < 1) cout << -1 << endl;
			else cout << x - 1 << sep << 1 << sep << 0 << endl;
		}
	}
	return 0;
}