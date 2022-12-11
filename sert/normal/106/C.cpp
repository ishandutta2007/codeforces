#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

void add(vector<int> &dp, int w, int c) {
	for (int i = (int)dp.size() - w; i >= 0; i--) {
		dp[i + w] = max(dp[i + w], dp[i] + c);
	}
}

void solve() {
	int n, m, c0, d0;
	cin >> n >> m >> c0 >> d0;
	vector<int> dp(n + 1, 0);
	for (int i = 0; i + c0 <= n; i++) dp[i + c0] = dp[i] + d0;
	for (int i = 0; i < m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = 0; j < a / b; j++) {
			add(dp, c, d);
		}
	}
	cout << dp.back() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
#ifdef MADE_BY_SERT
	int T = 2;
	for (int i = 1; i < T; i++) solve();	
#endif
}