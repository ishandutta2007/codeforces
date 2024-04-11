#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;
int t, n, a, b, da, db;
vector<int> g[N];



int dis[N];

pair<int,int> bfs(int src) {
	queue<int> q;
	for (int i = 1; i <= n; i ++) dis[i] = -1;
	q.push(src); dis[src] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v: g[u]) {
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1; q.push(v);
			}
		}
	}

	int mx = -1, pos = -1;
	for (int i = 1; i <= n; i ++) {
		if (dis[i] > mx) {
			mx = dis[i]; pos = i;
		}
	}
	return make_pair(mx, pos);
}

int main() {
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d%d%d%d", &n, &a, &b, &da ,&db);
		for (int i = 1; i <= n; i ++) {
			g[i].clear();
		}
		for (int i = 1; i < n; i ++) {
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		pair<int,int> p = bfs(a);
		if (da >= dis[b]) {
			printf("Alice\n"); continue;
		}
		pair<int,int> p2 = bfs(p.second);
		int D = p2.first;
		if (da >= (D + 1) / 2) {
			printf("Alice\n"); continue;
		}
		if (2 * da >= db) {
			printf("Alice\n"); continue;
		}
		printf("Bob\n");
	}
}