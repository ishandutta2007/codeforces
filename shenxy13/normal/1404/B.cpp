#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, a, b, da, db;
vector<int> adjlist[100000];
int dist[100000], md = 0;
void dfs(int v, int p) {
	for (int i: adjlist[v]) {
		if (i == p) continue;
		dist[i] = dist[v] + 1;
		dfs(i, v);
	}
}
int diameter(int v, int p) {
	vector<int> child;
	for (int i: adjlist[v]) {
		if (i == p) continue;
		child.push_back(diameter(i, v) + 1);
	}
	while (child.size() < 2) child.push_back(0);
	sort(child.begin(), child.end());
	md = max(md, child[child.size() - 1] + child[child.size() - 2]);
	return child.back();
}
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		scanf("%d %d %d %d %d", &n, &a, &b, &da, &db);
		--a, --b;
		for (int i = 0; i < n; ++i) adjlist[i].clear();
		int u, v;
		for (int i = 1; i < n; ++i) {
			scanf("%d %d", &u, &v);
			adjlist[u - 1].push_back(v - 1);
			adjlist[v - 1].push_back(u - 1);
		}
		if (2 * da < db) {
			fill_n(dist, n, 0);
			dfs(a, -1);
			if (dist[b] > da) {
				md = 0;
				diameter(a, -1);
				if (md <= 2 * da) printf("Alice\n");
				else printf("Bob\n");
			} else printf("Alice\n");
		} else printf("Alice\n");
	}
}