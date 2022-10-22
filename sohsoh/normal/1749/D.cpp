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

const ll MAXN = 1e6 + 10;
const ll MOD = 998244353;
const ll LOG = 1000;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	a %= MOD;

	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline bool is_prime(int n) {
	if (n == 1) return false;
	for (int j = 2; j < n; j++)
		if (n % j == 0)
			return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += poww(m, i);
	ans %= MOD;

	ans = (ans - m % MOD + MOD) % MOD;
	vector<int> primes;
	ll f = 1, tans = m % MOD;
	for (int i = 2; i <= n && f <= m; i++) {
		if (is_prime(i)) f = f * i;
		tans = tans * ((m / f) % MOD) % MOD;
		ans = (ans + MOD - tans) % MOD;
	}

	cout << ans << endl;
	return 0;
}