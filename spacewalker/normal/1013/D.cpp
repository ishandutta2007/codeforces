#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	int n, m, pur; scanf("%d %d %d", &n, &m, &pur);
	vector<vector<int>> graph(n + m);
	for (int i = 0; i < pur; ++i) {
		int r, c; scanf("%d %d", &r, &c); --r; --c;
		graph[r].push_back(n + c);
		graph[n + c].push_back(r);
		// printf("edge %d %d\n", r, n + c);
	}
	vector<bool> vis(n + m, false);
	queue<int> q;
	int ccs = 0;
	for (int start = 0; start < n + m; ++start) {
		if (!vis[start]) {
			++ccs;
			vis[start] = true;
			q.push(start);
			while (not q.empty()) {
				int cur = q.front(); q.pop();
				for (int next : graph[cur]) {
					if (!vis[next]) {
						vis[next] = true;
						q.push(next);
					}
				}
			}
		}
	}
	printf("%d\n", ccs - 1);
	return 0;
}