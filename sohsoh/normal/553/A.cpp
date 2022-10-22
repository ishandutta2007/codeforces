/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9

ll dp[MAXN], C[MAXN], fact[MAXN], inv[MAXN];

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
ll nCr(ll r, ll n) {
	return fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2, MOD);
	}
	ll k;
	cin >> k;
	for (int i = 0; i < k; i++) cin >> C[i];
	dp[0] = 1;
	ll ps = C[0];
	for (int i = 1; i < k; i++) {
		dp[i] = dp[i - 1] * nCr(ps, ps + C[i] - 1) % MOD;
		ps += C[i];	
	}

	cout << dp[k - 1] << endl;
	return 0;
}