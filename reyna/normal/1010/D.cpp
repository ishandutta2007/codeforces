// In the name of God

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

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<int> adj[N];
string op[N];
int val[N], res[N];
int dfs_init(int v) {
	if (op[v] == "IN") return val[v];
	if (op[v] == "NOT") return val[v] = !dfs_init(adj[v][0]);
	if (op[v] == "AND") {
		int ret = 1;
		for (int u : adj[v])
			ret &= dfs_init(u);
		return val[v] = ret;
	}
	if (op[v] == "XOR") {
		int ret = 0;
		for (int u : adj[v])
			ret ^= dfs_init(u);
		return val[v] = ret;
	}
	if (op[v] == "OR") {
		int ret = 0;
		for (int u : adj[v])
			ret |= dfs_init(u);
		return val[v] = ret;
	}
	
}
void dfs_res(int v, int ch = 1) {
	if (op[v] == "IN") {
		res[v] = val[0] ^ ch;
		return;
	}
	if (op[v] == "NOT" || op[v] == "XOR") {
		for (int u : adj[v])
			dfs_res(u, ch);
		return;
	}
	if (op[v] == "AND") {
		int x = adj[v][0];
		int y = adj[v][1];
		if (val[x] == 0 && val[y] == 1) {
			dfs_res(x, ch);	
			dfs_res(y, 0);
		} else if (val[x] == 1 && val[y] == 0) {
			dfs_res(x, 0);
			dfs_res(y, ch);
		} else if (val[x] == 1 && val[y] == 1) {
			dfs_res(x, ch);
			dfs_res(y, ch);
		} else {
			dfs_res(x, 0);
			dfs_res(y, 0);
		}
				
		return;
	}
	if (op[v] == "OR") {
		int x = adj[v][0];
		int y = adj[v][1];
		if (val[x] == 0 && val[y] == 1) {
			dfs_res(x, 0);	
			dfs_res(y, ch);
		} else if (val[x] == 1 && val[y] == 0) {
			dfs_res(x, ch);
			dfs_res(y, 0);
		} else if (val[x] == 0 && val[y] == 0) {
			dfs_res(x, ch);
			dfs_res(y, ch);
		} else {
			dfs_res(x, 0);
			dfs_res(y, 0);
		}
		return;
	}
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> op[j];
		if (op[j] == "IN") {
			cin >> val[j];	
		} else if (op[j] == "NOT") {
			int x;
			cin >> x;
			adj[j].pb(--x);
		} else {
			int x, y;
			cin >> x >> y;
			adj[j].pb(--x);
			adj[j].pb(--y);
		}
	}
	dfs_init(0);
	dfs_res(0);
	for (int j = 0; j < n; ++j)
		if (op[j] == "IN")
			cout << res[j];
}