#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;

vector<pair<int, int>> ansPath;

void generateAns(int v, int p, int k, int ct) {
	int entryTime = ct;
	ansPath.emplace_back(v, ct);
	for (int kid : tree[v]) {
		if (kid == p) continue;
		if (ct == k) {
			ct = k - (int)tree[v].size();
			ansPath.emplace_back(v, ct);
		}
		generateAns(kid, v, k, ct + 1);
		ansPath.emplace_back(v, ct + 1);
		ct++;
	}
	if (ct != entryTime - 1 && entryTime > 0) {
		ansPath.emplace_back(v, entryTime - 1);
	}
}

int main() {
	int n; scanf("%d", &n);
	tree = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		--a; --b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) ans = max(ans, (int)tree[i].size());
	generateAns(0, -1, ans, 0);
	printf("%lu\n", ansPath.size());
	for (auto v_t : ansPath) printf("%d %d\n", v_t.first + 1, v_t.second);
	return 0;
}