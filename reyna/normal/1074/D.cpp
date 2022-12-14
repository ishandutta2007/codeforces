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

const int N = (int) 1e6 + 5, mod = (int) 0;
vector<int> comp[N];
vector<pair<int, int>> adj[N];
int d[N], par[N], cnt;
map<int, int> save;
void dfs(int v, int p, int t) {
	d[v] = t;
	for (auto e : adj[v]) if (e.first != p) {
		dfs(e.first, v, t ^ e.second);	
	}
}
void unite(int u, int v, int w) {
	int pu = par[u];
	int pv = par[v];
	if (pu == pv) return;
	adj[u].pb(mp(v, w));
	adj[v].pb(mp(u, w));
	if (comp[pu].size() > comp[pv].size()) swap(pu, pv), swap(u, v);
	dfs(u, v, d[v] ^ w);
	for (int x : comp[pu]) comp[pv].push_back(x), par[x] = pv;
}
int main() {
	ios_base::sync_with_stdio(0);
	int q, last = 0;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		int xu, xv;
		cin >> xu >> xv;
		xu = xu ^ last;
		xv = xv ^ last;
		if (xu > xv) swap(xu, xv);
		++xv;
		if (save.find(xu) == save.end()) {
			save[xu] = cnt;
			par[cnt] = cnt;
			comp[cnt].pb(cnt);
			d[cnt] = 0;
			++cnt;
		}
		if (save.find(xv) == save.end()) {
			save[xv] = cnt;
			par[cnt] = cnt;
			comp[cnt].pb(cnt);
			d[cnt] = 0;
			++cnt;
		}
		int u = save[xu], v = save[xv];
		if (t == 2) {
			if (par[u] != par[v]) {
				last = 1;
				cout << -1 << '\n';
				continue;
			}
			last = d[u] ^ d[v];
			cout << last << '\n';
		} else {
			int w;
			cin >> w;
			w ^= last;
			if (par[u] == par[v]) {
				continue;
			}
			unite(u, v, w);
		}
	}
}