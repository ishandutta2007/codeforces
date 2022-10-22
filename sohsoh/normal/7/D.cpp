// \_()_/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 6e6 + 10;
const ll MOD = 1e9 + 7;

int n, dp[MAXN];
ll hsh[MAXN], hsh_r[MAXN], p_pow[MAXN], p;
string s, s_r;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	s_r = s;
	reverse(all(s_r));
	n = s.size();

	s = "#" + s;
	s_r = "#" + s_r;
	p = rng() % MOD;

	p_pow[0] = 1;
	for (int i = 1; i <= n; i++) {
		hsh[i] = (hsh[i - 1] + p_pow[i - 1] * s[i]) % MOD;
		hsh_r[i] = (hsh[i - 1] + p_pow[i - 1] * s_r[i]) % MOD;
		p_pow[i] = p_pow[i - 1] * p % MOD;
	}

	for (int i = n; i > 0; i--)
		hsh_r[i] = (hsh_r[i + 1] * p + s_r[i]) % MOD;

	ll ans = dp[1] = 1;
	for (int i = 2; i <= n; i++)
		if (hsh[i] == hsh_r[n - i + 1])
			ans += dp[i] = dp[i / 2] + 1;
	cout << ans << endl;
	return 0;
}