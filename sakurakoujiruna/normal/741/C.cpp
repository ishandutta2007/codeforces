#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
vector <int> e[N];

int u[N], v[N];
int c[N];

bool vis[N];

void dfs(int x, int t) {
	vis[x] = true; c[x] = t;
	for(int i : e[x]) if(!vis[i])
		dfs(i, t ^ 1);
}

int main() {
	ios :: sync_with_stdio(false);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> u[i] >> v[i];
		e[u[i]].push_back(v[i]);
		e[v[i]].push_back(u[i]);
	}
	for(int i = 1; i <= n; i ++) {
		e[i * 2 - 1].push_back(2 * i);
		e[i * 2].push_back(2 * i - 1);
	}
	for(int i = 1; i <= 2 * n; i ++) if(!vis[i])
		dfs(i, 0);

	for(int i = 1; i <= n; i ++)
		cout << c[u[i]] + 1 << ' ' << c[v[i]] + 1 << '\n';
	return 0;
}