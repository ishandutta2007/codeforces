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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 8e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; 
ll P = 31;

ll n, hsh[MAXN], P_pow[MAXN], P_pow_inv[MAXN];
int ans[MAXN], dp[MAXN][MAXN], mx[MAXN][MAXN], Lg[MAXN];
string s;

inline ll Substr(int L, int R) {
	return (hsh[R] - hsh[L - 1] + MOD) % MOD * P_pow_inv[L - 1] % MOD;
}

inline void Prep() {
	P_pow[0] = P_pow_inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		P_pow[i] = P * P_pow[i - 1] % MOD;
		P_pow_inv[i] = poww(P_pow[i], MOD - 2, MOD);
		hsh[i] = P_pow[i] * int(s[i] - 'a' + 1) + hsh[i - 1] % MOD;
		hsh[i] %= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	P = rng() % int(1e8) + 1;

	cin >> s;
	n = s.size();
	s = '.' + s;
	Prep();
	Lg[0] = 0;
	for (int i = 1; i <= n; i++) Lg[i] = 1 + Lg[i / 10];
	for (int L = n; L > 0; L--) {
		memset(dp[L], 63, sizeof dp[L]);
		for (int k = 1; L + k - 1 <= n; k++) {
			mx[L][k] = L + k - 1;
			if (L + 2 * k - 1 <= n && Substr(L, L + k - 1) == Substr(L + k, L + 2 * k - 1)) mx[L][k] = max(mx[L][k], mx[L + k][k]);
			for (int R = L + k - 1; R <= mx[L][k]; R += k) {	
				dp[L][R] = min(dp[L][R], k + Lg[(R - L + 1) / k]);
			}
		}
	}

	memset(ans, 63, sizeof ans);
	for (int i = 1; i <= n; i++) {
		ans[i] = dp[1][i];
		for (int j = 2; j <= i; j++)
			ans[i] = min(ans[i], ans[j - 1] + dp[j][i]);
	}

	cout << ans[n] << endl;
	return 0;
}