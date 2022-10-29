#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

vector<int> s[N];
vector<int> adj[N];
int n, m, num;
map<int, int> color;
int visit[N], tag;

void dfs(int u, int from) {
	++tag;
	for (auto v : s[u]) {
		if (color.count(v)) {
			visit[color[v]] = tag;
		}
	}
	int ptr = 1;
	for (auto v : s[u]) {
		if (!color.count(v)) {
			while (visit[ptr] == tag) ptr++;
			color[v] = ptr;
			ptr++;
		}
	}
	for (auto v : adj[u]) {
		if (v == from) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d %d", &n, &m);
	num = 1;
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		num = max(num, k);
		for (int j = 1; j <= k; j++) {
			int x; scanf("%d", &x);
			s[i].push_back(x);
		}
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", num);
	for (int i = 1; i <= m; i++) {
		if (!color.count(i)) color[i] = 1;
		printf("%d ", color[i]);
	}
	puts("");
	return 0;
}