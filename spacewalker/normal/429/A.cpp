#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

#define INF 1000000000
#define ROOT 0

int interChange(int x) {
	return (((x & 1) == 1) << 1) | (((x & 2) == 2) << 0);
}

bool isCurrentlySet(int x) {
	return (x & 1);
}

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> tree(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int ui, vi; scanf("%d %d", &ui, &vi);
		tree[--ui].push_back(--vi);
		tree[vi].push_back(ui);
	}
	queue<pair<int, int>> q;
	vector<int> init(n, 0);
	vector<int> goal(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &init[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &goal[i]);
	}
	q.emplace(0, ROOT);
	vector<int> toFlip;
	vector<bool> visited(n, 0);
	visited[ROOT] = true;
	while (!q.empty()) {
		auto cs_cur = q.front(); q.pop();
		if (isCurrentlySet(cs_cur.first) == (init[cs_cur.second] != goal[cs_cur.second])) {
			// no flip needs to occur?

		} else {
			toFlip.push_back(cs_cur.second);
			cs_cur.first ^= 1;
		}
		for (int child : tree[cs_cur.second]) {
			if (!visited[child]) {
				q.emplace(interChange(cs_cur.first), child);
				visited[child] = true;
			}
		}
	}
	printf("%lu\n", toFlip.size());
	for (int i : toFlip) {
		printf("%d\n", i + 1);
	}
	return 0;
}