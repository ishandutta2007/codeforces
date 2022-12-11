#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1000000000
using namespace std;

vector<vector<int>> tree;
int n;


vector<int> linearize() {
	// look for the edge with zero incoming vertex
	vector<int> inDegree(n, 0);
	for (int c = 0; c < n; ++c) {
		for (int child : tree[c]) {
			++inDegree[child];
		}
	}
	int root = 0;
	while (inDegree[root] > 0) {
		++root;
	}

	vector<int> linRev;
	queue<int> q; q.push(root);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		linRev.push_back(cur);
		for (int neighbor : tree[cur]) {
			q.push(neighbor);
		}
	}
	reverse(linRev.begin(), linRev.end());
	/*
	for (int i : linRev) {
		printf("%d ", i);
	}
	printf("\n");
	*/
	return linRev;
}

bool isParentOfLeaves(int node) {
	if (tree[node].size() == 0) {return false;}
	for (int child : tree[node]) {
		if (tree[child].size() > 0) {
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	int temp1, temp2;
	tree = vector<vector<int>>(n, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d %d", &temp1, &temp2);
		tree[temp1-1].push_back(temp2-1);
	}
	// travelOrder[n-1] = root
	vector<int> travelOrder = linearize();

	vector<int> childLeaves(n, 0);
	for (int i : travelOrder) {
		if (tree[i].size() == 0) {
			childLeaves[i] = 1; // temporarily set to 1 as a base case
		} else {
			int res = 0;
			for (int child : tree[i]) {
				res += childLeaves[child];
			}
			childLeaves[i] = res;
		}
	}/*
	for (int i = 0; i < n; ++i) {
		if (tree[i].size() == 0) {
			childLeaves[i] = 0;
		}
	}*/
	vector<bool> isMax(n, true);
	queue<pair<int, bool>> q; q.emplace(travelOrder[n-1], true);
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		isMax[cur.first] = cur.second;
		for (int child : tree[cur.first]) {
			q.emplace(child, !cur.second);
		}
	}

	vector<int> shamBest(n, 1);
	// DP for Shambambukli's best result
	for (int i : travelOrder) {
		if (tree[i].size() == 0) {
			continue; // we already have our base case
		} else if (isMax[i]) {
			int minDeduction = INF;
			for (int child : tree[i]) {
				minDeduction = min(minDeduction, childLeaves[child] - shamBest[child]);
			}
			shamBest[i] = childLeaves[i] - minDeduction;
		} else {
			int resultSum = 0;
			for (int child : tree[i]) {
				resultSum += shamBest[child];
			}
			//printf("sB[%d] = %d - %d + 1\n", i + 1, resultSum, tree[i].size());
			shamBest[i] = resultSum - tree[i].size() + 1;
		}
	}
	printf("%d ", shamBest[travelOrder[n-1]]);


	vector<int> mazukBest(n, 1);
	// DP for Mazukta's best result
	for (int i : travelOrder) {
		if (tree[i].size() == 0) {
			continue;
		} else if (isMax[i]) {
			int resultSum = 0;
			for (int child : tree[i]) {
				resultSum += mazukBest[child];
			}
			mazukBest[i] = resultSum;
		} else {
			int minChildBest = INF;
			for (int child : tree[i]) {
				minChildBest = min(minChildBest, mazukBest[child]);
			}
			mazukBest[i] = minChildBest;
		}
	}

	printf("%d", mazukBest[travelOrder[n-1]]);

	return 0;
}