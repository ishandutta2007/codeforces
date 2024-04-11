#include <bits/stdc++.h>

using namespace std;

#define N 5005

using namespace std;

vector <int> V[N], RV[N], id[N];

int vis[N];
int ord[N], ft;

int col[N], C, ok[N];

int n, m, ans;

void DFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < V[u].size(); i ++) {
		int v = V[u][i];
		if (!vis[v]) DFS(v);
	}
	ord[ft --] = u;
}

void DFS_(int u) {
	vis[u] = 1;
	col[u] = C;
	for (int i = 0; i < RV[u].size(); i ++) {
		int v = RV[u][i];
		if (!vis[v]) DFS_(v);
	}
}

int q[N], d[N][N], T;

void run() {
	for(int i = 1; i <= n; i ++) vis[i] = 0;
	for(int i = 1; i <= n; i ++) id[col[i]].push_back(i);
	ans = n;
	for(int i = 1; i <= C; i ++) if(!ok[i]) {
		int cnt = (int)id[i].size();
if(cnt == 1) continue;
		for(int j = 0; j < cnt; j ++) {
			int k = id[i][j];
			int h = 0, t = 0;
			++ T;
			vis[k] = T;
			q[t ++] = k;
			d[k][k] = 0;
			while(h < t) {
				int tp = q[h ++];
				for(int r = 0; r < (int)V[tp].size(); r ++) {
					int rr = V[tp][r];
					if(col[rr] != i || vis[rr] == T) continue;
					vis[rr] = T;
					q[t ++] = rr;
					d[k][rr] = d[k][tp] + 1;
				}
			}
		}
		int mn = N;
		for(int j = 0; j < cnt; j ++) {
			int k = id[i][j];
			for(int r = 0; r < (int)V[k].size(); r ++) {
				int rr = V[k][r];
				if(col[rr] != i) continue;
				if(mn > d[rr][k]) mn = d[rr][k];
			}
		}
		ans += 998 * (mn + 1) + 1;
	}
	printf("%d\n", ans);
}

int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);

	for (int k = 1; k <= m; k ++) {
		int i, j;
		scanf("%d %d", &i, &j);
		V[i].push_back(j);
		RV[j].push_back(i);
	}

	ft = n;
	for (int i = 1; i <= n; i ++) if (!vis[i]) DFS(i);
	for (int i = 1; i <= n; i ++) vis[i] = 0;

	C = 0;
	for (int i = 1; i <= n; i ++) if (!vis[ord[i]]) {
		C ++;
		DFS_(ord[i]);
	}
	for(int i = 1; i <= n; i ++) {
		int cc = col[i];
		for(int j = 0; j < (int)V[i].size(); j ++) {
			int k = V[i][j];
			if(col[k] != cc) ok[cc] = 1;
		}
	}
	run();
	return 0;
}