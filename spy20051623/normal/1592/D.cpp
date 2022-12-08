#include <bits/stdc++.h>

using namespace std;

vector<int> g[1005];
int fa[1005], son[1005];
bool vis[1005];
int n;
unordered_set<int> s;

int ask() {
	unordered_set<int> ss;
	for (int i: s) ss.insert(i), ss.insert(fa[i]);
	printf("? %d", ss.size());
	for (int i: ss) printf(" %d", i);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%d", &ans);
	return ans;
}

int init(int p, int f) {
	fa[p] = f;
	son[p] = 1;
	for (int i: g[p]) {
		if (i != f) son[p] += init(i, p);
	}
	return son[p];
}

void dfs(int p, int x) {
	if (s.size() >= x) return;
	if (p != 1 && !vis[p]) {
		s.insert(p);
	}
	for (int i: g[p]) {
		if (i != fa[p]) dfs(i, x);
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	init(1, 1);
	int num;
	for (int i = 2; i <= n; ++i) {
		s.insert(i);
	}
	num = ask();
	int cnt = n - 1;
	vis[1] = true;
	while (cnt > 1) {
		s.clear();
		dfs(1, cnt / 2);
		int ans = ask();
		if (ans == num) {
			for (int i = 1; i <= n; ++i) {
				if (s.find(i) == s.end()) vis[i] = true;
			}
			cnt = s.size();
		} else {
			for (int i: s) vis[i] = true;
			cnt -= s.size();
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) printf("! %d %d\n", i, fa[i]);
	}
	fflush(stdout);
	return 0;
}