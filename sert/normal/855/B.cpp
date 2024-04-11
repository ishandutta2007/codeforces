#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
const ll INF = (ll)3e18 + 41;
// const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void dfs(int v, int d, const vector<vector<int>> &es, vector<int> &dep) {
	dep[d] ^= 1;
	for (int w : es[v]) dfs(w, d + 1, es, dep);
}

void solve() {
	int n, q[3];
	cin >> n >> q[0] >> q[1] >> q[2];
	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<ll>> dp(4, vector<ll>(n + 1, -INF));

	for (int i = 0; i <= n; i++) dp[0][i] = 0;
	for (int num = 1; num <= 3; num++) {
		ll qq = q[num - 1];
		for (int i = 0; i < n; i++) {
			dp[num][i + 1] = max(dp[num][i], dp[num - 1][i + 1] + a[i] * qq);
		}
	}
	cout << dp[3][n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}