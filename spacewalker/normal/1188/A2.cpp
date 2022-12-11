#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> actions, elist;
vector<vector<pair<int, int>>> tree;

pair<int, int> getRepLeaves(int i, int p) {
	vector<int> choices;
	for (auto chpp : tree[i]) {
		if (chpp.first != p) {
			choices.push_back(getRepLeaves(chpp.first, i).first);
		}
	}
	if (choices.size() == 0) {
		return make_pair(i, i);
	} else {
		// choices.size() == 1 implies i has degree 2
		return make_pair(choices[0], choices[1]);
	}
}

int main() {	
	int n; scanf("%d", &n);
	vector<int> deg(n);
	tree = vector<vector<pair<int, int>>>(n); // dest vertex, expected value
	for (int i = 0; i < n - 1; ++i) {
		int x, y, val; scanf("%d %d %d", &x, &y, &val); --x; --y;
		tree[x].emplace_back(y, val);
		tree[y].emplace_back(x, val);
		elist.emplace_back(make_pair(x, y), val);
	}
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (tree[i].size() == 2) {
			printf("NO\n");
			return 0;
		} else if (tree[i].size() > 2) {
			root = i;
		}
	}
	printf("YES\n");
	for (auto edge : elist) {
		int u = edge.first.first, v = edge.first.second, val = edge.second;
		pair<int, int> uLeaf = getRepLeaves(u, v), vLeaf = getRepLeaves(v, u);
		actions.emplace_back(make_pair(uLeaf.first, vLeaf.first), val/2);
		actions.emplace_back(make_pair(uLeaf.second, vLeaf.second), val/2);
		if (uLeaf.first != uLeaf.second) {
			actions.emplace_back(make_pair(uLeaf.first, uLeaf.second), -val/2);
		}
		if (vLeaf.first != vLeaf.second) {
			actions.emplace_back(make_pair(vLeaf.first, vLeaf.second), -val/2);
		}
	}
	printf("%lu\n", actions.size());
	for (auto act : actions) {
		printf("%d %d %d\n", act.first.first + 1, act.first.second + 1, act.second);
	}
	return 0;
}