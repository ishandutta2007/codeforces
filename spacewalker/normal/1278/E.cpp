#include <bits/stdc++.h>

using namespace std;

struct LLthingo {
	int val;
	LLthingo *p, *n;
	LLthingo(int val, LLthingo* p, LLthingo* n) : val(val), p(p), n(n) {}
	void addBefore(int x) {
		LLthingo *p2 = p;
		p = new LLthingo(x, p2, this);
		if (p2 != nullptr) p2->n = p;
	}
	void addAfter(int x) {
		LLthingo *n2 = n;
		n = new LLthingo(x, this, n2);
		if (n2 != nullptr) n2->p = n;
	}
};

vector<vector<int>> tree;
vector<int> prnt;
vector<int> pOrder;

void getParent(int v, int p) {
	prnt[v] = p;
	pOrder.push_back(v);
	for (int u : tree[v]) if (u != p) getParent(u, v);
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	prnt = vector<int>(n, -1);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		tree[--a].push_back(--b);
		tree[b].push_back(a);
	}
	getParent(0, -1);
	vector<LLthingo*> endList(n, nullptr);
	LLthingo *lstart = new LLthingo(0, nullptr, nullptr);
	endList[0] = new LLthingo(0, lstart, nullptr);
	lstart->n = endList[0];
	for (int i : pOrder) {
		if (prnt[i] == -1) continue;
		endList[prnt[i]]->addBefore(i);
		endList[prnt[i]]->addAfter(i);
		endList[i] = endList[prnt[i]]->n;
	}
	vector<int> flatList;
	for (LLthingo* lp = lstart; lp != nullptr; lp = lp->n) flatList.push_back(lp->val);
	vector<pair<int, int>> ans(n, make_pair(-1, -1));
	for (int i = 0; i < flatList.size(); ++i) {
		if (ans[flatList[i]].first == -1) ans[flatList[i]].first = i;
		else ans[flatList[i]].second = i;
	}
	for (auto s_e : ans) {
		printf("%d %d\n", s_e.first + 1, s_e.second + 1);
	}
	return 0;
}