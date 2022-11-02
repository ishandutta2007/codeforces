#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> c(N);
	vector<long long> dpx(N), dpy(N);
	function<void(int, int)> dfs_bottomup = [&](int pos, int pre) {
		c[pos] = 1;
		for (int i : G[pos]) {
			if (i == pre) continue;
			dfs_bottomup(i, pos);
			dpx[pos] += dpx[i];
			c[pos] += c[i];
		}
		dpx[pos] += c[pos];
	};
	dfs_bottomup(0, -1);
	function<void(int, int)> dfs_topdown = [&](int pos, int pre) {
		for (int i : G[pos]) {
			if (i == pre) continue;
			dpy[i] = dpy[pos] + (dpx[pos] - dpx[i] - c[pos]) + (N - c[i]);
			dfs_topdown(i, pos);
		}
	};
	dfs_topdown(0, -1);
	long long ans = dpx[0];
	for (int i = 1; i < N; ++i) {
		ans = max(ans, dpx[i] + dpy[i] - c[i] + N);
	}
	cout << ans << '\n';
	return 0;
}