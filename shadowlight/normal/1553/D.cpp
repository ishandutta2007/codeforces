#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	vector <vector<int>> dp(n + 1, vector<int>(2, -1));
	dp[0][0] = 0;
	dp[0][1] = -1;

	for (int i = 0; i < n; ++i) {
		for (int w = 0; w < 2; ++w) {
			if (dp[i][w] == -1) continue;

			if (dp[i][w] < t.size() && t[dp[i][w]] == s[i]) {
				dp[i + 1][w ^ 1] = max(dp[i + 1][w ^ 1], dp[i][w] + 1);
			}
			if (i + 2 <= n) {
				dp[i + 2][w] = max(dp[i][w], dp[i + 2][w]);
			}
		}
		if (t[0] == s[i]) {
			dp[i + 1][1] = max(dp[i + 1][1], 1);
		}
		dp[i + 1][0] = max(dp[i + 1][0], 0);
	}
	cout << (dp[n][t.size() % 2] == t.size() ? "YES\n" : "NO\n");
}



int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}