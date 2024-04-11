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
	ll n;
	cin >> n;
	ll a[4], b[4];
	cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
	ll mx = min(a[1], b[2]) + min(a[2], b[3]) + min(a[3], b[1]), mn = n;
	vector<pll> p = {{1, 1}, {1, 3}, {2, 1}, {2, 2}, {3, 2}, {3, 3}};
	do {
		ll tans = n;
		ll ta[4] = {a[0], a[1], a[2], a[3]}, tb[4] = {b[0], b[1], b[2], b[3]};
		for (pll u : p) {
			ll x = min(ta[u.X], tb[u.Y]);
			tans -= x;
			ta[u.X] -= x;
			tb[u.Y] -= x;
		}

		mn = min(mn, tans);
	} while (next_permutation(all(p)));

	cout << mn << sep << mx << endl;
	return 0;
}