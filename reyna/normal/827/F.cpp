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

const int N = (int) 3e6 + 6, mod = (int) 0;
vector<int> adj[N], ex[N][2];
int eu[N], ev[N], el[N], er[N], d[N];
int by_l(int x, int y) { return el[x >> 2] > el[y >> 2]; }
int main() {
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int e = 0; e < m; ++e) {
		int a = e << 2 | 0, b = a | 1, c = a | 2, d = a | 3;
		int &u = eu[e], &v = ev[e], &l = el[e], &r = er[e];
		cin >> u >> v >> l >> r;
		--u, --v, ++r;
		if (u > v) swap(u, v);
		ex[u][0].pb(a);
		ex[u][1].pb(b);
		ex[v][0].pb(c);
		ex[v][1].pb(d);
		adj[a].push_back(d);
		adj[b].push_back(c);
		adj[d].push_back(a);
		adj[c].push_back(b);
	}
	for (int v = 0; v < n; ++v)
		for (int p = 0; p <= 1; ++p)
			sort(ex[v][p].begin(), ex[v][p].end(), by_l);
	memset(d, 63, sizeof d);
	set<pair<int, int>> st;
	for (int e = 0; e < m; ++e) {
		int a = e << 2 | 0;
		int &u = eu[e], &v = ev[e], &l = el[e], &r = er[e];
		if (l == 0 && u == 0) {
			d[a] = 0;
			st.insert(mp(d[a], a));
		}
	}
	while ((int) st.size()) {
		auto cur = *(st.begin());
		st.erase(cur);
		int ind = cur.second, e = ind >> 2;
		int u = eu[e], v = ev[e], l = el[e], r = er[e], parity = 0;
		if (ind & 2) {
			swap(u, v);	
		}
		parity = ind & 1;
		if (d[ind] + 1 < r) for (int x : adj[ind]) {
			if (d[ind] + 1 < d[x]) {
				st.erase(mp(d[x], x));
				d[x] = d[ind] + 1;	
				st.insert(mp(d[x], x));
			}
		}
		int curd = cur.first;
		while ((int) ex[u][parity].size()) {
			int nxe = ex[u][parity].back();
			if (curd >= er[nxe >> 2]) {
				ex[u][parity].pop_back();
			} else {
				int after = el[nxe >> 2];
				while ((after ^ parity) & 1) ++after;
				after = max(after, curd);
				if (after >= r) break;
				if (after < er[nxe >> 2]) {
					if (d[nxe] > after) {
						st.erase(mp(d[nxe], nxe));
						d[nxe] = after;
						st.insert(mp(d[nxe], nxe));
					}
				}
				ex[u][parity].pop_back();
			}
		}
	}
	int res = 2e9;
	for (int j = 0; j < 4 * m; ++j) {
		int e = j >> 2;
		int u = eu[e], v = ev[e], l = el[e], r = er[e];
		if (j & 2) {
			swap(u, v);
		}
		if (u == n - 1) {
			res = min(res, d[j]);	
		}
	}
	if (res > (int) 1e9 + 10) {
		res = -1;	
	}
	cout << res << '\n';
}