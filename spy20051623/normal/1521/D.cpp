#include <bits/stdc++.h>

using namespace std;

vector<int> m[200005];

vector<pair<int, int>> rem;
vector<pair<int, int>> cha;

int lvl[200005];
int fa[200005];

void bfs(int s) {
	memset(lvl, 0, sizeof lvl);
	queue<int> q;
	int p;
	q.push(s);
	lvl[s] = 1;
	fa[s] = 0;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		for (int i : m[p]) {
			if (!lvl[i]) {
				lvl[i] = lvl[p] + 1;
				fa[i] = p;
				q.push(i);
			}
		}
	}
}

void remove(int x, int y) {
	if (lvl[x] > lvl[y])
		swap(x, y);
	rem.emplace_back(x, y);
	fa[y] = 0;
}

void dfs(int p) {
	vector<int> son;
	for (int i : m[p]) {
		if (fa[i] == p)
			son.push_back(i);
	}
	for (int i : son) {
		dfs(i);
	}
	son.clear();
	for (int i : m[p]) {
		if (fa[i] == p)
			son.push_back(i);
	}
	if (son.size() > 1) {
		if (fa[p])
			remove(p, fa[p]);
		for (int i = 2; i < son.size(); ++i) {
			remove(son[i], p);
		}
	}
}

int find(int p) {
	vector<int> son;
	for (int i : m[p]) {
		if (fa[i] == p)
			son.push_back(i);
	}
	if (fa[p])
		return !son.empty() ? find(son[0]) : p;
	int a = p;
	int b = p;
	if (!son.empty())
		a = find(son[0]);
	if (son.size() > 1)
		b = find(son[1]);
	cha.emplace_back(a, b);
	return 0;
}

void solve() {
	int n;
	scanf("%d", &n);
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		scanf("%d%d", &a, &b);
		m[a].push_back(b);
		m[b].push_back(a);
	}
	rem.clear();
	cha.clear();
	bfs(1);
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		if (!fa[1])
			find(i);
	}
	printf("%d\n", rem.size());
	for (int i = 0; i < cha.size() - 1; ++i) {
		printf("%d %d %d %d\n", rem[i].first, rem[i].second, cha[i].second, cha[i + 1].first);
	}
	for (int i = 1; i <= n; ++i) {
		m[i].clear();
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}