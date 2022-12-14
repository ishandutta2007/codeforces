
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
int n, sz[N], g, b;
vector<pair<int, int>> adj[N];
void dfs(int v, int p = -1, int ep = 0) {
	sz[v] = 1;
	for (auto e : adj[v]) if (e.first != p) {
		dfs(e.first, v, e.second);
		sz[v] += sz[e.first];
	}
	if (sz[v] & 1) {
		g += ep;
	}
	b += min(2 * n - sz[v], sz[v]) * ep;
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int j = 0; j < 2 * n; ++j) adj[j].clear();
		for (int j = 0; j < 2 * n - 1; ++j) {
			int u, v, w;
			cin >> u >> v >> w;
			--u, --v;
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		dfs(0);
		cout << g << ' ' << b << '\n';
		g = b = 0;
	}
}