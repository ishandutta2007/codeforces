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

const int N = (int) 2005, mod = (int) 0;
int cnt;
vector<int> ver, adj[N];
int sz[N], mark[N], par[N], see[N], some[N];
char ask(int x, int y, int z) {
	cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << endl;
	char res;
	cin >> res;
	return res;
}
void dfs_sz(int v) {
	sz[v] = 1;
	ver.push_back(v);
	for (int x : adj[v]) if (!mark[x]) {
		dfs_sz(x);
		sz[v] += sz[x];
	}
	return;
}
void solve(int root, int add) {
	if (mark[root]) {
		int p = par[root];
		int nw = cnt++;
		see[nw] = 1;
		par[root] = nw;
		par[add] = nw;
		par[nw] = p;
		return;
	}
	ver.clear();
	dfs_sz(root);
	if (ver.size() == 1) {
		int p = par[root];
		int nw = cnt++;
		see[nw] = 1;
		par[root] = nw;
		par[add] = nw;
		par[nw] = p;
		return;
	}
	int cen = root;
	for (int x : ver) 
		if (sz[x] > sz[root] / 2 && sz[x] < sz[cen]) 
			cen = x;
	int x = adj[cen][0], y = adj[cen][1];
	int res_ask = ask(some[x], some[y], add);
	if (res_ask == 'X') {
	    mark[x] = mark[y] = 1;
		solve(root, add);
	} else if (res_ask == 'Y') {
	    mark[cen] = 1;
		solve(y, add);
	} else {
	    mark[cen] = 1;
		solve(x, add);
	}
}
void get_some(int rt) {
	if (adj[rt].size() == 0) {
		some[rt] = rt;
		return;
	}
	for (int x : adj[rt])
		get_some(x);
	some[rt] = some[adj[rt][0]];
}
void do_solve(int root, int add) {
	memset(mark, 0, sizeof mark);
	get_some(root);
	solve(root, add);
}
int main() {
	int n;
	cin >> n; cnt = n;
	par[0] = -1;
	see[0] = 1;
	for (int add = 1; add < n; ++add) {
		int root = -1;
		for (int j = 0; j < 2 * n; ++j)
			if (par[j] == -1)
				root = j;
		for (int j = 0; j < 2 * n; ++j) {
			if (see[j]) {
				if (par[j] >= 0)
					adj[par[j]].push_back(j);
			}
		}
		do_solve(root, add);
		for (int j = 0; j < 2 * n; ++j) {
			adj[j].clear();
		}
		see[add] = 1;
	}
	cout << -1 << endl;
	for (int j = 0; j < cnt; ++j) {
		cout << (par[j] == -1 ? -1 : par[j] + 1) << ' ';
	}
	cout << endl;
}