#include <bits/stdc++.h>
using namespace std;
const int N = 8102;
int n;
vector<int> g[N];
struct SCC {
	int pre[N], low[N], sccno[N], dfs_clock, scc_cnt;
	stack<int> S;
	void dfs(int u) {
		pre[u] = low[u] = ++ dfs_clock;
		S.push(u);
		for (int i = 0; i < g[u].size(); i ++) {
			int v = g[u][i];
			if (! pre[v]) {
				dfs(v);
				low[u] = min(low[u], low[v]);
			} else if (! sccno[v]) {
				low[u] = min(low[u], pre[v]);
			}
		}
		if (low[u] == pre[u]) {
			scc_cnt ++;
			for (;;) {
				int x = S.top(); S.pop();
				sccno[x] = scc_cnt;
				if (x == u) break;
			}
		}
	}
	void Excalibur(int n) {
		for (int i = 1; i <= n; i ++) {
			pre[i] = low[i] = sccno[i] = 0;
		}
		while (S.size()) S.pop();
		dfs_clock = scc_cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (pre[i] == 0) dfs(i);
		}
	}
} Saber;

void add_edge(int x, int val_x, int y, int val_y) {
	//printf("%d %d %d %d\n", x,val_x,y,val_y);
	g[x<<1 | val_x].push_back(y<<1 | val_y);
}
int r, a[2002][2002], b[2002][2002], x[2002];
void read() {
	char s[2002];
	scanf("%d",&r); n = 2*r;
	for(int i=1;i<=r;i++){
		scanf("%s",s+1);
		for(int j=1;j<=r;j++){
			a[i][j] = s[j] - '0';
		}
	}
	for(int i=1;i<=r;i++){
		scanf("%s",s+1);
		for(int j=1;j<=r;j++){
			b[i][j] = s[j] - '0';
		}
	}
	scanf("%s",s+1);
	for(int j=1;j<=r;j++){
		x[j] = s[j] - '0';
	}
}
int main() {
	//freopen("in.txt", "r", stdin);
	read();
	// printf("ok\n");
	for (int i = 1; i <= r; i ++) {
		for (int j = 1; j <= r; j ++) {
			//printf("i=%d, j=%d\n",i,j);
			int u = i, v = j + r;
			if (a[i][j] == b[i][j]) {
				if (x[j] == 0 && x[i] == 0) {

				}
				if (x[j] == 0 && x[i] == 1) {
					add_edge(v, 1, v, 0);
				}
				if (x[j] == 1 && x[i] == 0) {
					add_edge(u, 1, u, 0);
				}
				if (x[j] == 1 && x[i] == 1) {
					add_edge(u, 0, v, 0);
					add_edge(u, 1, v, 1);
					add_edge(v, 0, u, 0);
					add_edge(v, 1, u, 1);
				}
			} else {
				if (x[j] == 0 && x[i] == 0) {
					return !printf("-1\n");
				}
				if (x[j] == 0 && x[i] == 1) {
					add_edge(v, 0, v, 1);
				}
				if (x[j] == 1 && x[i] == 0) {
					add_edge(u, 0, u, 1);
				}
				if (x[j] == 1 && x[i] == 1) {
					add_edge(u, 0, v, 1);
					add_edge(u, 1, v, 0);
					add_edge(v, 0, u, 1);
					add_edge(v, 1, u, 0);
				}
			}
		}
	}
	Saber.Excalibur(r * 4 + 2);
	for (int i = 1; i <= 2 * r; i ++) {
		//printf("i = %d (%d, %d)\n", i, Saber.sccno[i<<1], Saber.sccno[i<<1|1]);
		if(Saber.sccno[i << 1] == Saber.sccno[i<<1 | 1]) {
			return !printf("-1\n");
		}
	}

	vector<int> v1,v2;
	for (int i = 1; i <= r; i ++) {
		if (Saber.sccno[i << 1] > Saber.sccno[i <<1 | 1]) {
			//printf("row %d\n", i);
			v1.push_back(i);
		}
	}
	for (int i = r + 1; i <= 2 * r; i ++) {
		if (Saber.sccno[i << 1] > Saber.sccno[i <<1 | 1]) {
			//printf("col %d\n", i - r);
			v2.push_back(i-r);
		}
	}
	printf("%d\n", v1.size() + v2.size());
	for (auto x: v1) printf("row %d\n", x - 1);
	for (auto x: v2) printf("col %d\n", x - 1);
}