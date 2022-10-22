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
const ld EPS = 1e-10;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << setprecision(15) << fixed;
	ll k, d, t;
	cin >> k >> d >> t;
	
	ll rep = 1;
	if (k > d) rep = ceil(ld(k) / ld(d));
	rep *= d;
	ll x = rep + k;
	ll ans = rep * (2ll * t / (rep + k));
	ll rem = (2ll * t) % (rep + k);
	if (rem > 2 * k) return cout << ans + rem - k << endl, 0;
	cout << ld(ans) + (ld(rem) / 2) << endl;

	return 0;
}