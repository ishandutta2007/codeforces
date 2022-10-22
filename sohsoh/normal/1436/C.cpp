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

ll fact[MAXN], inv[MAXN];

ll nCr(ll r, ll n) {
	if (r > n || r < 0) return 0;
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = i * fact[i - 1] % MOD, inv[i] = poww(fact[i], MOD - 2, MOD);

	ll n, x, pos;
	cin >> n >> x >> pos;
	
	ll L = 0, R = n;
	ll lx = 0, ly = 0;
	while (L < R) {
		ll mid = (L + R) / 2;
		if (mid == pos) {
			L = mid + 1;	
		} else if (mid < pos) {
			lx++;
			L = mid + 1;
		} else {
			R = mid;
			ly++;
		}
	
	}
	
	cout << nCr(ly, n - x) * fact[ly] % MOD * nCr(lx, x - 1) % MOD * fact[lx] % MOD * fact[n - lx - ly - 1] % MOD << endl;

	return 0;
}