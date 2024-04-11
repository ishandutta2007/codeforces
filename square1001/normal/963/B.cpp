#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
vector<int> topological_sorting(vector<vector<int> > G) {
	int N = G.size();
	vector<int> deg(N);
	for (int i = 0; i < N; ++i) {
		for (int j : G[i]) {
			++deg[j];
		}
	}
	queue<int> que;
	for (int i = 0; i < N; ++i) {
		if (deg[i] == 0) {
			que.push(i);
		}
	}
	vector<int> ord;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		ord.push_back(u);
		for (int i : G[u]) {
			--deg[i];
			if (deg[i] == 0) {
				que.push(i);
			}
		}
	}
	return ord;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N; ++i) {
		int p;
		cin >> p; --p;
		if (p != -1) {
			G[p].push_back(i);
			G[i].push_back(p);
		}
	}
	if (N <= 2) {
		cout << (N == 1 ? "YES" : "NO") << endl;
		if (N == 1) cout << 1 << endl;
		return 0;
	}
	int root = -1;
	for (int i = 0; i < N; ++i) {
		if (G[i].size() >= 2) {
			root = i;
			break;
		}
	}
	vector<vector<int> > ordgraph(N);
	function<bool(int, int)> calc = [&](int pos, int pre) {
		int deg = 0;
		for (int i : G[pos]) {
			if (i == pre) continue;
			bool res = calc(i, pos);
			if (res) deg ^= 1;
		}
		if (pre != -1) {
			if (deg == 0) ordgraph[pre].push_back(pos);
			else ordgraph[pos].push_back(pre);
		}
		return (deg == 0);
	};
	bool res = calc(root, -1);
	if (!res) {
		cout << "NO" << endl;
	}
	else {
		vector<int> ord = topological_sorting(ordgraph);
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i) {
			cout << ord[i] + 1 << '\n';
		}
	}
	return 0;
}