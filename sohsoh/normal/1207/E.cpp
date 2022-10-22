#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define debug(x)                    cerr << #x << ": " <<  x << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << '?' << sep;
	for (int i = 0; i < 100; i++) cout << i << sep;
	cout << endl;
	ll x;
	cin >> x;
	ll ans = 0;
	for (ll i = 7; i < 14; i++) ans ^= (x & (1ll << i));
	cout << '?' << sep;
	for (ll i = 1; i <= 100; i++) cout << (i << 7ll) << sep;
	cout << endl;
	cin >> x;
	for (ll i = 0; i < 7; i++) ans ^= (x & (1ll << i));
	cout << '!' << sep << ans << endl;
	return 0;
}