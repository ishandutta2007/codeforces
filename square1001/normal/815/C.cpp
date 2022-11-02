#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, B;
	cin >> N >> B;
	vector<int> p(N, -1), c(N), d(N);
	for (int i = 0; i < N; ++i) {
		cin >> c[i] >> d[i];
		if (i >= 1) cin >> p[i], --p[i];
	}
	vector<vector<long long> > g(N);
	vector<vector<long long> > dp(N, vector<long long>({ 0 }));
	for (int i = N - 1; i >= 0; --i) {
		dp[i].insert(dp[i].begin(), 0);
		g[i].push_back(c[i]);
		sort(g[i].begin(), g[i].end());
		for (int j = 1; j < dp[i].size(); ++j) dp[i][j] += c[i] - d[i];
		long long sum = 0;
		for (int j = 0; j < g[i].size(); ++j) {
			sum += g[i][j];
			dp[i][j + 1] = min(dp[i][j + 1], sum);
		}
		if (p[i] != -1) {
			vector<long long> nxt(dp[p[i]].size() + dp[i].size() - 1, 1LL << 62);
			for (int j = 0; j < dp[p[i]].size(); ++j) {
				for (int k = 0; k < dp[i].size(); ++k) {
					nxt[j + k] = min(nxt[j + k], dp[p[i]][j] + dp[i][k]);
				}
			}
			dp[p[i]] = nxt;
			g[p[i]].insert(g[p[i]].end(), g[i].begin(), g[i].end());
		}
	}
	int mx = 0;
	for (int i = 0; i <= N; ++i) {
		if (dp[0][i] <= B) mx = i;
	}
	cout << mx << endl;
	return 0;
}