#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, m, r, a, b, c[1009], z[1009]; bool vis[1009]; vector<int> G[1009];
int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 0; i < r; i++) scanf("%d", &c[i]), c[i]--;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b); a--, b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 0; i < r; i++) {
		queue<int> que; que.push(c[i]); z[i] = 1; vis[c[i]] = true;
		while (!que.empty()) {
			int u = que.front(); que.pop();
			for (int j : G[u]) {
				if (!vis[j]) {
					vis[j] = true; z[i]++;
					que.push(j);
				}
			}
		}
	}
	sort(z, z + r);
	int sum = 0, ret = 0;
	for (int i = 0; i < r - 1; i++) sum += z[i], ret += z[i] * (z[i] - 1) / 2;
	ret += (n - sum) * (n - sum - 1) / 2;
	cout << ret - m << endl;
	return 0;
}