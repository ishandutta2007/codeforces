#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

int n, m, k, vis[N], par[N], dep[N];
vector<int> g[N];

int mxdet = N, x, y; 

void dfs(int u, int p) {
	vis[u] = 1;
	dep[u] = dep[p] + 1;
	par[u] = p;
	for (auto v: g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			int cur = dep[u] - dep[v];
			// printf("u = %d v = %d\n", u, v);
			
			if (cur >= 1 && cur < mxdet) {
				mxdet = cur, x = u, y = v;
			}
			continue;
		}
		dfs(v, u);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1, 0);
	// printf("mxdet = %d, x = %d, y = %d\n", mxdet, x, y);
	if (mxdet == N) {
		vector<int> v[2];
		for (int i = 1; i <= n; i++) v[dep[i] % 2].push_back(i);
		printf("1\n");
		int len = (k + 1) / 2;
		if (v[0].size() >= len) {
			for (int i = 0; i < len; i ++) printf("%d ", v[0][i]);
		} else {
			for (int i = 0; i < len; i ++) printf("%d ", v[1][i]);
		}
		return 0;
	}
	vector<int> v;
	int now = x;
	while (1) {
		v.push_back(now);
		if (now == y) break;
		now = par[now];
	}
	if (mxdet < k) {
		printf("2\n");
		printf("%d\n", v.size());
		for (auto x: v) printf("%d ", x); printf("\n");
		return 0;
	} 
	printf("1\n");
	vector<int> new_v;
	for (int i = 0; i < v.size(); i += 2) new_v.push_back(v[i]);
	assert(new_v.size() >= (k+1)/2);
	for (int i = 0; i < (k + 1) / 2; i ++) printf("%d ", new_v[i]); printf("\n");
}