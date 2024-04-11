#include <bits/stdc++.h>
using namespace std;
#define N 10101

vector <int> v[N], ans;
bool vis[N], col[N], flag[N];
int root[N], dp[N], ed[N];
pair <int, int> p, q, edge[N];
map < pair <int, int>, int > mp;
int a, b, c, f[N], n, m, cnt;

void dfs(int x) {
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (vis[y]) continue;
		root[y] = x, dp[y] = dp[x] + 1;
		col[y] = 1 - col[x];
		p.first = x, p.second = y;
		ed[y] = mp[p];
		flag[mp[p]] = 1;
		dfs(y);
	}
}

int man(int a, int b) {
	if (dp[a] < dp[b]) while (dp[a] < dp[b]) b = root[b];
	else while (dp[a] > dp[b]) a = root[a];
	while (1) {
		if (a == b) return a;
		a = root[a], b = root[b];
	}
}

int main() {
//	freopen("e.in", "r", stdin);
//	freopen("e_new.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		cin >> a >> b;
		edge[i].first = a, edge[i].second = b;
		v[a].push_back(b), v[b].push_back(a);
		p.first = a, p.second = b;
		q.first = b, q.second = a;
		mp[p] = mp[q] = i;
	}
	for (int i = 1; i <= n; i ++) root[i] = i;
	for (int i = 1; i <= n; i ++) if (!vis[i]) col[i] = 0, dfs(i);
	for (int i = 1; i <= m; i ++) if (!flag[i]) {
		a = edge[i].first, b = edge[i].second;
		c = man(a, b);
		if (col[a] == col[b]) {
			cnt ++;
			f[i] = 1;
			while (a != c) f[ed[a]] ++, a = root[a];
			while (b != c) f[ed[b]] ++, b = root[b];
		}
		else {
			while (a != c) f[ed[a]] --, a = root[a];
			while (b != c) f[ed[b]] --, b = root[b];
		}
	}
	if (!cnt) memset(f, 0, sizeof f);
	for (int i = 1; i <= m; i ++) if (f[i] == cnt) ans.push_back(i);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i ++) cout << ans[i] << ' '; cout << endl;
	return 0;
}