#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
vector<int> adjlist[500000];
vector<int> children[500000];
ii ans[500000];
int dfs(int v, int p, int s) {
	for (int i: adjlist[v]) {
		if (i != p) children[v].push_back(i);
	}
	ans[v].second = s + children[v].size();
	s = ans[v].second + 1;
	for (int i = 0; i < children[v].size(); ++i) {
		ans[children[v][i]].first = ans[v].second - i - 1;
		s = dfs(children[v][i], v, s) + 1;
	}
	return s - 1;
}
int main() {
	int n, x, y;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d %d", &x, &y);
		adjlist[x - 1].push_back(y - 1);
		adjlist[y - 1].push_back(x - 1);
	}
	ans[0].first = 1;
	dfs(0, -1, 2);
	for (int i = 0; i < n; ++i) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}