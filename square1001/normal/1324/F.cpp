#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> col(N);
	for (int i = 0; i < N; ++i) {
		cin >> col[i];
		col[i] = (col[i] == 0 ? -1 : 1);
	}
	vector<int> pcol = col;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	function<void(int, int)> dfs1 = [&](int pos, int pre) {
		for (int i : G[pos]) {
			if (i == pre) continue;
			dfs1(i, pos);
			col[pos] += max(col[i], 0);
		}
	};
	dfs1(0, -1);
	vector<int> down(N);
	function<void(int, int)> dfs2 = [&](int pos, int pre) {
		int sum = col[pos] + down[pos];
		for (int i : G[pos]) {
			if (i == pre) continue;
			down[i] = max(sum - max(col[i], 0), 0);
			dfs2(i, pos);
		}
	};
	dfs2(0, -1);
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << col[i] + down[i];
	}
	return 0;
}