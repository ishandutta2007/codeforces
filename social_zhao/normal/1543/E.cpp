#include<bits/stdc++.h>
using namespace std;

int get() {
	int x = 0, f = 1; char c = getchar();
	while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
	while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
	return x * f;
}

const int N = 65537, M = 1966081;
int n, node, dep[N], ansp[N], mxd, revp[N];
vector<int> adj[N], bin[N];
// struct Edge { int v, nxt; } edge[M << 2];
vector<int> edge[N];
unordered_map<int, int> lnk[N];
int pos[N], p[N], id, c[N], col[N], vis[N];
set<pair<int, int>> s;

void clear(int n) {
	for(int i = 0; i < n; i++) 
		adj[i].clear(), lnk[i].clear(), edge[i].clear(),
		dep[i] = ansp[i] = col[i] = vis[i] = c[i] = p[i] = pos[i] = 0;
	for(int i = 0; i <= mxd; i++) 
		bin[i].clear();
	mxd = 0, node = 0, id = 0;
}

void add(int u, int v) { edge[u].push_back(v); }

queue<int> q;
void bfs() {
	dep[0] = 1, q.push(0);
	while(q.size()) {
		int u = q.front(); q.pop();
		for(auto v : adj[u]) {
			if(!dep[v]) dep[v] = dep[u] + 1, q.push(v);
		}
	}
	mxd = 0;
	for(int i = 0; i < node; i++) mxd = max(mxd, dep[i]);
} 

void solve() {
	n = get(), node = 1 << n;
	for(int i = 1; i <= n * (1 << (n - 1)); i++) {
		int u = get(), v = get();
		adj[u].push_back(v), adj[v].push_back(u);
	}
//	printf("read\n");
	bfs();
	for(int i = 0; i < 1 << n; i++) bin[dep[i]].push_back(i);
	for(int i = 0; i < bin[2].size(); i++) 
		ansp[bin[2][i]] = 1 << i;
	for(int i = 3; i <= mxd; i++) {
		for(auto u : bin[i]) {
			for(auto v : adj[u]) 
				ansp[u] |= ansp[v];
		}
	}
	for(int i = 0; i < 1 << n; i++) revp[ansp[i]] = i;
	for(int i = 0; i < 1 << n; i++) cout << revp[i] << " "; cout << endl;
//	for(int i = 0; i < node; i++) {
//		for(int j = 0; j < adj[i].size(); j++)
//			for(int k = j + 1; k < adj[i].size(); k++) {
//				int u = adj[i][j], v = adj[i][k];
//				u = ansp[u], v = ansp[v];
//				if(lnk[u][v]) continue;
//				add(u, v), add(v, u), lnk[u][v] = lnk[v][u] = 1;
//			}
//	}
//	printf("%d\n", tot);
//		int res = GetMinCol();
//		cout << res << endl;
	for(int i = 0; i < 1 << n; i++)
		for(int j = 0; j < n; j++)
			if(i >> j & 1) col[i] ^= j;
	if(n == (n & (-n))) {
		for(int i = 0; i < 1 << n; i++) cout << col[ansp[i]] << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	clear(node);
}

int main() {
//	freopen("data.out", "r", stdin);
//	freopen("table.out", "w", stdout);
	int T = get();
	while(T--) solve();
	return 0;
}

/*
1
2
0 1
1 2
2 3
3 0
*/