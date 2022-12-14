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

const int N = (int) 2e5 + 5, mod = (int) 0;
vector<int> adj[N], ver;
int sz[N], mark[N], hs[N];
long long add_up[N], res[N];
string s;
void dfs_cen(int v, int p = -1) {
	ver.push_back(v);
	sz[v] = 1;
	for (int u : adj[v]) if (!mark[u] && u != p) {
		dfs_cen(u, v);
		sz[v] += sz[u];
	}
}
void dfs_get_hashs(int v, int p = -1) {
	hs[v] = (p == -1 ? 1 << (s[v] - 'a') : hs[p] ^ (1 << (s[v] - 'a')));
	for (int u : adj[v]) if (!mark[u] && u != p) {
		dfs_get_hashs(u, v);	
	}
}
int cnt[1 << 20];
void get_values(int root, int px) {
	for (int x : ver) if (root != x) cnt[hs[x]]++;
	for (int x : ver) if (root != x) {
		int val = cnt[(1 << s[root] - 'a') ^ hs[x]];
		add_up[x] += (px == 1 ? val : -val);
		for (int j = 0; j < 20; ++j) {
			int val = cnt[(1 << j) ^ (1 << (s[root] - 'a')) ^ hs[x]];	
			add_up[x] += (px == 1 ? val : -val);	
		}
	}
	for (int x : ver) if (root != x) cnt[hs[x]]--;
}
void dfs_add_values(int v, int p = -1) {
	for (int u : adj[v]) if (!mark[u] && u != p) {
		dfs_add_values(u, v);	
		add_up[v] += add_up[u];
	}
	res[v] += add_up[v];
}
void solve(int v) {
	ver.clear();
	dfs_cen(v);
	int root = v;
	for (int u : ver) if (sz[u] >= sz[root] / 2 && sz[u] < sz[v]) {
		v = u;	
	}
	vector<int> orig_ver = ver;
	dfs_get_hashs(v);
	get_values(v, +1);
	for (int u : adj[v]) if (!mark[u]) {
		ver.clear();
		dfs_cen(u, v);
		get_values(v, -1);
	}
	int adds = 1;
	for (int x : orig_ver) if (x != v) {
		int ss =  hs[x];
		if (ss == 0 || (ss & (ss - 1)) == 0) {
			++add_up[x];	
			adds++;
		}
			
	}
	add_up[v] += adds;
	dfs_add_values(v);
	res[v] -= add_up[v] / 2;
	mark[v] = 1;
	for (int x : orig_ver) add_up[x] = 0;
	for (int u : adj[v]) if (!mark[u]) {
		solve(u);	
	}
}


int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	cin >> s;
	solve(0);
	for (int j = 0; j < n; ++j)
		cout << res[j] << ' ';
	
}