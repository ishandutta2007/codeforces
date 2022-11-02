#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m, city[N];
map <int, int> mp;
vector <int> v[N];
bool vis[N];

void dfs(int x) {
	vis[x] = 1;
	printf("%d ", city[x]);
	for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (!vis[y]) dfs(y);
	}
}

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (!mp[a]) mp[a] = ++n, city[n] = a;
		if (!mp[b]) mp[b] = ++n, city[n] = b;
		a = mp[a], b = mp[b];
		v[a].push_back(b), v[b].push_back(a);
	}
	for (int i = 1; i <= n; i ++) {
		if (v[i].size() == 1) {
			dfs(i); return 0;
		}
	}
	return 0;
}