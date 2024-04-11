#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<bool>visited(300001);
vector<int> g[300001];
long long cnnnt = 0;
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < (int)g[v].size(); i++) {
		int u = g[v][i];
		if (!visited[u]) {
			cnnnt++;
			dfs(u);
			
		}
	}
}
#define int long long
signed main() {
	int n;
	cin >> n;
	
	vector<int> dist(n + 1, -1);
	vector<int>par(n, -1);
	int x, y;
	cin >> y >> x;
	for (int i = 0; i < n - 1; i++) {
		int k1, k2;
		cin >> k1 >> k2;
		k1--;
		k2--;
		g[k1].push_back(k2);
		g[k2].push_back(k1);
	}
	x -= 1;
	y -= 1;
	dist[x] = 0;
	int c = 0;
	queue<int> Q;
	Q.push(x);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int i = 0; i < g[v].size(); i++) {
			if (dist[g[v][i]] == -1) {
				dist[g[v][i]] = dist[v] + 1;
				par[g[v][i]] = v;
				Q.push(g[v][i]);
				if (g[v][i] == y) {
					c = 1;
				}
			}
		}
	}
	
	int z1 = par[y];
	int y2 = y;
	while (1) {
		if (par[y2] == x) {
			break;
		}
		y2 = par[y2];
	}
	visited[y] = true;
	visited[z1] = true;
	dfs(y);
	//cout << cnnnt;
	long long ans1 = cnnnt + 1;
	cnnnt = 0;
	int z2 = y2;
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	visited[z2] = true;
	visited[x] = true;
	dfs(x);
	long long ans2 = cnnnt + 1;
	//cout << ans2 * ans1;
	long long ans = n * (n - 1);
	ans -= ans1 * ans2;
	cout << ans;
	return 0;
}