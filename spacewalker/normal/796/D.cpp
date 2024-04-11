#include <queue>
#include <cstdio>
#include <vector>

using namespace std;

struct EdgeInfo {
	int from;
	int to;
	int idx;
	EdgeInfo (int f, int t, int i) : from(f), to(t), idx(i) {}
};

struct SearchData {
	int to;
	int dist;
	SearchData (int t, int d) : to(t) , dist(d) {}
};

int main() {
	int cities, stations, radius;
	scanf("%d %d %d", &cities, &stations, &radius);

	vector<int> stationIdx(stations, 0);
	for (int st = 0; st < stations; ++st) {
		scanf("%d", &stationIdx[st]);
		--stationIdx[st];
	}

	vector<EdgeInfo> edgeList;
	vector<bool> wasUsed(cities - 1, false);
	vector<vector<EdgeInfo>> tree(cities, vector<EdgeInfo>());

	for (int i = 0; i < cities - 1; ++i) {
		int from, to;
		scanf("%d %d", &from, &to);
		--from; --to;
		edgeList.emplace_back(from, to, i);
		tree[from].emplace_back(from, to, i);
		tree[to].emplace_back(to, from, i);
	}

	vector<bool> visited(cities, false);
	queue<SearchData> toVisit;
	for (int station : stationIdx) {
		visited[station] = true;
		toVisit.emplace(station, 0);
	}

	while (!toVisit.empty()) {
		SearchData cur = toVisit.front(); toVisit.pop();
		if (cur.dist > radius) {
			continue; // don't calc this vertex
		}
		for (EdgeInfo neighbor : tree[cur.to]) {
			if (!visited[neighbor.to]) {
				visited[neighbor.to] = true;
				wasUsed[neighbor.idx] = true;
				toVisit.emplace(neighbor.to, cur.dist + 1);
			}
		}
	}

	vector<int> unusedEdges;
	for (int i = 0; i < cities - 1; ++i) {
		if (!wasUsed[i]) {
			unusedEdges.push_back(i + 1);
		}
	}

	printf("%lu\n", unusedEdges.size());
	for (int i = 0; i < unusedEdges.size(); ++i) {
		printf("%s%d", (i > 0 ? " " : ""), unusedEdges[i]);
	}

	return 0;
}