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

inline ll inv(ll a) {
	ll ans = 1, b = MOD - 2;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll dp[MAXN], s, n, A[MAXN], F[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		s += A[i];
	}

	dp[0] = n - 1;
	for (int i = 1; i < s; i++) {
		ll p = (s - i) * inv(s) % MOD * (n - 2) % MOD * inv(n - 1) % MOD;
		ll q = i * inv(s) % MOD;
		dp[i] = (q * dp[i - 1] + 1) % MOD * inv((1 - p - q + 2 * MOD) % MOD) % MOD;	
	}

	for (int i = s - 1; i >= 0; i--)
		F[i] = (dp[i] + F[i + 1]) % MOD;

	ll ans = (MOD - F[0] * (n - 1) % MOD);
	for (int i = 1; i <= n; i++)
		ans += F[A[i]];

	ans = ans % MOD * inv(n) % MOD;
	cout << ans << endl;
	return 0;
}