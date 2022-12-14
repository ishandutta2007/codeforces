#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define M 30030

const int INF = 2e9 + 2;

int n, m, src, dst, xx, yy, x[M], y[M], w[M];
int dt[N], ft[N], low[N], dtime;
int bridge[M], gas, path[N];

bool vis[N];

vector <int> v[N], id[N];

int cnt = 0, del;

bool dfs(int u) {
    if (u == dst) return 1;
    vis[u] = 1;
    for (int i = 0, sz = v[u].size(); i < sz; i ++) if (!vis[v[u][i]]) {
		path[cnt++] = id[u][i];
		if (dfs(v[u][i])) return 1;
		cnt --;
    }
    return 0;
}

void Dfs (int x, int pre = 0){
	vis[x] = 1;
	low[x] = dt[x] = ++ dtime;
	for(int i = 0; i < v[x].size(); i ++){
		if(id[x][i] == del) continue;
		if(v[x][i] == pre){
			pre = 0;
			continue;
		}
		if(vis[v[x][i]]){
			low[x] = min(low[x], dt[v[x][i]]);
			continue;
		}
		Dfs (v[x][i], x);
		if(low[v[x][i]] > dt[x]) bridge[gas ++] = id[x][i];
		low[x] = min(low[x], low[v[x][i]]);
	}
	ft[x] = dtime;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &src, &dst);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d %d", &xx, &yy, &w[i]);
		v[xx].push_back(yy);
		v[yy].push_back(xx);
        id[xx].push_back(i);
        id[yy].push_back(i);
        x[i] = xx;
        y[i] = yy;
	}
	if (!dfs(src)) {
		puts("0\n0");
		return 0;
	}
	int ans1 = INF, ans2 = INF, id, id1, id2;
	for (int i = 0; i < cnt; i ++) {
		del = path[i];
		memset(vis, 0, sizeof vis);
		memset(ft, 0, sizeof ft);
		memset(dt, 0, sizeof dt);
		memset(low, 0, sizeof low);
		gas = 0;
		Dfs(src);
		if(dt[dst] == 0) {
			if(ans1 > w[del]) ans1 = w[del], id = del;
			continue;
		}
		for(int j = 0; j < gas; j ++){
			if(dt[x[bridge[j]]] <= dt[dst] && ft[dst] <= ft[x[bridge[j]]] && dt[y[bridge[j]]] <= dt[dst] && ft[dst] <= ft[y[bridge[j]]]){
				if(ans2 > w[del] + w[bridge[j]]) {
					ans2 = w[del] + w[bridge[j]], id1 = del, id2 = bridge[j];
				}
			}
		}
	}
	if(ans1 == INF && ans2 == INF){
		puts("-1");
		return 0;
	}
	if(ans1 < ans2) printf("%d\n1\n%d", ans1, id);
	else printf("%d\n2\n%d %d\n", ans2, id1, id2);
	return 0;
}