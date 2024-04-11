#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	int mx = *max_element(a.begin(), a.end());
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = a.size();
	vector<bool> prime(mx + 1, true);
	prime[0] = false; prime[1] = false;
	for (int i = 2; i * i <= mx; ++i) {
		if (!prime[i]) continue;
		for (int j = i * i; j <= mx; j += i) {
			prime[j] = false;
		}
	}
	vector<vector<int> > factor(mx + 1);
	for (int i = 2; i <= mx; ++i) {
		if (!prime[i]) continue;
		for (int j = i; j <= mx; j += i) {
			factor[j].push_back(i);
		}
	}
	vector<int> pcover(mx + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < 1 << factor[a[i]].size(); ++j) {
			int mul = 1;
			for (int k = 0; k < factor[a[i]].size(); ++k) {
				if ((j >> k) & 1) {
					mul *= factor[a[i]][k];
				}
			}
			++pcover[mul];
		}
	}
	vector<int> cover(mx + 1);
	for (int i = 2; i <= mx; ++i) {
		for (int j = 1; j < 1 << factor[i].size(); ++j) {
			int mul = 1, cnt = 0;
			for (int k = 0; k < factor[i].size(); ++k) {
				if ((j >> k) & 1) {
					++cnt;
					mul *= factor[i][k];
				}
			}
			if (cnt % 2 == 1) cover[i] += pcover[mul];
			else cover[i] -= pcover[mul];
		}
	}
	int ans = inf;
	for (int i = 0; i < n; ++i) {
		vector<int> dp(1 << factor[a[i]].size(), inf);
		dp[0] = 1;
		vector<int> tbl(1 << factor[a[i]].size(), 1);
		for (int j = 0; j < 1 << factor[a[i]].size(); ++j) {
			for (int k = 0; k < factor[a[i]].size(); ++k) {
				if ((j >> k) & 1) {
					tbl[j] *= factor[a[i]][k];
				}
			}
		}
		for (int j = 1; j < 1 << factor[a[i]].size(); ++j) {
			for (int k = j; k > 0; k = (k - 1) & j) {
				if (cover[tbl[k]] != n) dp[j] = min(dp[j], dp[j - k] + 1);
			}
		}
		ans = min(ans, dp.back());
	}
	if (ans != inf) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}