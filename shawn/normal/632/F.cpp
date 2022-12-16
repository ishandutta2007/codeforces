#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - 48, c = getchar();
	return x;
}

#define pb push_back
const int N = 3100;
const int inf = 0x7f7f7f7f;
int a[N][N], n, mx[N], ed, dis[N];
bool mst[N], vis[N];
vector <int> E[N];

void bfs(int s) {
	queue <int> q;
	memset(vis, 0, sizeof vis);
	memset(mx, 0, sizeof mx);
	q.push(s), mx[s] = 0, vis[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < E[u].size(); i ++) {
			int v = E[u][i];
			if (!vis[v]) mx[v] = max(a[u][v], mx[u]), vis[v] = 1, q.push(v);
		}
	}
}

int main() {
	n = rd();
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) a[i][j] = rd();
	for (int i = 1; i <= n; i ++) {
		if (a[i][i]) return puts("NOT MAGIC"), 0;
		for (int j = 1; j <= n; j ++) if (a[i][j] != a[j][i]) return puts("NOT MAGIC"), 0;
	}
	dis[0] = inf;
	for (int i = 2; i <= n; i ++) dis[i] = a[1][i]; mst[1] = 1;
	for (int i = 1; i < n; i ++) {
		int id = 0, _id;
		for (int j = 1; j <= n; j ++) if (!mst[j] && dis[j] < dis[id]) id = j;
		for (int j = 1; j <= n; j ++) if (mst[j] && a[j][id] == dis[id]) E[j].pb(id), E[id].pb(j), j = n;
		mst[id] = 1;
		for (int j = 1; j <= n; j ++) if (!mst[j] && a[id][j] < dis[j]) dis[j] = a[id][j];
	}
	for (int i = 1; i <= n; i ++) {
		bfs(i);
		for (int j = 1; j <= n; j ++) if (mx[j] != a[i][j]) return puts("NOT MAGIC"), 0;
	}
	return puts("MAGIC"), 0;
}