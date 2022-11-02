#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int n, x, a, b; vector<vector<int> > g;
vector<int> solve(int pos) {
	vector<int> ret(n, -1); ret[pos] = 0;
	queue<int> que; que.push(pos);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : g[u]) {
			if (ret[i] == -1) {
				ret[i] = ret[u] + 1;
				que.push(i);
			}
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> x; x--; g.resize(n);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b; a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> r1 = solve(0);
	vector<int> r2 = solve(x);
	int ret = 0;
	for (int i = 0; i < n; i++) {
		if (r1[i] > r2[i]) ret = max(ret, r1[i]);
	}
	printf("%d\n", ret * 2);
	return 0;
}