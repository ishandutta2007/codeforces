#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int> > G(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int start = 0;
	for (int i = 1; i < N; ++i) {
		if (G[i].size() > G[start].size()) {
			start = i;
		}
	}
	vector<int> dist(N, -1);
	dist[start] = 0;
	queue<int> que;
	que.push(start);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i : G[u]) {
			if (dist[i] == -1) {
				dist[i] = dist[u] + 1;
				cout << i + 1 << ' ' << u + 1 << '\n';
				que.push(i);
			}
		}
	}
	return 0;
}