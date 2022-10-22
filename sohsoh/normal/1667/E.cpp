#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e5 + 10;
const ll MOD = 998244353;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll fact[MAXN], inv[MAXN], n;

inline ll C(ll k, ll n) {
	if (n < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	inv[0] = fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = poww(fact[i], MOD - 2);
	}

	cin >> n;
	ll s = 0, c = (n + 1) / 2;

	vector<ll> ans;
	for (int i = 1; i <= n; i++) {
		ll x = 1;
		if (i < n) {
			// sigma j = c - 1 -> i - 1: C(j, i - 1) * j! * (n - j - 2)! * (n - i)
			x = fact[i - 1] * (n - i) % MOD;	
			// sigma j = c - 1 -> i - 1: (n - j - 2)! / (i - 1 - j)! 
			// sigma j = c - 1 -> i - 1: C(i - j - 1, n - j - 2) / (n - i - 1)!
			x = x * fact[n - i - 1] % MOD; // RTE	
			// sigma j >= c - 1: C(n - i - 1, n - 2 - j)
			// sigma j >= 1: C(n - i - 1, n - c - j)
			// C(n - i, n - c)
			x = x * C(n - i, n - c) % MOD;	
		} else x = fact[n - 1];

		x = (x - s * poww(n - i + 1, MOD - 2) % MOD + MOD) % MOD;
		ans.push_back(x);
		s = (s + x) % MOD;
	}

	reverse(all(ans));
	for (ll e : ans)
		cout << e << sep;
	cout << endl;
	return 0;
}