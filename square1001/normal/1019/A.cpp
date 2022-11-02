#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int n, m, p, c;
	cin >> n >> m;
	vector<vector<int> > g(m);
	for (int i = 0; i < n; ++i) {
		cin >> p >> c;
		g[--p].push_back(c);
	}
	for (int i = 0; i < m; ++i) {
		sort(g[i].begin(), g[i].end(), greater<int>());
	}
	long long ret = -1;
	for (int i = max((int)g[0].size(), 1); i <= n; ++i) {
		long long sum = 0; int cnt = 0;
		for (int j = 1; j < m; ++j) {
			for (int k = i - 1; k < g[j].size(); ++k) {
				sum += g[j][k];
				++cnt;
			}
		}
		vector<int> rem;
		for (int j = 1; j < m; ++j) {
			for (int k = 0; k < g[j].size() && k < i - 1; ++k) {
				rem.push_back(g[j][k]);
			}
		}
		sort(rem.begin(), rem.end());
		for (int j = 0; j < i - (int)g[0].size() - cnt; ++j) {
			sum += rem[j];
		}
		if (ret == -1 || ret > sum) ret = sum;
	}
	cout << ret << '\n';
	return 0;
}