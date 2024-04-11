#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, t[109], d[109], p[109], id[109], dp[109][2009];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> d[i] >> p[i], id[i] = i + 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i] > d[j]) {
				swap(t[i], t[j]);
				swap(d[i], d[j]);
				swap(p[i], p[j]);
				swap(id[i], id[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d[i]; j++) {
			dp[i + 1][j] = dp[i][j];
			if (j >= t[i]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - t[i]] + p[i]);
		}
	}
	int pos = max_element(dp[n], dp[n] + d[n - 1]) - dp[n];
	cout << dp[n][pos] << endl;
	vector<int> v;
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i][pos] != dp[i + 1][pos]) v.push_back(id[i]), pos -= t[i];
	}
	reverse(v.begin(), v.end());
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	return 0;
}