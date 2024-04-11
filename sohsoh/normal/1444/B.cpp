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
const ll MOD = 998244353; // 1e9 + 9;

ll fact(ll n) {
	if (n == 1 || n == 0) return 1;
	return n * fact(n - 1) % MOD;
}

ll A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) cin >> A[i];
	sort(A, A + 2 * n);
	ll ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) ans -= A[i];
		else ans += A[i];
	}

	ans %= MOD;
	cout << ans * fact(2 * n) % MOD * poww(fact(n), MOD - 2, MOD) % MOD * poww(fact(n), MOD - 2, MOD) % MOD << endl;
	return 0;
}