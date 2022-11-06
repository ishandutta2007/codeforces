#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define all(a) begin(a), end(a)
#define sz(a) ((int) (a).size())

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

const int N = 3e5 + 7;

void add(ll &a, ll b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

ll pw(ll a, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1, a = a * a % MOD) {
		if (n & 1) res = res * a % MOD;
	}
	return res;
}

ll f[N], rf[N];

ll cnk(int n, int k) {
	return f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

ll dp[N];
ll f2[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[0] = 1;
	for (int i = 1; i < N; ++i) {
		f[i] = f[i - 1] * i % MOD;
	}
	for (int i = 0; i < N; ++i) {
		rf[i] = pw(f[i], MOD - 2);
	}
	dp[0] = 1;
	for (int i = 1; i < N; ++i) {
		dp[i] = dp[i - 1];
		if (i >= 2) add(dp[i], dp[i - 2] * (i - 1) % MOD);
	}
	f2[0] = 1;
	for (int i = 2; i < N; ++i) {
		f2[i] = f2[i - 2] * (i - 1) % MOD;
		(f2[i] *= 2) %= MOD;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		// p1 p2 .. pk n
		// pi >= 0
		// pi <= pi+1
		// p[i+1]-p[i]>=2
		// 

		ll ans = 0;
		for (int i = 0; 2 * i <= n; i += 2) {
			int sum = n - 2 * i;
			int cnt = i + 1;
			add(ans, cnk(sum + cnt - 1, cnt - 1) * dp[n - 2 * i] % MOD * f2[i] % MOD);
		}
		cout << ans << "\n";
	}
	return 0;
}