
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int sz[N], n;
vector<int> adj[N];
void dfs_init(int v, int p = -1) {
	sz[v] = 1;
	for (int u : adj[v]) if (u != p) {
		dfs_init(u, v);
		sz[v] += sz[u];
	}
}
int dfs_res(int v, int p, int sum) {
	int res = sum;
	for (int u : adj[v]) if (u != p) {
		res = max(res, dfs_res(u, v, sum - n + (n - sz[u]) + (n - sz[u])));		
	}
	return res;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs_init(0);
	int sum = 0;
	for (int v = 0; v < n; ++v)
		sum += sz[v];
	cout << 	dfs_res(0, -1, sum) << endl;
}