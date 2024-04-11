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

const ll MAXN = 1e5 + 10;
const ll MOD = 998244353;

int n, k;
ll ans = 1, fact[MAXN], inv[MAXN];
string s;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> s;
	s = "1" + s;

	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
	
	int lst = 0;
	if (k == 0 || count(all(s), '1') < k) return cout << 1 << endl, 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] != '1') continue;
		
		int cnt = 1, j = i + 1;
		for (; j <= n; j++) {
			if (s[j] == '1') cnt++;
			if (cnt > k) {
				cnt--;
				break;
			}
		}

		lst++;
		j--;
		
		ans += C(cnt, j - lst + 1) - C(cnt - 1, j - i) + MOD;
		lst = i;
	}

	cout << ans % MOD << endl;
	return 0;
}