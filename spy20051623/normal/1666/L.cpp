#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;
int vis[N], pre[N], tot;
int n, m, s;
vector<int> g[N];

bool dfs(int p, int f) {
	if (vis[p] && vis[p] != tot) {
		stack<int> a, b;
		a.push(p);
		b.push(p);
		int x = f, y = pre[p];
		while (x != s) a.push(x), x = pre[x];
		while (y != s) b.push(y), y = pre[y];
		a.push(s);
		b.push(s);
		cout << "Possible\n";
		cout << a.size() << '\n';
		while (!a.empty()) cout << a.top() << ' ', a.pop();
		cout << '\n';
		cout << b.size() << '\n';
		while (!b.empty()) cout << b.top() << ' ', b.pop();
		cout << '\n';
		return true;
	}
	if (vis[p] == tot) return false;
	vis[p] = tot;
	pre[p] = f;
	for (int i: g[p]) if (dfs(i, p)) return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (y == s) continue;
		g[x].push_back(y);
	}
	for (int i: g[s]) {
		++tot;
		if (dfs(i, s)) return 0;
	}
	cout << "Impossible\n";
	return 0;
}