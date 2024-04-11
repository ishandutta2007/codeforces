#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e18 + 7;

void solve() {
	ll n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector <vector <ll> > dp(n + 1, vector <ll> (2, 0));
	dp[0][0] = b;
	dp[0][1] = INF;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			dp[i + 1][0] = min(dp[i][0] + b, dp[i][1] + a + b);
			dp[i + 1][1] = min(dp[i][0] + 2 * b + a, dp[i][1] + 2 * b);
		} else {
			dp[i + 1][1] = dp[i][1] + 2 * b;
			dp[i + 1][0] = INF;
		}
		//cout << dp[i + 1][0] << " " << dp[i + 1][1] << "\n";
	}
	//cout << ones << " " << cnt << "\n";
	cout << n * a + dp[n][0] << "\n";
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
	for (int i = 0; i < t; i++) {
		solve();
	}

}