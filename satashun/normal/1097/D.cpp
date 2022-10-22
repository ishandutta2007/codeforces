#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()
#define dump(x) cout << #x << " = " << (x) << endl

const ll MOD = 1000000007;
const int MX = 100;
const int MK = 10010;

ll inv[MX], fact[MX], ifact[MX];

void init() {
    inv[1] = 1;
    for (int i = 2; i < MX; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MX; ++i) {
        fact[i] = fact[i-1] * i % MOD;
        ifact[i] = ifact[i-1] * inv[i] % MOD;
    }
}

ll n;
int k;

ll dp[MK][MX];

int main() {
	init();
	cin >> n >> k;

	vector<pair<ll, int>> vec;

	for (ll i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) {
				n /= i;
				++cnt;
			}
			vec.eb(i, cnt);
		}
	}

	if (n != 1) {
		vec.eb(n, 1);
	}

	ll ans = 1;
	for (auto e : vec) {
		ll p = e.fi;
		int v = e.se;

		for (int i = 0; i <= k; ++i) {
			for (int j = 0; j < MX; ++j) {
				dp[i][j] = 0;
			}
		}
		dp[0][v] = 1;

		for (int i = 1; i <= k; ++i) {
			for (int j = 0; j <= v; ++j) if (dp[i-1][j] != 0) {
				ll val = dp[i-1][j] * inv[j+1] % MOD;
				dp[i][0] += val;
				if (dp[i][0] >= MOD) {
					dp[i][0] -= MOD;
				}
				dp[i][j+1] -= val;
				if (dp[i][j+1] < 0) {
					dp[i][j+1] += MOD;
				}
			}
			ll ac = 0;
			for (int j = 0; j < MX; ++j) {
				ac += dp[i][j];
				if (ac >= MOD) {
					ac -= MOD;
				}
				dp[i][j] = ac;
			}
		}

		ll coef = 0;
		ll cur = 1;
		p %= MOD;

		for (int j = 0; j <= v; ++j) {
			coef = (coef + cur * dp[k][j]) % MOD;
			cur = cur * p % MOD;
		}

		ans = ans * coef % MOD;
	}

	cout << ans << endl;

	return 0;
}