#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r, n;
	cin >> r >> n;

	vector <pair <int, int>> a(n + 1);
	vector <int> ts(n + 1);
	a[0] = {1, 1};
	ts[0] = 0;

	for (int i = 1; i <= n; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		ts[i] = t;
		a[i] = {x, y};
	}
	vector <int> dp(n + 1, 0);
	int res = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= 4 * r; ++j) {
			int pr = i - j;
			if (pr < 0) continue;
			if (abs(a[i].x - a[pr].x) + abs(a[i].y - a[pr].y) <= ts[i] - ts[pr] && (!pr || dp[pr])) {
				dp[i] = max(dp[i], dp[pr] + 1);
			}
		}
		res = max(res, dp[i]);
	}
	cout << res << "\n";
}