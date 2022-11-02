#include <iomanip>
#include <iostream>
using namespace std;
int n, m, x[109]; double dp[100009];
int main() {
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		sum += x[i];
	}
	dp[0] = 1.0;
	for (int i = 1; i <= n; ++i) {
		double s = 0.0;
		for (int j = i * m - m + 1; j <= i; ++j) {
			s += dp[j];
		}
		for (int j = i * m; j >= i; --j) {
			s += (j >= m ? dp[j - m] : 0) - dp[j];
			dp[j] = (s - (j >= x[i - 1] ? dp[j - x[i - 1]] : 0.0)) / (m - 1);
		}
		dp[i - 1] = 0.0;
	}
	double prob = 0.0;
	for (int i = 0; i < sum; ++i) {
		prob += dp[i];
	}
	cout << fixed << setprecision(15) << prob * (m - 1) + 1 << '\n';
	return 0;
}