#include <queue>
#include <cstdio>
#pragma warning(disable : 4996)
using namespace std;
int n, m, x, dist[2009]; bool f[1009];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d", &x), f[x] = true;
	fill(dist, dist + 2001, -1);
	queue<int> que; que.push(0);
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i <= 1000; i++) {
			if (f[i] && dist[u + i - n + 1000] == -1) {
				dist[u + i - n + 1000] = (u == 0 ? 0 : dist[u + 1000]) + 1;
				que.push(u + i - n);
			}
		}
	}
	printf("%d\n", dist[1000]);
	return 0;
}