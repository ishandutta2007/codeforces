#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
struct edge { int u, v; ll w; int rev; };

int MOD = 1000000007;
 
vector<int> G[100000];
int parent[20][100000];
int depth[100000];
 
void dfs(int v, int p, int d) {
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p) dfs(G[v][i], v, d + 1);
}
 
void init(int V) {
	dfs(0, -1, 0);
	for (int k = 0; k + 1 < 20; k++)
		for (int v = 0; v < V; v++)
			if (parent[k][v] < 0) parent[k + 1][v] = -1;
			else parent[k + 1][v] = parent[k][parent[k][v]];
}
 
int lca(int u, int v) {
	if (depth[u] > depth[v]) swap(u, v);
	for (int k = 0; k < 20; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v) return u;
	for (int k = 20 - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v]) {
			u = parent[k][u];
			v = parent[k][v];
		}
	return parent[0][u];
}
 
int mydfs(int u, int p, vector<vector<int> >& index, vector<int>& up, vector<int>& UP) {
	int sum = up[u];
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (v == p) continue;
		int x = mydfs(v, u, index, up, UP);
		sum += x;
		int k = index[u][i];
		UP[k] += x;
	}
	return sum;
}

int pow_mod(ll x, ll n, int m) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) res = (res * x) % m;
		x = (x * x) % m;
	}
	return res;
}

int main() {
	int N; cin >> N;
	vector<vector<int> > index(N);
	vector<int> a(N - 1), b(N - 1), c(N - 1);
	for (int i = 0; i < N - 1; i++) {
		int x, y; cin >> x >> y >> c[i];
		G[x - 1].push_back(y - 1);
		G[y - 1].push_back(x - 1);
		index[x - 1].push_back(i);
		index[y - 1].push_back(i);
		a[i] = x - 1; b[i] = y - 1;
	}
	init(N);
	int K; cin >> K;
	vector<int> s(K + 1);
	for (int i = 1; i <= K; i++) {
		scanf("%d", &s[i]);
		s[i]--;
	}
	vector<int> up(N), down(N);
	for (int i = 0; i + 1 <= K; i++) {
		int x = lca(s[i], s[i + 1]);
		up[s[i]]++; up[x]--;
		down[s[i + 1]]++; down[x]--;
	}
	vector<int> UP(N - 1), DOWN(N - 1);
	mydfs(0, -1, index, up, UP);
	mydfs(0, -1, index, down, DOWN);
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		if (!c[i]) continue;
		int x = a[i], y = b[i];
		int t;
		if (depth[x] < depth[y]) t = UP[i];
		else t = DOWN[i];
		ans = (ans + pow_mod(2, t, MOD) - 1) % MOD;
	}
	cout << (ans + MOD) % MOD << endl;
}