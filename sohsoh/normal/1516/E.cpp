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

const ll MAXN = 400 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

inline void mkey(ll& a) {
	if (a < 0) a += MOD;
	if (a >= MOD) a -= MOD;
}

inline ll poww(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}

	return ans;
}

ll k, n, dp[MAXN][MAXN], fact[MAXN], C[MAXN][MAXN], inv[MAXN], ans[MAXN];

inline void FillDP() {
	dp[0][0] = 1;
	for (int i = 1; i < MAXN; i++) {
		for (int j = 1; j < MAXN; j++) {
			for (int k = 2; k <= i; k++) {
				mkey(dp[i][j] += dp[i - k][j - 1] * C[k - 1][i - 1] % MOD * fact[k - 1] % MOD);
			}
		
		}
	} 
}

inline ll C2(ll k, ll n) {
	if (k > n || k < 0) return 0;
	ll ans = 1;
	for (int i = n; i > n - k; i--) ans = ans * i % MOD;
	return ans * inv[k] % MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	C[0][0] = fact[0] = inv[0] = 1;
	for (int j = 1; j < MAXN; j++) {
		for (int i = 0; i <= j; i++) {
			C[i][j] = C[i][j - 1];
			if (i) mkey(C[i][j] += C[i - 1][j - 1]);
		}

		fact[j] = j * fact[j - 1] % MOD;
		inv[j] = poww(fact[j], MOD - 2);
	}
	
	FillDP();
	
	cin >> n >> k;
	ans[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j < MAXN; j++) {
			int k = i + j;
			if (k > MAXN) continue;
			mkey(ans[i] += dp[k][j] * C2(k, n) % MOD);
		}

		if (i > 1) mkey(ans[i] += ans[i - 2]);
		cout << ans[i] << sep;
	}

	cout << endl;
	return 0;
}