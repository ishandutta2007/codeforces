#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
int n, m;
vector<int> g[N];
int f[N];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			f[i] = 0, g[i].clear();
		}
		for (int i = 1; i <= m; i ++) {
			int u, v;
			scanf("%d%d", &u, &v);
			g[u].push_back(v);
		}
		vector<int> ans;
		for (int i = 1; i <= n; i ++) {
			if (f[i] == 2) ans.push_back(i);
			else {
				for (auto j: g[i]) {
					f[j] = max(f[j], f[i] + 1);
				}
			}
		}
		printf("%d\n", ans.size());
		for (auto x: ans) printf("%d ", x); printf("\n");
	}
}