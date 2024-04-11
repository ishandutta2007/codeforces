#include <bits/stdc++.h>
using namespace std;

#define N 300010

int h[N], depth[N], mxx[N], diam, root[N], n, m, que, type, x, y, vis[N], sz[N];
vector <int> V[N];

void dfs(int v, int par) {
    for (int i = 0; i < V[v].size(); i ++) {
		int vv = V[v][i];
		if (vv == par) continue;
		dfs(vv, v);
		if (depth[v] <= depth[vv] + 1) {
			mxx[v] = depth[v];
			depth[v] = depth[vv] + 1;
		}
		else if(mxx[v] < depth[vv] + 1) mxx[v] = depth[vv] + 1 ;
    }
    if (diam < mxx[v] + depth[v]) diam = mxx[v] + depth[v];
    return;
}

int find_rt(int r) {
    if (r == root[r]) return r;
    return root[r] = find_rt(root[r]);
}

int main() {
	//freopen("ksh.in", "r", stdin);

	scanf("%d%d%d", &n, &m, &que);
	for (int i = 1; i <= n; i ++) root[i] = i;
	while (m --) {
		scanf("%d%d", &x, &y);
		V[x].push_back(y);
		V[y].push_back(x);
		root[find_rt(x)] = find_rt(y);
	}
	//for (int i = 1; i <= n; i ++) printf("%d ", find_rt(i));
    for (int i = 1; i <= n; i ++) {
		if (!vis[find_rt(i)]) {
			diam = 0;
			dfs(i, 0);
			sz[find_rt(i)] = diam;
			vis[find_rt(i)] = 1;
		}
    }
    while (que --) {
		scanf("%d", &type);
		if (type == 1) {
			scanf("%d", &x);
			printf("%d\n", sz[find_rt(x)]);
		}
		if (type == 2) {
			scanf("%d%d", &x, &y);
			int rx = find_rt(x), ry = find_rt(y);
			if (rx == ry) continue;
			root[rx] = ry;
			sz[ry] = max((sz[rx] + 1) / 2 + (sz[ry] + 1) / 2 + 1, max(sz[rx], sz[ry]));
		}
    }
}