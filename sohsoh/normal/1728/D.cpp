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

const ll MAXN = 2e3 + 10;

int dp[MAXN][MAXN], n;
string s;

// 0, 1, 2

int f(char a, char b, int c) {
	if (c != 1) return c;
	if (a == b) return 1;
	return a < b ? 0 : 2;
}

inline int solve() {
	cin >> s;
	n = s.size();
	s = "." + s;

	for (int r = 2; r <= n; r++) {
		dp[r - 1][r] = (s[r] == s[r - 1] ? 1 : 0);
		for (int l = r - 3; l > 0; l -= 2) {
			dp[l][r] = min(
				max(f(s[l], s[l + 1], dp[l + 2][r]), f(s[l], s[r], dp[l + 1][r - 1])),
				max(f(s[r], s[r - 1], dp[l][r - 2]), f(s[r], s[l], dp[l + 1][r - 1]))
			);
		}
	}

	if (dp[1][n] == 0) cout << "Alice" << endl;
	else if (dp[1][n] == 1) cout << "Draw" << endl;
	else cout << "Bob" << endl;

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}