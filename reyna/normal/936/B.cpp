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
vector<int> out[N], adj[N];
int h[N], deg[N], mark[N], op[N], tot;
void add_edge(int u, int v) {
	adj[u].pb(v);
	deg[u]++;
}
int dfs_draw(int v, int p = -1) {
	if (h[v]) return 0;
	op[v] = 1;
	int res = 0;
	h[v] = (p == -1 ? 1 : h[p] + 1);
	for (int u : out[v]) {
		if (op[u]) {
			res = 1;
		}
		res |= dfs_draw(u, v);
	}
	op[v] = 0;
	return res;
}
int path[N], ed;
void dfs_path(int v) {
	if (mark[v]++) return;
	path[ed++] = v;
	if ((v & 1) && deg[v] == 0) {
		cout << "Win\n";
		for (int j = 0; j < ed; ++j) cout << path[j] / 2 + 1 << ' ';
		cout << '\n';
		exit(0);
	}
	for (int u : adj[v]) dfs_path(u);	
	--ed;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < n; ++j) {
		int k;
		cin >> k;
		while (k--) {
			int x;
			cin >> x;
			--x;
			out[j].pb(x);
			add_edge(j << 1, x << 1 | 1);
			add_edge(j << 1 | 1, x << 1);
		}
	}
	int st;
	cin >> st;
	--st;
	int draw = dfs_draw(st);
	dfs_path(st << 1);
	if (draw) {
		cout << "Draw\n";
	} else {
		cout << "Lose\n";
	}
}