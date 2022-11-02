#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, a[N], m, b[N], prv[N];
vector <int> V[N];
bool vis[N];

int bpm(int u) {
	for (int i = 0; i < V[u].size(); i ++) {
		int v = V[u][i];
		if (vis[v]) continue;
		vis[v] = 1;
		if (!prv[v] || (prv[v] && bpm(prv[v]))) {
			prv[v] = u;
			return 1;
		}
	}
	return 0;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1; i <= m; i ++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (abs(a[i] - b[j]) <= 1) V[i].push_back(j);
		}
	}
	int rlt = 0;
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		if (bpm(i)) rlt ++;
	}
	printf("%d\n", rlt);
	return 0;
}