#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	vector<int> dist(n);
	for (int i = 0; i < n; ++i) scanf("%d", &dist[i]);
	vector<vector<int>> byDistance(n);
	for (int i = 0; i < n; ++i) {
		byDistance[dist[i]].push_back(i);
	}
	if (byDistance[0].size() != 1) {
		printf("-1\n");
		return 0;
	}
	vector<int> cParent(n, -1);
	for (int cDist = 1; cDist < n; ++cDist) {
		if (byDistance[cDist].empty()) continue;
		if (byDistance[cDist - 1].empty() && !byDistance[cDist].empty()) {
			printf("-1\n");
			return 0;
		}
		for (int k = 0; k < byDistance[cDist].size(); ++k) {
			cParent[byDistance[cDist][k]] = byDistance[cDist-1][k % byDistance[cDist - 1].size()];
		}
	}
	vector<int> degree(n);
	for (int i = 0; i < n; ++i) {
		if (cParent[i] >= 0) {
			++degree[i];
			++degree[cParent[i]];
		}
	}
	if (*max_element(begin(degree), end(degree)) > k) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", n - 1);
	for (int i = 0; i < n; ++i) {
		if (cParent[i] >= 0) {
			printf("%d %d\n", i + 1, cParent[i] + 1);
		}
	}
	return 0;
}