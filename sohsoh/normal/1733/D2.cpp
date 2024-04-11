#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;
#define int			ll

const ll MAXN = 5e3 + 10;

ll A[MAXN], B[MAXN], C[MAXN], dp[2][MAXN][2];

inline void f(ll& a, ll b) {
	a = min(a, b);
}

inline int solve() {
	ll n, x, y;
	cin >> n >> x >> y;

	vector<int> vec;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		A[i] = int(c - '0');
	}

	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		B[i] = int(c - '0');
		C[i] = (A[i] ^ B[i]);
	}

	if (count(C + 1, C + n + 1, 1) & 1) return cout << -1 << endl, 0;
	if (x > y) {
		for (int i = 1; i <= n; i++)
			if (C[i]) vec.push_back(i);

		if (vec.empty()) return cout << 0 << endl, 0;
		if (vec.size() > 2 || vec[0] < vec[1] - 1) cout << 1ll * vec.size() / 2 * y << endl;
		else cout << min(2 * y, x) << endl;
		return 0;
	}

	x *= 2;
	y *= 2;
	memset(dp, 63, sizeof dp);
	dp[1][C[1]][C[1]] = 0;
	dp[1][1 - C[1]][1 - C[1]] = y / 2; 

	for (int i = 2; i <= n; i++) {
		int ind = i & 1;
		memset(dp[ind], 63, sizeof dp[ind]);
		int r = C[i];

		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 2; k++) {
				f(dp[ind][j + r][r], dp[ind ^ 1][j][k]);
				if (j - k + (r ^ 1) + (k ^ 1) >= 0) f(dp[ind][j - k + (r ^ 1) + (k ^ 1)][(r ^ 1)], dp[ind ^ 1][j][k] + x);
			}	
		}

		for (int j = 0; j <= i; j++) {
			for (int k = 0; k < 2; k++) {
				f(dp[ind][j - k + (k ^ 1)][(k ^ 1)], dp[ind][j][k] + y / 2);
			}	
		}

	}

	ll ans = ll(1e18);
	for (int j = 0; j < MAXN; j += 2)
		ans = min({ans, dp[n & 1][j][0] + (j / 2) * y, dp[n & 1][j][1] + (j / 2) * y});

	cout << ans / 2 << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}