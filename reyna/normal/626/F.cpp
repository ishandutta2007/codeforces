//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 205, K = 1005, S = K * N / 4 + 505, mod = 1e9 + 7;

int read() { int x; cin >> x; return x; }

int dp[N / 2][S], odp[N / 2][S], a[N];

void add(int &a, int b) {
	a = a + b;
	if (a >= mod)
		a -= mod;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 200, k = 1000; 
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	dp[0][0] = 1;
	for (int cur = 0; cur < n; ++cur) {
//		memcpy(odp, dp, sizeof dp);
//		memset(dp, 0, sizeof dp);
		for (int op = 0; op <= min(n - cur, min(cur, n / 2 + 1)) + 1; ++op) {
			for (int val = 0; val <= min(S - 1, 500 * op + K); val++) if (dp[op][val]) {
				odp[op][val] = dp[op][val];
				dp[op][val] = 0;
			}
		}
		for (int op = 0; op <= min(n - cur, min(cur, n / 2 + 1)); ++op) {
			for (int val = 0; val <= min(S - 1, 500 * op + K); val++) if (odp[op][val]) {
				int p = 1LL * odp[op][val] * (op + 1) % mod;
				add(dp[op + 1][val + a[cur]], odp[op][val]);
				add(dp[op][val], p);
				if (op && a[cur] <= val)
					add(dp[op - 1][val - a[cur]], (add(p, -odp[op][val] + mod), p));
//				add(dp[op][val], odp[op][val]);
			}
		}
//		for (int op = 0; op <= n; ++op)
//			for (int val = 0; val < S; ++val) if (dp[op][val])
//				cout << dp[op][val] << ' ' << cur << ' ' << op << ' ' << val << endl;
	}
	int res = 0;
	for (int i = 0; i <= k; ++i)
		add(res, dp[0][i]);
	cout << res;
	
}