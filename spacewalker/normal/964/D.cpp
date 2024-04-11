#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define ROOT 0
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> tree(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		int pi; scanf("%d", &pi);
		if (pi > 0) {
			tree[i].push_back(pi - 1);
			tree[pi - 1].push_back(i);
		}
	}
	vector<int> trav;
	trav.reserve(n);
	vector<vector<int>> children(n, vector<int>());
	vector<bool> visited(n, false);
	visited[ROOT] = true;
	queue<int> travQ;
	travQ.push(ROOT);
	while (!travQ.empty()) {
		int cur = travQ.front(); travQ.pop();
		trav.push_back(cur);
		for (int child : tree[cur]) {
			if (!visited[child]) {
				visited[child] = true;
				travQ.push(child);
				children[cur].push_back(child);
			}
		}
	}
	reverse(trav.begin(), trav.end());
	vector<bool> canDivPE(n, false);
	vector<vector<int>> divisionGraph(n, vector<int>());
	for (int i : trav) {
		vector<int> eChildren;
		vector<int> oChildren;
		for (int child : children[i]) {
			if (canDivPE[child]) {
				eChildren.push_back(child);
			} else {
				oChildren.push_back(child);
			}
		}
		canDivPE[i] = (eChildren.size() % 2 == 0);
		for (int ec : eChildren) {
			divisionGraph[ec].push_back(i);
			//printf("dg edge %d %d\n", ec, i);
		}
		for (int oc : oChildren) {
			divisionGraph[i].push_back(oc);
			//printf("dg edge %d %d\n", i, oc);
		}
	}
	printf("%s\n", (canDivPE[ROOT] ? "YES" : "NO"));
	if (canDivPE[ROOT]) {
		vector<int> toposort; toposort.reserve(n);
		vector<int> inDeg(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int next : divisionGraph[i]) {
				++inDeg[next];
			}
		}
		queue<int> zeroInDeg;
		for (int i = 0; i < n; ++i) {
			if (inDeg[i] == 0) {
				zeroInDeg.push(i);
			}
		}
		while (!zeroInDeg.empty()) {
			int cur = zeroInDeg.front(); zeroInDeg.pop();
			toposort.push_back(cur);
			for (int next : divisionGraph[cur]) {
				--inDeg[next];
				if (inDeg[next] == 0) {
					zeroInDeg.push(next);
				}
			}
		}
		reverse(toposort.begin(), toposort.end());
		for (int i : toposort) {
			printf("%d\n", i + 1);
		}
	}
	return 0;
}