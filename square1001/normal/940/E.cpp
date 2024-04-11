#include <iostream>
#include <algorithm>
using namespace std;
int n, m, cl, cr, a[100009], st[100009]; long long dp[100009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		while (cr > cl && a[st[cr - 1]] > a[i]) cr--;
		st[cr++] = i;
		if (i >= m) {
			sum -= a[i - m];
			if (st[cl] == i - m) cl++;
		}
		dp[i + 1] = dp[i] + a[i];
		if (i >= m - 1) {
			dp[i + 1] = min(dp[i + 1], dp[i - m + 1] + sum - a[st[cl]]);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}