#include <bits/stdc++.h>

using namespace std;

vector<int> g[200005];
int lvl[200005];
int dis[200005];
int ans;

void add(int x, int y) {
	g[x].push_back(y);
	g[y].push_back(x);
}

void bfs() {
	queue<int> q;
	int p;
	lvl[1] = 1;
	q.push(1);
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i : g[p]) {
			if (!lvl[i]) {
				lvl[i] = lvl[p] + 1;
				q.push(i);
			}
		}
	}
}

void dfs(int p) {
	if (g[p].size() == 1) {
		dis[p] = 0;
		return;
	}
	for (int i : g[p]) {
		if (lvl[i] > lvl[p]) {
			dfs(i);
			dis[p] = min(dis[p], dis[i] + 1);
			ans = max(ans, dis[i] + 2);
		}
	}
}

void solve() {
	memset(lvl, 0, sizeof lvl);
	memset(dis, 63, sizeof dis);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	bfs();
	ans = 0;
	int maxm = 0, cnt = 0;
	for (int i : g[1]) {
		dfs(i);
		if (dis[i] > maxm) {
			maxm = dis[i];
			cnt = 1;
		} else if (dis[i] == maxm) {
			++cnt;
		}
	}
	if (cnt > 1) {
		ans = max(ans, maxm + 2);
	} else {
		ans = max(ans, maxm + 1);
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) {
		g[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}