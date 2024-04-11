
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

const int N = (int) 2005, mod = (int) 0;
int sz[N], c[N], res[N];
vector<int> adj[N];
void dfs_init(int v, int p = -1) {
	sz[v] = 1;
	for (int u : adj[v]) {
		dfs_init(u, v);
		sz[v] += sz[u];
	}
	
}
void dfs_res(int v, vector<int> all) {
	sort(ALL(all));
	res[v] = all[c[v]];
	vector<int> nxt;
	for (int x : all) if (x != res[v]) nxt.pb(x);
	for (int u : adj[v]) {
		vector<int> go;
		while ((int) go.size() != sz[u]) go.pb(nxt.back()), nxt.pop_back();
		dfs_res(u, go);
	}
}
int main() {
	int n, root = 0;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		int p;
		cin >> p >> c[j];
		--p;
		if (p == -1) root = j;
		else adj[p].pb(j);
	}
	vector<int> all;
	for (int j = 0; j < n; ++j) all.pb(j);
	dfs_init(root);
	for (int v = 0; v < n; ++v)
		if (sz[v] - 1 < c[v]) {
			cout << "NO\n";
			return 0;
		}
	dfs_res(root, all);
	cout << "YES\n";
	for (int j = 0; j < n; ++j)
		cout << 1 + res[j] << ' ';
}