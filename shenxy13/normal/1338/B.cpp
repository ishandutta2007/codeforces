#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> adjlist[100000];
int leaf_colour = 0, one = 1, sib = 0;
void dfs(int v, int p, bool red) {
	if (adjlist[v].size() == 1) {
		if (red) {
			if (leaf_colour > 0) one = 0;
			else leaf_colour = -1;
		} else {
			if (leaf_colour < 0) one = 0;
			else leaf_colour = 1;
		}
	}
	int num_leaf = 0;
	for (int i: adjlist[v]) {
		if (adjlist[i].size() == 1) ++num_leaf;
		if (i == p) continue;
		dfs(i, v, !red);
	}
	sib += max(0, num_leaf - 1);
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		adjlist[a - 1].push_back(b - 1);
		adjlist[b - 1].push_back(a - 1);
	}
	dfs(0, -1, true);
	if (one) printf("1 %d", n - 1 - sib);
	else printf("3 %d", n - 1 - sib);
	return 0;
}