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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		b >>= 1;
		a = a * a % MOD;
	}

	return ans;
}

ll F[MAXN], fact[MAXN], inv[MAXN], n, k, q, cnt[MAXN], ans;
vector<int> D[MAXN];

inline ll C(ll k, ll n) {
	if (k < 0 || k > n) return 0;
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		F[i] += i;
		D[i].push_back(i);
		for (int j = 2 * i; j < MAXN; j += i)
			F[j] -= F[i], D[j].push_back(i);
		fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
	}

	cin >> n >> k >> q;
	for (int i = 0; i < n + q; i++) {
		int x;
		cin >> x;
		for (int e : D[x]) {
			ans += F[e] * C(k - 1, cnt[e]) % MOD;
			if (ans >= MOD) ans -= MOD;
			cnt[e]++;
		}

		if (i >= n) cout << ans << endl;
	}
	return 0;
}