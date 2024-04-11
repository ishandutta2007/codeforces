#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
typedef unsigned long long LL;

const int N = 300000 + 10;
const int M = 30000000 + 10;
const LL MOD = 1e9 + 7;
std::mt19937_64 gen(std::chrono::steady_clock::now().time_since_epoch().count());
 
int n, q, a[N]; 
vector<int> g[N];
int pid, lson[M], rson[M], root[M];
LL sum[M], value[N];

void change(int old, int &k, int l, int r, int pos, LL x) {
	k = ++ pid;
	lson[k] = lson[old], rson[k] = rson[old], sum[k] = sum[old] ^ x;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) 
		change(lson[old], lson[k], l, mid, pos, x);
	else 
		change(rson[old], rson[k], mid+1, r, pos, x);
}
int query(int root1, int root2, int root3, int root4, int l, int r, int L, int R) {
	//printf("l=%d, r=%d, sum=%llu\n", l, r, (sum[root1] ^ sum[root2] ^ sum[root3] ^ sum[root4]));
	if ((sum[root1] ^ sum[root2] ^ sum[root3] ^ sum[root4]) == 0) return -1;
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	int ans = -1;
	if (L <= mid && ans == -1) ans = query(lson[root1], lson[root2], lson[root3], lson[root4], l, mid, L, R);
	if (R  > mid && ans == -1) ans = query(rson[root1], rson[root2], rson[root3], rson[root4], mid + 1, r, L, R);
	return ans;
}
int par[N][20], dep[N];
void dfs(int u, int p) {
	par[u][0] = p; 
	change(root[p], root[u], 1, n, a[u], value[a[u]]);
	dep[u] = dep[p] + 1;
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int d = dep[u] - dep[v];
	for (int i = 19; i >= 0; i --) if (d >> i & 1) u = par[u][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i --) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i], v = par[v][i];
		}
	}
	return par[u][0];
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++) 
		value[i] = gen();

	for (int i = 1; i <= n; i ++) 
		scanf("%d", &a[i]);
	
	for (int i = 1; i < n; i ++) {
		int u, v; 
		scanf("%d%d", &u, &v);
		g[u].push_back(v);	
		g[v].push_back(u);
	}	
	dfs(1, 1);	
	for (int i = 1; i < 20; i ++) {
		for (int j = 1; j <= n; j ++) {
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}
	while (q --) {
		int u, v, l, r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int parent = lca(u, v);
		//printf("u = %d, v = %d, parent = %d\n", u, v, parent);
		int res = query(root[u], root[v], root[parent], 
			parent == 1 ? root[0] : root[par[parent][0]], 
			1, n, l, r);
		printf("%d\n", res);
	}
}