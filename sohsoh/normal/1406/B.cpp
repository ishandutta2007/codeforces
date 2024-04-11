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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		vector<ll> N, P;
		ll n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			if (x > 0) P.push_back(x);
			else N.push_back(x);
		}

		sort(all(P));
		sort(all(N));
		reverse(all(N));
		ll ps = P.size(), ns = N.size();
		ll ans = -1 * INF;
		if (ps >= 5) ans = max(ans, P[ps - 1] * P[ps - 2] * P[ps - 3] * P[ps - 4] * P[ps - 5]);
		if (ps >= 4 && ns >= 1) ans = max(ans, P[0] * P[1] * P[2] * P[3] * N[0]);
		if (ps >= 3 && ns >= 2) ans = max(ans, P[ps - 1] * P[ps - 2] * P[ps - 3] * N[ns - 1] * N[ns - 2]);
		if (ps >= 2 && ns >= 3) ans = max(ans, P[0] * P[1] * N[0] * N[1] * N[2]);
		if (ps >= 1 && ns >= 4) ans = max(ans, P[ps - 1] * N[ns - 1] * N[ns - 2] * N[ns - 3] * N[ns - 4]);
		if (ns >= 5) ans = max(ans, N[0] * N[1] * N[2] * N[3] * N[4]);

		cout << ans << endl;
	}
	return 0;
}