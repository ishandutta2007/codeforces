#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<pii> g[1005];
int dis[1005][1005], vis[1005];
pii l[1005];

void dijkstra(int s) {
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.emplace(0, s);
	memset(vis, 0, sizeof vis);
	dis[s][s] = 0;
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		if (vis[p.second]) continue;
		vis[p.second] = 1;
		for (auto &i: g[p.second]) {
			if (dis[s][i.first] > dis[s][p.second] + i.second) {
				dis[s][i.first] = dis[s][p.second] + i.second;
				q.emplace(dis[s][i.first], i.first);
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		g[x].emplace_back(y, z);
		g[y].emplace_back(x, z);
	}
	memset(dis, 63, sizeof dis);
	for (int i = 1; i <= n; ++i) {
		dijkstra(i);
	}
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &l[i].first, &l[i].second);
	}
	int ans = 2e9;
	for (int i = 1; i <= n; ++i) {
		for (auto &j: g[i]) {
			int sum = 0;
			for (int c = 0; c < k; ++c) {
				sum += min(dis[l[c].first][l[c].second], min(dis[l[c].first][i] + dis[j.first][l[c].second],
															 dis[l[c].first][j.first] + dis[i][l[c].second]));
			}
			ans = min(ans, sum);
		}
	}
	printf("%d\n", ans);
	return 0;
}