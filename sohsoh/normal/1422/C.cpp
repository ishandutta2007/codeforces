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

ll X[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> s;

	X[0] = 1;
	ll tp = 10;
	for (ll i = 1; i < MAXN; i++) X[i] = (X[i - 1] + (i + 1) * tp) % MOD, tp *= 10, tp %= MOD;
	ll ans = 0, p = 1;
	for (ll i = 0; i < s.size() - 1; i++) {
		ans += (ll(s[i]) - '0') * X[s.size() - i - 2] % MOD;
		ans %= MOD;
		p %= MOD;
	}


	p = 1;
	for (ll i = s.size() - 1; i > 0; i--) {
		ans += (ll(s[i] - '0')) * p % MOD * ((i * (i + 1) / 2ll) % MOD) % MOD;
		ans %= MOD;	
		p *= 10;
		p %= MOD;
	}


	cout << ans << endl;

	return 0;
}