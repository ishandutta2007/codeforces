#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

struct VectorWeird {
	vector<int> arr;
	int maxIndex;
	VectorWeird() {}
	void addElem(int v) {
		arr.push_back(v);
	}
	int& operator[] (int i) {
		return arr[arr.size() - 1 - i];
	}
	int size() {return arr.size();}
};

vector<vector<int>> tree;
vector<int> par, maxDepth;
vector<int> trav;
vector<bool> isLeaf;

void findPar(int i, int p) {
	par[i] = p;
	for (int v : tree[i]) {
		if (v != p) {findPar(v, i); isLeaf[i] = false;}
	}
	trav.push_back(i);
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n); par = maxDepth = vector<int>(n);
	isLeaf = vector<bool>(n, true);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		tree[--a].push_back(--b);
		tree[b].push_back(a);
	}
	findPar(0, -1);
	vector<VectorWeird*> depList(n, nullptr);
	for (int i : trav) {
		// printf("at %d\n", i);
		if (isLeaf[i]) {
			depList[i] = new VectorWeird();
			depList[i]->addElem(1);
			maxDepth[i] = 0;
		} else {
			int bestSize = 0, bsc = -1;
			for (int v : tree[i]) {
				if (v != par[i]) {
					if (depList[v]->size() > bestSize) {
						bestSize = depList[v]->size();
						bsc = v;
					}
				}
			}
			// printf("merging to %d\n", bsc);
			depList[i] = depList[bsc];
			maxDepth[i] = maxDepth[bsc];
			for (int v : tree[i]) {
				if (v != par[i] and v != bsc) {
					for (int dp = 0; dp < depList[v]->size(); ++dp) {
						(*depList[i])[dp] += (*depList[v])[dp];
						if ((*depList[i])[dp] > (*depList[i])[maxDepth[i]] or 
							((*depList[i])[dp] == (*depList[i])[maxDepth[i]] and dp < maxDepth[i])) {
							maxDepth[i] = dp;
						}
					}
				}
			}
			// for (int dp = 0; dp < depList[i]->size(); ++dp) {
			// 	printf("at depth %d: %d\n", dp + 1, (*depList[i])[dp]);
			// }
			// printf("maxDepth = %d\n", maxDepth[i]);
			depList[i]->addElem(1);
			if ((*depList[i])[++maxDepth[i]] == 1) {
				maxDepth[i] = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", maxDepth[i]);
	}
	return 0;
}