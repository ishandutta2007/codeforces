#include <bits/stdc++.h>
using namespace std;

vector<int> mp[200005];
int lvl[200005];
int dis[200005];
bool used[200005];

void bfs() {
	queue<int> q;
	int p;
	q.push(1);
	lvl[1] = 0;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (auto y : mp[p]) {
			if (lvl[y] == -1) {
				lvl[y] = lvl[p] + 1;
				q.push(y);
			}
		}
	}
}

void dfs(int x) {
	used[x] = 1;
	dis[x] = lvl[x];
	for (auto y : mp[x]) {
		if (!used[y] && lvl[y] > lvl[x])
			dfs(y);
		if (lvl[y] > lvl[x]) {
			if (dis[y] < dis[x])
				dis[x] = dis[y];
		} else {
			if (lvl[y] < dis[x])
				dis[x] = lvl[y];
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t, n, m, i, j;
	cin >> t;
	memset(lvl, -1, sizeof(lvl));
	memset(dis, 63, sizeof(dis));
	while (t--) {
		cin >> n >> m;
		while (m--) {
			cin >> i >> j;
			mp[i].push_back(j);
		}
		bfs();
		dfs(1);
		for (i = 1; i <= n; ++i)
			cout << dis[i] << ' ';
		cout << endl;
		for (i = 1; i <= n; ++i) {
			mp[i].clear();
		}
		memset(lvl, -1, sizeof(lvl));
		memset(dis, 63, sizeof(dis));
		memset(used, 0, sizeof(used));
	}
	return 0;
}