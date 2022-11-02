#include <cstdio>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;
struct edge { int to, id; };
int n, m, a, b, r, d[300009], s[300009]; bool vis[300009]; vector<edge> g[300009];
int dfs(int pos) {
	vis[pos] = true;
	int ret = 0;
	for (edge i : g[pos]) {
		if (!vis[i.to]) {
			int res = dfs(i.to);
			if (res == 1) s[r++] = i.id;
			ret ^= res;
		}
	}
	if (d[pos] == 1) ret ^= 1;
	return ret;
}
int main() {
	scanf("%d %d", &n, &m);
	int root = -1, cnt = 0; bool any = false;
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
		if (d[i] == -1) any = true, root = i;
		else if (!any && d[i] == 1) root = i, cnt ^= 1;
	}
	if (root == -1) printf("0\n");
	else if (!any && cnt == 1) printf("-1\n"); 
	else {
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b); a--, b--;
			g[a].push_back(edge{ b, i + 1 });
			g[b].push_back(edge{ a, i + 1 });
		}
		dfs(root);
		printf("%d\n", r);
		for (int i = 0; i < r; i++) printf("%d\n", s[i]);
	}
	return 0;
}