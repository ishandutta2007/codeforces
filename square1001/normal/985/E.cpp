#include <iostream>
#include <algorithm>
using namespace std;
int n, m, d, a[500009], dp[500009];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> d;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sum = 0, pl = 0; dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		if (i >= m - 1) sum += dp[i - m + 1];
		while (a[i] - a[pl] > d) sum -= dp[pl++];
		dp[i + 1] = (sum > 0 ? 1 : 0);
	}
	cout << (dp[n] == 1 ? "YES\n" : "NO\n");
	return 0;
}