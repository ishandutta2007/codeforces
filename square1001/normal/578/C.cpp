#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
int n, a[200009]; double dp[200009];
double solve(double x) {
	double ret = 0.0;
	for (int i = 0; i < n; i++) dp[i + 1] = max(dp[i] + a[i] - x, 0.0), ret = max(ret, dp[i + 1]);
	for (int i = 0; i < n; i++) dp[i + 1] = max(dp[i] - a[i] + x, 0.0), ret = max(ret, dp[i + 1]);
	return max(ret, dp[n]);
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	double l = -1.0e+10, r = 1.0e+10;
	for (int i = 0; i < 150; i++) {
		double m1 = (l * 2 + r) / 3.0;
		double m2 = (l + r * 2) / 3.0;
		if (solve(m1) < solve(m2)) r = m2;
		else l = m1;
	}
	cout << fixed << setprecision(15) << solve(l) << endl;
	return 0;
}