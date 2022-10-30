#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solve(int pos, int pre, vector<vector<int> > &g) {
	int sum2 = 0;
	vector<int> dif;
	for (int i = 0; i < g[pos].size(); ++i) {
		if (pre == g[pos][i]) continue;
		vector<int> res = solve(g[pos][i], pos, g);
		sum2 += res[1];
		dif.push_back(res[1] - res[0]);
	}
	sort(dif.begin(), dif.end());
	int res1 = max(sum2, (dif.size() >= 1 ? sum2 - dif[0] + 1 : 0));
	int res2 = max(res1, (dif.size() >= 2 ? sum2 - dif[0] - dif[1] + 2 : 0));
	return vector<int>({ res1, res2 });
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, a, b; long long x, y;
	cin >> n >> x >> y;
	vector<vector<int> > g(n);
	for (int i = 0; i < n - 1; ++i) {
		cin >> a >> b; --a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (x > y) {
		long long ret = (n - 1) * y;
		for (int i = 0; i < n; ++i) {
			if (g[i].size() == n - 1) {
				ret += x - y;
				break;
			}
		}
		cout << ret << '\n';
	}
	else {
		int ret = solve(0, -1, g)[1];
		cout << ret * x + (n - ret - 1) * y << '\n';
	}
	return 0;
}