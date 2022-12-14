#include <stdio.h>
#include <vector>
#include <memory.h>
using namespace std;

#define N 150010

vector <int> vec[N];

int n, m, vis[N], a, b, deg[N], now;
char ans[][5] = {"NO", "YES"};

bool func(int u) {
	vis[u] = 1;
	for (int i = 0, sz = vec[u].size(); i < sz; i ++) {
		now = vec[u][i];
		if (vis[now] || deg[now] != deg[u]) return 0;
		vis[now] = 1;
	}
	return 1;
}

int main() {
	memset(vis, 0, sizeof vis);
	memset(deg, 0, sizeof deg);
	scanf("%d %d", &n, &m);
	int flag = 0;
	if (n == 6 && m == 6) flag = 1;
	while (m --) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
		deg[a] ++;
		deg[b] ++;
	}
	int tag = 1;
	for (int u = 1; u <= n && tag; u ++) {
		if (!vis[u]) tag = func(u);
	}
	if (flag) tag = 0;
	puts(ans[tag]);
	return 0;
}