#include <bits/stdc++.h>

using namespace std;

#define N 400400
const int inf = 1000000000;
vector <int> v[N];
int n, pa[N], sz[N], ans[N], R, RR;

void dfs(int r) {
	sz[r] = 1;
	for(int i = 0; i < v[r].size(); i ++) {
		int u = v[r][i];
		if(u == pa[r]) continue;
		pa[u] = r;
		dfs(u);
		sz[r] += sz[u];
	}
}

int tp;

void DFS(int r) {
	for(int i = 0; i < v[r].size(); i ++) {
		int u = v[r][i];
		if(u == pa[r]) continue;
		pa[u] = r;
		DFS(u);
	}
	if(n - sz[r] - tp > n / 2) ans[r] = 0; else ans[r] = 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; i ++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y); v[y].push_back(x);
	}
	dfs(1);
	R = -1, RR = 1;
	for(int i = 1; i <= n; i ++) {
		int ok = 1;
		for(int j = 0; j < v[i].size(); j ++) {
			int k = v[i][j];
			if(k == pa[i]) continue;
			if(sz[k] > n / 2) ok = 0;
		}
		if(sz[1] - sz[i] > n / 2) ok = 0;
		if(ok) {
			if(R != -1) RR = 0;
			else R = i;
		}
	}
	if(!RR) {
		for(int i = 1; i <= n; i ++) ans[i] = 1;
	} else {
		pa[R] = 0;
		dfs(R);
		int mx = -1, mmx = -1, id;
		for(int i = 0; i < v[R].size(); i ++) {
			int u = v[R][i];
			if(sz[u] > mx) mx = sz[u], id = u;
		}
		for(int i = 0; i < v[R].size(); i ++) {
			int u = v[R][i];
			if(u == id) continue;
			if(sz[u] > mmx) mmx = sz[u];
		}
		for(int i = 0; i < v[R].size(); i ++) {
			int u = v[R][i];
			if(u != id) tp = mx; else tp = mmx;
			pa[u] = R;
			DFS(u);
		}
		ans[R] = 1;
	}
	for(int i = 1; i <= n; i ++) printf("%d ", ans[i]); puts("");
	return 0;
}