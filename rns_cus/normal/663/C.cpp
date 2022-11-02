#include <bits/stdc++.h>
using namespace std;
#define M 200010

struct Edge {
	int x, y, c;
	Edge(int x = 0, int y = 0, int c = 0) : x(x), y(y), c(c) {}
} ed[M];

int ans, n, m, vis[M][3];

vector <int> con[M], v[3], V;

typedef pair <int, int> PII;

void check(int c) {
	memset(vis, 0, sizeof(vis));
	vector <int> tV;
	for (int i = 1; i <= n; i++) {
		if (vis[i][0] || vis[i][1]) continue;
    queue <PII> q; q.push(PII(i, 0));

		v[0].clear(); v[1].clear();
    vis[i][0] = 1;
    v[0].push_back(i);

    while (!q.empty()) {
    	PII p = q.front(); q.pop();
    	int x = p.first, y = p.second;
    	for (int k = 0; k < con[x].size(); k++) {
    		int j = con[x][k];
    		int u = ed[j].x + ed[j].y - x;
				if (c != ed[j].c && vis[u][y]) return;
				if (c == ed[j].c && vis[u][y ^ 1]) return;

				if (c != ed[j].c && vis[u][y ^ 1]) continue;
				if (c == ed[j].c && vis[u][y]) continue;

				if (c == ed[j].c) {
					vis[u][y] = 1;
					q.push(PII(u, y));
					v[y].push_back(u);
				}
				else {
					vis[u][y ^ 1] = 1;
					q.push(PII(u, y ^ 1));
					v[y ^ 1].push_back(u);
				}
    	}
    }
    if (v[0].size() > v[1].size()) swap(v[0], v[1]);
    for (int j = 0; j < v[0].size(); j++) tV.push_back(v[0][j]);
	}
	if (!c || !V.size()) V = tV;
	else if (V.size() > tV.size()) V = tV;
}

int flag[4];

int main() {
	//freopen("C.in", "r", stdin);
	scanf("%d %d", &n, &m);
	char type[10];
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d %s", &x, &y, type);
		if (x > y) swap(x, y);
		ed[i] = Edge(x, y, (type[0] == 'R'));
		flag[type[0] == 'R'] = 1;
		con[x].push_back(i), con[y].push_back(i);
	}

	if (!flag[0] || !flag[1]) return puts("0"), 0;

	ans = M;
	for (int c = 0; c <= 1; c++) check(c);

	if (!V.size()) puts("-1");
	else {
		printf("%d\n", V.size());
		for (int i = 0; i < V.size(); i++) printf("%d ", V[i]);
	}
}