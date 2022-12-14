#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int N = 1e4 + 10;
const int inf = 0x7f7f7f7f;
int dis[N], x[N], y[N], n, m, K;
bool fg, vis[N];

int spfa() {
	queue <int> q;
	memset(dis, 0x7f, sizeof dis);
	q.push(1), vis[1] = 1, dis[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 1; i <= K; i ++) {
			if (i == u) continue;
			int w = inf;
			int dx = abs(x[i] - x[u]), dy = abs(y[i] - y[u]);
			if (dx + dy == 1) w = 0;
			else if (dx <= 2 || dy <= 2) w = 1;
			if (dis[i] > dis[u] + w) {
				dis[i] = dis[u] + w;
				if (!vis[i]) vis[i] = 1, q.push(i);
			} 
		}
		vis[u] = 0;
	}
	return dis[K] == inf ? -1 : dis[K];
}

int main() {
	n = rd(), m = rd(), K = rd();
	for (int i = 1; i <= K; i ++) {
		x[i] = rd(), y[i] = rd();
		fg |= (x[i] == n && y[i] == m);
	}
	if (!fg) x[++K] = n + 1, y[K] = m + 1;
	printf("%d\n", spfa());
	return 0;
}