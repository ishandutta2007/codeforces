#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
long long knapsack(int n, vector<long long> w, vector<long long> c, int limit) {
	vector<long long> dp(limit + 1);
	for (int i = 0; i < n; ++i) {
		for (int j = limit; j >= w[i]; --j) {
			dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
		}
	}
	return dp[limit];
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> W(N);
	vector<long long> C(N);
	vector<pair<long long, int> > d;
	vector<vector<long long> > g(3);
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> W[i] >> C[i];
		for (int j = 0; j < W[i]; ++j) {
			d.push_back(make_pair(C[i] * 6 / W[i], i));
		}
		sum += C[i];
		g[W[i] - 1].push_back(C[i]);
	}
	sort(d.begin(), d.end(), greater<pair<long long, int> >());
	for (int i = 0; i < 3; ++i) {
		sort(g[i].begin(), g[i].end(), greater<long long>());
	}
	vector<int> pivot(3);
	vector<bool> vis(N);
	for (int i = 0; i < d.size() && i < M; ++i) {
		if (!vis[d[i].second]) {
			vis[d[i].second] = true;
			++pivot[W[d[i].second] - 1];
		}
	}
	long long curw = 0, cursum = 0;
	vector<long long> subw, subc;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			if (j < pivot[i] - 3) {
				curw += i + 1;
				cursum += g[i][j];
			}
			else if (pivot[i] - 3 <= j && j < pivot[i] + 3) {
				subw.push_back(i + 1);
				subc.push_back(g[i][j]);
			}
		}
	}
	long long subans = knapsack(subw.size(), subw, subc, M - curw);
	long long ans = cursum + subans;
	cout << ans << endl;
	return 0;
}