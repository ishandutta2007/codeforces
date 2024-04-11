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

ll n, A[MAXN];

pll lst(ll i) {
	ll cnt = 1;
	while (i < n - 1 && A[i] < A[i + 1]) i++, cnt++;
	return {i, cnt};
}

ll solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	ll P = 1;
	ll ind = 0, h = 0;
	while (ind < n - 1) {
		ll tp = 0;
		while (P > 0 && ind < n - 1) {
			P--;
			pll x = lst(ind + 1);
			ind = x.X;
			tp += x.Y;
		}

		P = tp;
		h++;
	}
	cout << h << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}