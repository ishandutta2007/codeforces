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

const ll MAXN = 1e6 + 10;

int n, dp[MAXN][2], A[MAXN];
bool B[MAXN];

inline void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		B[i] = (c == '1');
	}

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		dp[i][1] = 0;
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if (B[i]) {
			dp[i][1] = dp[i][0] + A[i];
			dp[i][0] = max(dp[i - 1][1], dp[i - 1][0] + A[i - 1]);
		}
	}

	cout << max(dp[n][0], dp[n][1]) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}