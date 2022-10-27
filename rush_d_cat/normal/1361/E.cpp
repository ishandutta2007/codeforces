#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
int t, n, m, FG = 0;
vector<int> g[N];
int vis[N], dfn[N], who[N], C;
pair<int, int> low[N];
void merge(pair<int, int>& p1, pair<int,int> p2) {
	vector<int> tmp;
	tmp.push_back(p1.first); tmp.push_back(p1.second);
	tmp.push_back(p2.first); tmp.push_back(p2.second);
	sort(tmp.begin(), tmp.end());
	p1.first = tmp[0];
	p1.second = tmp[1];
}
void chk(int u, bool & fg) {
	vis[u] = 1; 
	for (auto v: g[u]) {
		// printf("%d -> %d(%d)\n", u, v, vis[v]);
		if (vis[v] == 1) {
			continue;
		}
		if (vis[v] == 2) {
			fg = false; return;
		}
		chk(v, fg);
	}
	vis[u] = 2;	
}
void dfs(int u, bool & fg) {
	vis[u] = 1; dfn[u] = ++ C; who[C] = u;
	for (auto v: g[u]) {
		// printf("%d -> %d(%d)\n", u, v, vis[v]);
		if (vis[v] == 1) {
			merge(low[u], make_pair(dfn[v], N));
			continue;
		}
		if (vis[v] == 2) {
			fg = false; return;
		}
		dfs(v, fg);
		merge(low[u], low[v]);
	}
	vis[u] = 2;
}
bool ok[N];
void solve(int u) {
	vis[u] = 1;
	ok[u] = (low[u].second >= dfn[u]);
	// printf("%d / %d %d\n", u, low[u].first, low[u].second);
	
	int x = who[ low[u].first ];
	if (x <= n && x >= 1 && ok[x] == 0) ok[u] = 0;
	for (auto v: g[u]) {
		if (vis[v]) {
			continue;
		}
		solve(v);
	}	
 
}
void output() {
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i ++) {
		for (auto j: g[i]) {
			printf("%d %d\n", i, j);
		}
	}
}
bool check() {
	for (int it = 1; it <= 100; it ++) {
		int x = (1LL * rand() * rand()) % n + 1;	
		for (int i = 1; i <= n; i ++) {
			vis[i] = 0;
		}
		C = 0;
		bool can = true;
		chk(x, can);
		if (can) {
			for (int i = 1; i <= n; i ++) {
				vis[i] = dfn[i] = 0; low[i] = make_pair(N, N);
			}
			dfs(x, can);
			for (int i = 1; i <= n; i ++) {
				ok[i] = vis[i] = 0;
			}
			solve(x);
			vector<int> ans;
			for (int i = 1; i <= n; i ++) if (ok[i]) ans.push_back(i);
			int mx = n / 5; 
			if (n % 5 == 0) {
				mx --;
			}
			if (ans.size() <= mx) {
				printf(" ");
				return false;
			}
			for (auto x: ans) {
				printf("%d ", x);  
			}
			printf("\n");
			return true;
		}
	}
	return false;
}
int main() {
	srand(time(0));
	scanf("%d", &t); 
	while (t --) {
		scanf("%d%d",&n,&m);
		for (int i = 1; i <= n; i ++) {
			g[i].clear();
		}
		for (int i = 1; i <= m; i ++) {
			int u, v; scanf("%d%d", &u, &v);
			g[u].push_back(v); 
		}
		if (check() == false) {
			printf("-1\n"); 
		} 
	}
}