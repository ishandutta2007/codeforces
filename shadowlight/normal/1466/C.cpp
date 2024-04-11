#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9 + 7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();

	vector <vector <int>> dp(n + 2, vector<int>(4, INF));
	dp[1][3] = 0;
	for (int i = 0; i < n; ++i) {
		for (int mask = 0; mask < 4; ++mask) {
			if (dp[i + 1][mask] == INF) continue;
			for (int t = 0; t < 2; ++t) {
				int nmask = (mask % 2 * 2 + t);
				if (!t && !(mask & 1) && s[i] == s[i - 1]) continue;
				if (!t && !(mask & 2) && s[i] == s[i - 2]) continue;
				dp[i + 2][nmask] = min(dp[i + 2][nmask], dp[i + 1][mask] + t);
			}
		}
	}
	int res = INF;
	for (int i = 0; i < 4; ++i) {
		res = min(res, dp[n + 1][i]);
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}