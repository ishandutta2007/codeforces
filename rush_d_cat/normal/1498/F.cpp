#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100000 + 10;

int n, k;
vector<int> g[N];
int a[N];
int down[N][42], up[N][42], f[N][42];

void dfs(int u, int p) {
	down[u][0] = a[u];
	for (auto v: g[u]) {
		if (v == p) continue;
		dfs(v, u);
		for (int i = 0; i < 2 * k; i ++) {
			down[u][i] ^= down[v][(i-1+2*k) % (2*k)];
		}
	}
}
bool ans[N];
void dfsup(int u, int p) {
	int flag = 0;
	for (int i = 0; i < 2 * k; i ++) {
		f[u][i] = down[u][i] ^ up[u][i];
		if (i >= k) flag ^= f[u][i];
	}
	ans[u] = (flag > 0);
	
	for (auto v: g[u]) {
		if (v == p) continue;
		for (int i = 0; i < 2 * k; i ++) {
			f[u][i] ^= down[v][(i-1+2*k) % (2*k)];
		}
		for (int i = 0; i < 2 * k; i ++) 			
			up[v][i] = f[u][(i-1+2*k)%(2*k)];

		dfsup(v, u);
		for (int i = 0; i < 2 * k; i ++) {
			f[u][i] ^= down[v][(i-1+2*k) % (2*k)];
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i < n; i ++) {
		int u, v; 
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i ++) cin >> a[i];
	dfs(1, 1);
	dfsup(1, 1);
	for (int i = 1; i <= n; i ++) 
		cout << (ans[i]?1:0) << " ";
	cout<<endl;
}