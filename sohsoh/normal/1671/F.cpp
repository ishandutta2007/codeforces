#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const int MAXN = 27;
const int MAXK = 13;
const int MOD = 998244353;

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
}

inline void sohsoh(int& a) { // orz
	if (a < 0) a += MOD;
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

int dp[MAXN][MAXK][MAXK][MAXN], fp[MAXN][MAXK][MAXK], f[MAXN][MAXK][MAXK], ks[MAXK][MAXN][MAXK][MAXK]; 
ll inv[MAXN];
// ans:  cnt, tot_len, a, b

inline ll C(ll k, ll n) {
	if (k > n || k < 0) return 0;

	ll ans = 1;
	for (int i = 1; i <= k; i++)
		ans = ans * (n - i + 1) % MOD *inv[i] % MOD;
	return ans;
}

inline int solve() {
	int n, a, b;
	cin >> n >> a >> b;
	
	int ans = 0;
	for (int i = 1; i < MAXK; i++) {
		for (int l = 0; l <= min(n, MAXN - 1); l++) {
			ans = (ans + 1ll * ks[i][l][a][b] * C(i, n - l + i)) % MOD;
		}
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < MAXN; i++)
		inv[i] = poww(i, MOD - 2);

	for (int i = 1; i < MAXN; i++) {
		dp[i][0][0][i] = fp[i][0][0] = f[i][0][0] = 1;
		for (int a = 1; a < MAXK; a++) {
			for (int b = 1; b <= a; b++) {
				for (int j = max(1, i - a); j <= i; j++) {
					for (int k = 0; k < j; k++)
						mkey(dp[i][a][b][j] += dp[i - 1][a - (i - j)][b][k]);	
				
					for (int k = j; k < i; k++)
						mkey(dp[i][a][b][j] += dp[i - 1][a - (i - j)][b - 1][k]);
			
					mkey(f[i][a][b] += dp[i][a][b][j]);
					mkey(fp[i][a][b] += dp[i][a][b][j]);
				}
			}
		}
	}

	for (int i = 1; i < MAXN; i++)
		for (int a = 0; a < MAXK; a++)
			for (int b = 0; b < MAXK; b++)
				for (int j = 1; j < i; j++)
					for (int a1 = 0; a1 <= a; a1++)
						for (int b1 = 0; b1 <= b; b1++)
							f[i][a][b] = (f[i][a][b] - 1ll * f[j][a1][b1] * fp[i - j][a - a1][b - b1] % MOD + MOD) % MOD;	

	ks[0][0][0][0] = 1;
	for (int i = 1; i < MAXK; i++) 
		for (int l = 0; l < MAXN; l++) 
			for (int a = 0; a < MAXK; a++) 
				for (int b = 0; b < MAXK; b++) 
					for (int tl = 2; tl <= l; tl++) 
						for (int ta = 1; ta <= a; ta++) 
							for (int tb = 1; tb <= b; tb++) 
								ks[i][l][a][b] = (ks[i][l][a][b] + 1ll * ks[i - 1][l - tl][a - ta][b - tb] * f[tl][ta][tb] % MOD) % MOD;							

	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}