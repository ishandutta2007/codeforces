#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
const int N = 200005;
int n, m, et[N], eu[N], ev[N], col[N], ans[N];
vector<int> e[N];
void dfs(int u, int fa) {
	for (auto& x: e[u])
		if (x != fa) {
			if (col[x] == -1) {
				col[x] = col[u] ^ 1;
				dfs(x, u);
			} else if (col[x] != (col[u] ^ 1)) {
				puts("NO"), exit(0);
			}
		}
}
vector<int> ee[N];
int deg[N];
void add_edge(int u, int v) {
	ee[u].push_back(v);
	++deg[v];
}
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf("%d%d%d", &et[i], &eu[i], &ev[i]);
		e[eu[i]].push_back(ev[i]);
		e[ev[i]].push_back(eu[i]);
	}
	memset(col, -1, sizeof(col));
	rep(i, 1, n) if (col[i] == -1) {
		col[i] = 0;
		dfs(i, 0);
	}
	rep(i, 1, m) {
		if (et[i] == 1) {
			if (col[eu[i]]) swap(eu[i], ev[i]);
			add_edge(eu[i], ev[i]);
		} else {
			if (!col[eu[i]]) swap(eu[i], ev[i]);
			add_edge(eu[i], ev[i]);
		}
	}
	queue<int> q;
	rep(i, 1, n) if (!deg[i]) q.push(i);
	int cur = 0;
	while (!q.empty()) {
		int u = q.front();
		ans[u] = cur++;
		q.pop();
		for (auto& x: ee[u])
			if (!--deg[x]) {
				q.push(x);
			}
	}
	if (cur < n) {
		puts("NO"), exit(0);
	}
	puts("YES");
	rep(i, 1, n) printf("%c %d\n", col[i] == 0 ? 'L' : 'R', ans[i]);
}