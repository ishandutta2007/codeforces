#include <bits/stdc++.h>
 
using namespace std;
 
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> plll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define endl                        '\n'

 
const ll MAXN = 1e6 + 10;
const ll INF = 1e7;
const ll MOD = 998244353; // 1e9 + 9;

ll n, k, m, fen[MAXN] = {0}, dp[MAXN], ps[MAXN], F[MAXN];
vector<plll> v;

void update(int ind, int val) {
	for (++ind; ind < MAXN; ind += ind & -ind) fen[ind] += val;
}

void range_update(int l, int r, int val) {
	update(l, val);
	update(r + 1, -val);
}

ll point(int ind) {
	ll ans = 0;
	for (++ind; ind > 0; ind -= ind & -ind) ans += fen[ind];
	return ans;
}

void mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	scanf("%lld %lld %lld", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		ll l, r, x;
		scanf("%lld %lld %lld", &l, &r, &x);
		v.push_back({{l, r}, x});
	}

	ll ans = 1;
	for (int bt = 0; bt < k; bt++) {
		memset(fen, 0, sizeof fen);
		memset(dp, 0, sizeof dp);
		memset(ps, 0, sizeof ps);
		memset(F, 0, sizeof F);
		
		vector<pll> zseg;
		for (plll e : v) {
			if (e.Y & (1 << bt)) range_update(e.X.X, e.X.Y, -1 * INF);
			else range_update(e.X.X, e.X.Y, 1), zseg.push_back({e.X.X, e.X.Y});
		}

		for (pll e : zseg) F[e.Y + 1] = max(F[e.Y + 1], e.X);
		for (int i = 1; i < MAXN; i++) F[i] = max(F[i], F[i - 1]);
		dp[0] = 1;
		ps[0] = 1;
		for (int i = 1; i <= n + 1; i++) {
			ll x = point(i);
			if (x >= 0) {
				dp[i] = ps[i - 1];
				if (F[i] > 0) mkey(dp[i] -= ps[F[i] - 1]);
			} else dp[i] = 0;

			mkey(ps[i] = (ps[i - 1] + dp[i]));
		}

		ans *= dp[n + 1];
		ans %= MOD;
	}


	printf("%lld", ans);
	return 0;
}