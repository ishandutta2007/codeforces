#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<pair<int, int> > solve(vector<pair<int, int> > interval) {
	int n = interval.size();
	vector<int> comp;
	for (int i = 0; i < n; ++i) {
		++interval[i].second;
		comp.push_back(interval[i].first);
		comp.push_back(interval[i].second);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	vector<vector<int> > g(comp.size());
	for (int i = 0; i < n; ++i) {
		int pl = lower_bound(comp.begin(), comp.end(), interval[i].first) - comp.begin();
		int pr = lower_bound(comp.begin(), comp.end(), interval[i].second) - comp.begin();
		g[pr].push_back(pl);
	}
	vector<int> dp(comp.size());
	for (int i = 1; i < comp.size(); ++i) {
		dp[i] = dp[i - 1];
		for (int j : g[i]) {
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	vector<pair<int, int> > ans;
	int ptr = comp.size() - 1;
	while (ptr != 0) {
		if (dp[ptr] == dp[ptr - 1]) {
			--ptr;
		}
		else {
			for (int i : g[ptr]) {
				if (dp[i] + 1 == dp[ptr]) {
					ans.push_back(make_pair(comp[i], comp[ptr] - 1));
					ptr = i;
					break;
				}
			}
		}
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	map<int, vector<pair<int, int> > > d;
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = i; j < N; ++j) {
			sum += A[j];
			d[sum].push_back(make_pair(i + 1, j + 1));
		}
	}
	vector<pair<int, int> > ans;
	for (pair<int, vector<pair<int, int> > > i : d) {
		vector<pair<int, int> > res = solve(i.second);
		if (ans.size() < res.size()) {
			ans = res;
		}
	}
	cout << ans.size() << endl;
	for (pair<int, int> i : ans) {
		cout << i.first << ' ' << i.second << endl;
	}
	return 0;
}