// Sohsoh84 :)))))
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

const ll MAXN = 6e5 + 10;
const ll MOD = 1e9 + 7;

ll n, L, R, fact[MAXN], inv[MAXN];

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

inline void solve() {
	cin >> n >> L >> R;
	ll  ans = 0;

	deque<ll> dq;
	for (int i = 1; i <= n; i++) dq.push_back(i);

	ll pk = 0;
	while (!dq.empty()) {
		ll mx = min(dq.front() - L, R - dq.back());
		ans += (mx - pk) * C(n / 2 - dq.front() + 1, dq.size());
		if (n & 1) ans += (mx - pk) * C((n + 1) / 2 - dq.front() + 1, dq.size());
		ans %= MOD;
		
		while (!dq.empty() && dq.front() - L == mx) dq.pop_front();
		while (!dq.empty() && R - dq.back() == mx) dq.pop_back();
		pk = mx;
	}
	
	ans += max(0ll, min(R - n / 2, n / 2 + 1 - L) - pk);
	if (n & 1) ans += max(0ll, min(R - (n + 1) / 2, (n + 1) / 2 + 1 - L) - pk);
	cout << ans % MOD << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = inv[0] = 1;
	for (int i = 1; i < MAXN; i++)
		fact[i] = fact[i - 1] * i % MOD, inv[i] = poww(fact[i], MOD - 2);
	
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}