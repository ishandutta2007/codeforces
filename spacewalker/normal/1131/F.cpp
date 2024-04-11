#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// uniform_int_distribution<int>(0, 1000000000) gen();

// struct treap {
// 	treap *left, *right, *par;
// 	int prio, val;

// 	void setPP() {
// 		if (left != nullptr) left->par = par;
// 		if (right != nullptr) right->par = par;
// 	}

// 	treap(int val) : left(nullptr), right(nullptr), par(nullptr), prio(-1), val(val) {}
// 	treap() :  left(nullptr), right(nullptr), par(nullptr), prio(gen(rng)), val(-1) {}
// 	treap *merge(treap *ls, treap *rs) {
// 		if (ls == nullptr) return rs;
// 		else if (rs == nullptr) return ls;
// 		treap *res = nullptr;
// 		if (prio >= ls->prio) {
// 			left->par = this;
// 			right->par = this;
// 			res = this;
// 		} else if (ls->prio < rs->prio) {
// 			res = rs;
// 			rs = merge();
// 		}
// 	}
// };

vector<int> ans;

int main() {
	int n; scanf("%d", &n);
	vector<vector<pair<int, int>>> tree(n);
	int root = 0;
	set<pair<int, int>> toVis;
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b); --a; --b;
		if (i == 0) root = a;
		tree[a].emplace_back(b, i);
		tree[b].emplace_back(a, i);
	}
	vector<bool> placed(n, false);
	toVis.emplace(-1, root);
	while (!toVis.empty()) {
		int cur = toVis.begin()->second;
		placed[cur] = true;
		toVis.erase(toVis.begin());
		ans.push_back(cur);
		// printf("PL %d\n", cur);
		for (auto next : tree[cur]) {
			// printf("CHECK %d\n", next.first);
			if (!placed[next.first]) {
				// printf("VIS %d\n", next.first);
				toVis.emplace(next.second, next.first);
			}
		}
	}
	for (int x : ans) printf("%d ", x + 1);
	printf("\n");
	return 0;

}