#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int x, y; scanf("%d %d", &x, &y);
		--x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	vector<int> topics(n);
	for (int i = 0; i < n; ++i) scanf("%d", &topics[i]);
	vector<int> pOrder(n);
	for (int i = 0; i < n; ++i) pOrder[i] = i;
	sort(begin(pOrder), end(pOrder), [&topics] (int i, int j) {
			return topics[i] < topics[j];
	});
	// check if pOrder works
	vector<int> prodTopics(n, -1);
	for (int v : pOrder) {
//		printf("att %d\n", v);
		set<int> adj;
		for (int nxt : graph[v]) if (prodTopics[nxt] != -1) adj.insert(prodTopics[nxt]);
//		for (int x : adj) printf("see %d\n", x);
		int mex = 1;
		while (adj.count(mex) > 0) ++mex;
		prodTopics[v] = mex;
//		printf("mex %d\n", mex);
	}
	if (topics != prodTopics) printf("-1");
	else for (int x : pOrder) printf("%d ", x + 1);
	printf("\n");
	return 0;
}