#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 61;
int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<long long> dp(n);
	for (int i = 0; i < n; ++i) {
		dp[i] = abs(a[0] - (a[i] - i));
	}
	map<int, vector<int> > queries;
	for (int i = 0; i < n; ++i) {
		queries[a[i] - i].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		long long curmin = inf;
		for (pair<int, vector<int> > j : queries) {
			for (int k : j.second) {
				curmin = min(curmin, dp[k]);
			}
			for (int k : j.second) {
				dp[k] = curmin + abs(a[i] - (a[k] - k + i));
			}
		}
	}
	long long ans = *min_element(dp.begin(), dp.end());
	cout << ans << endl;
	return 0;
}