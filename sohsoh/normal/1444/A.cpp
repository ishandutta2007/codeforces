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

bool is_prime(ll n) {
	if (n == 1) return false;
	ll sq = sqrt(n);
	for (int i = 2; i <= sq; i++) if (n % i == 0) return false;
	return true;
}

int solve() {
	ll p, q;
	cin >> p >> q;
	if (p % q) return cout << p << endl, 0;
	ll sq = sqrt(q);
	vector<ll> pf;
	for (int i = 1; i <= sq; i++) {
		if (q % i == 0) {
			if (is_prime(i)) pf.push_back(i);
			if (is_prime(q / i)) pf.push_back(q / i);	
		}
	}

	ll ans = 1;
	for (ll e : pf) {
		ll tp = p;
		while (tp % q == 0) tp /= e;
		ans = max(ans, tp);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}