#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
int n;
vector<vector<int>> adj(maxn);
int dep[maxn];
double ans = 0.0;

void dfs(int u, int p) {
	dep[u] = p == -1 ? 1 : dep[p]+1;
	ans += (1.0)/(dep[u]+0.0);
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0.0;
	dfs(1, -1);
	cout << fixed << setprecision(15);
	cout << ans << endl;
	cin >> n;
}