#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int e[600][600], d[600], n, m;

int bfs(int fg) {
	queue <int> q;
	memset(d, -1, sizeof d);
	q.push(1), d[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 1; i <= n; i ++) {
			if (e[u][i] == fg && d[i] == -1) d[i] = d[u] + 1, q.push(i);
		}
	}
	return d[n];
}

int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= m; i ++) {
		int u = rd(), v = rd();
		e[u][v] = e[v][u] = 1;
	}
	printf("%d\n", bfs(1 ^ e[1][n]));
	return 0;
}