#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define int ll
#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e18 + 666;
 
template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
 
template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
 
void run();
 
signed main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	vector<vector<int>> dp(n + 1, vector<int>(2, INF));
	dp[0][0] = 0;
	for (int i = 1; i < n + 1; ++i) {
		if (s[i - 1] == '1') {
			dp[i][1] = dp[i - 1][1] + b;
		} else {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					cmin(dp[i][j], dp[i - 1][k] + abs(j - k) * a); 
				}
				dp[i][j] += b * j;
			}
		}
	}
	cout << dp[n][0] + a * n + b * (n + 1) << endl;
}

void run() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}