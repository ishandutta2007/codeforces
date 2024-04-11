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

const int N = (int) 2e5 + 5, M = 26, mod = (int) 0;
vector<int> adj[N];
int flag = 1, h[N], sum[N], can[N], mx[N][26], deg[N], par[N], up[N], rp[N], way[N], has[N][2][26], child[N][2];
void dfs(int v, int p = -1, int w = -1) {
	if (v != 0) {
		rp[v] = p;
		way[v] = w;
	}
	vector<int> dw;
	for (int j = 0; j < (int) adj[v].size(); ++j) {
		int u = adj[v][j];
		int good = (deg[v] > 1 || p == -1);
		int np = (good ? v : p);
		int nw = (good ? j : w);
		dfs(u, np, nw);
		dw.pb(h[u] + 1);
	}
	if ((int) dw.size() > 1 && dw[0] != dw[1]) {
		flag = 0;
	}
	if (dw.size() > 0)
		h[v] = dw[0];
	else
		h[v] = 0;
	
}
void update(int v) {
	int o = 1;
	if (v == 0 && (int) adj[v].size() == 1) o = 0;
	int x = child[v][0], y = child[v][o];
	int s = 0;
	for (int c = 0; c < 26; ++c) {
		mx[v][c] = max(mx[x][c] + has[v][0][c], mx[y][c] + has[v][o][c]);
		s += mx[v][c];
	}
	if (s <= h[v]) {
		can[v] = 0;	
	} else {
		can[v] = 1;
	}
	sum[v] = sum[x] + o * sum[y] + can[v];
	if (v != 0) update(rp[v]);
}
void add(int v, int c, int to_add) {
	has[rp[v]][way[v]][c] += to_add;
	update(rp[v]);
}
int main() {
	ios_base::sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for (int j = 1; j < n; ++j) {
		int p;
		cin >> p;
		char c;
		cin >> c;
		--p;
		par[j] = p;
		adj[p].pb(j);
		++deg[p];
		up[j] = (c == '?' ? 26 : c - 'a');
	}
	dfs(0);
	for (int v = 1; v < n; ++v)
		if (deg[v] != 1)
			child[rp[v]][way[v]] = v;
	for (int j = 1; j < n; ++j) {
		if (up[j] != 26) {
			add(j, up[j], 1);	
		}
	}
	while (q--) {
		int v;
		char c;
		cin >> v >> c; --v;
		int ch = (c == '?' ? 26 : c - 'a');
		if (up[v] != 26) add(v, up[v], -1);
		up[v] = ch;
		if (up[v] != 26) add(v, up[v], +1);
		if (!flag || sum[0] > 0) {
			cout << "Fou\n";
		} else {
			cout << "Shi ";
			long long res = 0;
			int s = 0;
			for (int j = 0; j < 26; ++j) {
				s += mx[0][j];
			}
			assert(s <= h[0]);
			int qmark = h[0] - s;
			for (int j = 0; j < 26; ++j)
				res += (j + 1) * (LL) (mx[0][j] + qmark);
			cout << res << '\n';
		}
	}
}