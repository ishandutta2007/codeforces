#include <cstdio>
#include <vector>
#include <queue>
#define ROOT 0

using namespace std;

int main() {
	int N; scanf("%d", &N);
	vector<vector<int>> tree(N, vector<int>());
	for (int i = 0; i < N - 1; ++i) {
		int ui, vi; scanf("%d %d", &ui, &vi);
		tree[--ui].push_back(--vi);
		tree[vi].push_back(ui);
	}
	vector<double> probHorseAt(N, -1);
	vector<int> dist(N, -1);
	vector<bool> isLeaf(N, false);
	queue<int> q;

	probHorseAt[ROOT] = 1.0;
	dist[ROOT] = 0;
	q.push(ROOT);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int childCount = tree[cur].size() - (cur == ROOT ? 0 : 1);
		for (int neigh : tree[cur]) {
			if (dist[neigh] == -1) {
				probHorseAt[neigh] = probHorseAt[cur] / childCount;
				//printf("horse will be at %d with probability %.5f\n", neigh, probHorseAt[neigh]);
				dist[neigh] = dist[cur] + 1;
				q.push(neigh);
			}
		}
		if (childCount == 0) {
			isLeaf[cur] = true;
		}
	}

	double ans = 0;
	for (int i = 0; i < N; ++i) {
		if (isLeaf[i]) {
			//printf("%d is leaf, with dist %d\n", i, dist[i]);
			ans += (probHorseAt[i] * dist[i]);
		}
	}

	printf("%.15f\n", ans);

	return 0;
}