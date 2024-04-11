#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 500000 + 10;
int n, m;
int col[N], dis[N], mask[N];
map<int, int> g[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[v][u] |= (w + 1);
	}

	memset(dis, -1, sizeof(dis));
	queue<int> q; q.push(n);
	dis[n] = 0; 
	while (q.size()) {
		int u = q.front(); q.pop();
		//printf("u = %d , dis = %d\n", u, dis[u]);
		for (auto p: g[u]) {
			int v = p.first;
			int w = p.second;
			if (dis[v] != -1) continue;
			//printf("v = %d w = %d\n", v, w);
			int pre = mask[v];
			mask[v] |= w;
			if (w == 1) col[v] = 1;
			else col[v] = 0;
			if (mask[v] == 3) {
				dis[v] = dis[u] + 1;

				if (pre == 0 || pre == 2) {
					col[v] = 0;
				} else {
					col[v] = 1;
				}
				//printf("v = %d, col = %d\n", v, col[v]);
				q.push(v);
			} 
		}
	}
	printf("%d\n", dis[1]);
	for (int i = 1; i <= n; i ++)
		printf("%d", col[i]);
	printf("\n");
}