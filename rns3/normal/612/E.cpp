#include <bits/stdc++.h>
using namespace std;
#define M 1000010
vector <int> v[M];
int p[M], vis[M], deg[M], q[M], n, m, id[M], pos[M];
bool cmp(int i, int j) {return deg[i] < deg[j];}
int main() {
//	freopen("E.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i), pos[p[i]] = i;
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		vis[i] = 1; v[m].push_back(pos[i]); int j = p[i];
		while (j != i) {v[m].push_back(pos[j]); vis[j] = 1; j = p[j];}
		m++;
	}
	for (int i = 0; i < m; i++) deg[i] = v[i].size(), id[i] = i;
	sort(id, id + m, cmp);
	id[m] = m;
	for (int r = 0; r < m; r++) {
		int i = id[r];
		if (deg[i] & 1) {
			for (int j = 0; j < deg[i]; j++) q[v[i][j]] = v[i][(j+(deg[i]+1)/2)%deg[i]];
		}
		else {
			if (deg[i] != deg[id[r+1]]) {puts("-1"); return 0;}
			int j = id[r+1];
			for (int k = 0; k < deg[i]; k++) q[v[i][k]] = v[j][k], q[v[j][k]] = v[i][(k+1)%deg[i]];
			r++;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", q[i]);
}