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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int d[N], n, mark[N];
set<pair<int, pair<int, int>>> st;
vector<pair<pair<int, int>, int>> adj[N];
vector<pair<int, int>> seg[N << 2];
void put(int i, int j, pair<int, int> x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j) return;
	if (i <= b && e <= j) {
		seg[v].push_back(x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	put(i, j, x, l, b, m);
	put(i, j, x, r, m, e);
}
void query(int pos, int v = 1, int b = 0, int e = n) {
	for (auto x : seg[v]) {
		st.insert(mp(d[pos] + x.y, mp(x.x, x.x + 1)));
	}
	seg[v].clear();
	if (b + 1 == e) {
		return;		
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (pos < m)
		query(pos, l, b, m);
	else
		query(pos, r, m, e);
}
void relax(int v) {
	query(v);
	for (auto e : adj[v]) {
		st.insert(mp(d[v] + e.y, mp(e.x.x, e.x.y)));
	}
}
int32_t main() {
	//wtf;
	ios_base::sync_with_stdio(0);
	int q, s;
	cin >> n >> q >> s; --s;
	set<int> all;
	for (int j = 0; j < n; ++j) all.insert(j);
	memset(d, 63, sizeof d);
	d[s] = 0;
	st.insert(mp(d[s], mp(s, s + 1)));
	for (int j = 0; j < q; ++j) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v, w;
			cin >> u >> v >> w;
			--u, --v;
			adj[u].push_back(mp(mp(v, v + 1), w));
		} else {
			int v, l, r, w;
			cin >> v >> l >> r >> w;
			--l; --v;
			if (t == 2) {
				adj[v].push_back(mp(mp(l, r), w));
			} else {
				put(l, r, mp(v, w));
			}
		}	
	}
	while (st.size()) {
		auto x = *(st.begin());
		st.erase(x);
		int l = x.y.x, r = x.y.y, w = x.x;
		vector<int> p;
		while (true) {
			auto it = all.lower_bound(l);
			if (it == all.end() || *it >= r) break;
			d[*it] = w;
			p.pb(*it);
			all.erase(*it);
		}
		for (int v : p) {
			relax(v);
		}
	}
	for (int j = 0; j < n; ++j)
		cout << (d[j] > 2e18 ? -1 : d[j]) << ' ';
}