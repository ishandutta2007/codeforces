#include <bits/stdc++.h>
using namespace std;

#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int qread() {
	register char c = getchar();
	register int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - 48;
		c = getchar();
	}
	return x * f;
}

int n, a[505][505], pnt, hd[250005];
bool vis[505][505];
struct Edge {
	int to, nxt, len;
	Edge() {
		nxt = -1;
	}
};
Edge e[1000005];
long long dis[250005];
const int Next[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

inline void AddEdge(int u, int v, int w) {
	e[++pnt].to = v;
	e[pnt].len = w;
	e[pnt].nxt = hd[u];
	hd[u] = pnt;
}

inline void Read() {
	n = qread();
	for (int i = 1;i <= 2 * n;i++) {
		for (int j = 1;j <= 2 * n;j++) a[i][j] = qread();
	}
}

inline void Solve() {
	long long ans = 0;
	for (int i = n + 1;i <= 2 * n;i++) {
		for (int j = n + 1;j <= 2 * n;j++) {
			ans += a[i][j];
			a[i][j] = 0;
		}
	}
	pnt = 0;
	for (int i = 1;i <= 4 * n * n;i++) {
		hd[i] = -1;
		dis[i] = 0x3f3f3f3f3f3f3f3f;
	}
	for (int i = 1;i <= 2 * n;i++) {
		for (int j = 1;j <= 2 * n;j++) {
			if (i <= n && j <= n && !(i == 1 && j == 1) && !(i == n && j == 1) && !(i == 1 && j == n) && !(i == n && j == n)) {
				continue;
			}
			for (int k = 0;k < 4;k++) {
				int tx = i + Next[k][0], ty = j + Next[k][1];
				tx = (tx + 2 * n - 1) % (2 * n) + 1;
				ty = (ty + 2 * n - 1) % (2 * n) + 1;
				if (tx <= n && ty <= n && !(tx == 1 && ty == 1) && !(tx == n && ty == 1) && !(tx == 1 && ty == n) && !(tx == n && ty == n)) {
					continue;
				}
				AddEdge((i - 1) * 2 * n + j, (tx - 1) * 2 * n + ty, a[tx][ty]);
			}
		}
	}
	dis[1] = dis[n] = dis[(n - 1) * 2 * n + 1] = dis[(n - 1) * 2 * n + n] = 0;
	priority_queue <pair <long long, int>, vector <pair <long long, int> >, greater <pair <long long, int> > > que;
	que.push(make_pair(dis[1], 1));
	que.push(make_pair(dis[n], n));
	que.push(make_pair(dis[(n - 1) * 2 * n + 1], (n - 1) * 2 * n + 1));
	que.push(make_pair(dis[(n - 1) * 2 * n + n], (n - 1) * 2 * n + n));
	while (!que.empty()) {
		int u = que.top().second;
		if (dis[u] < que.top().first) {
			que.pop();
			continue;
		}
		que.pop();
		for (int i = hd[u];~i;i = e[i].nxt) {
			if (dis[e[i].to] > dis[u] + e[i].len) {
				dis[e[i].to] = dis[u] + e[i].len;
				que.push(make_pair(dis[e[i].to], e[i].to));
			}
		}
	}
	cout << ans + dis[4 * n * n] << endl;
}

int main() {
	int t = qread();
	while (t--) {
		Read();
		Solve();
	}
	#ifdef CFA_44
	while (1);
	#endif
	return 0;
}