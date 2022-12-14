#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int c[2000];
vector<int> children[2000];
vector<int> dfs(int v) {
	vector<int> ans;
	for (int i: children[v]) {
		vector<int> a = dfs(i);
		for (int j: a) ans.push_back(j);
	}
	if (c[v] > ans.size()) return vector<int>();
	ans.insert(ans.begin() + c[v], v);
	return ans;
}
int main() {
	int n, p, root = -1;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &p, &c[i]);
		if (p == 0) root = i;
		else children[p - 1].push_back(i);
	}
	vector<int> ans = dfs(root);
	if (ans.size() != n) printf("NO");
	else {
		int x[n];
		for (int i = 0; i < ans.size(); ++i) x[ans[i]] = i + 1;
		printf("YES\n");
		for (int i = 0; i < n; ++i) printf("%d ", x[i]);
	}
	return 0;
}