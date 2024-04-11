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

const int N = (int) 3e5 + 5, sq = 430, mod = (int) 0;

int n, cur_pt[N][2], need[N], rev[N], par[N], a[N], b[N], st[N], ed[N], tot, to_add[N];
long long lh[N], lm[N];
vector<int> adj[N];
vector<int> hull[N][2];
int cmp(int x, int y) {
	return lh[x] == lh[y] ? lm[x] > lm[y] : lh[x] > lh[y];	
}
void dfs_init(int v, int p = -1) {
	if (p != -1) {
		a[v] += a[p];
		b[v] += b[p];
	}
	st[v] = tot++;
	rev[st[v]] = v;
	for (int u : adj[v]) if (u != p) {
		dfs_init(u, v);
	}
	ed[v] = tot;
}
long long when(int x, int y) {
	if (lh[x] < lh[y]) swap(x, y);
	return (lh[x] - lh[y] + lm[y] - lm[x] - 1) / (lm[y] - lm[x]);
}
void build(int id) {
	int b = id * sq, e = min(n, (id + 1) * sq);
	for (int turn = 0; turn <= 1; ++turn) {
		hull[id][turn].clear();
	}
	need[id] = 1e9 + 200;
	vector<int> all[2];
	for (int j = b; j < e; ++j) {
		int cur = rev[j], turn = 0;
		a[cur] += to_add[id];
		if (a[cur] < 0) {
			need[id] = min(need[id], -a[cur]);
			turn = 1;
		}
		all[turn].pb(cur);	
		lh[cur] = abs((LL) a[cur] * ::b[cur]);
		lm[cur] = (a[cur] < 0 ? -1 : 1) * ::b[cur];
	}
	to_add[id] = 0;
	for (int turn = 0; turn <= 1; ++turn) {
		cur_pt[id][turn] = 0;
		sort(ALL(all[turn]), cmp);
		long long mx = -1e18;
		for (int x : all[turn]) {
			if (lm[x] > mx) {
				mx = lm[x];
				while ((int) hull[id][turn].size() > 1 && when(hull[id][turn][hull[id][turn].size() - 2], hull[id][turn][hull[id][turn].size() - 1]) > when(hull[id][turn][hull[id][turn].size() - 2], x)) hull[id][turn].pop_back();
				hull[id][turn].pb(x);	
			}
		}
	}	
}
void update(int b, int e, int x) {
	int idb = b / sq;
	int ide = e / sq;
	if (idb == ide) {
		for (int j = b; j < e; ++j) {
			a[rev[j]] += x;
		}
		build(idb);
		return;
	}
	int see = 0;
	while (b % sq != 0) {
		see = 1;
		a[rev[b]] += x;
		++b;
	}
	if (see) {
		build(idb);
	}
	see = 0;
	while (e % sq != 0) {
		see = 1;
		--e;
		a[rev[e]] += x;
	}
	if (see) {
		build(ide);
	}
	b /= sq;
	e /= sq;
	for (int j = b; j < e; ++j) {
		to_add[j] += x;
		if (to_add[j] > need[j]) {
			build(j);	
		}
	}
}
long long get_best(int id) {
	long long res = 0;
	for (int turn = 0; turn <= 1; ++turn) {
		if ((int) hull[id][turn].size() == 0) continue;
		int &pt = cur_pt[id][turn];
		while (pt < (int) hull[id][turn].size() - 1 && when(hull[id][turn][pt], hull[id][turn][pt + 1]) <= to_add[id]) ++pt;
		int cur_id = hull[id][turn][pt];
		res = max(res, abs(((LL) a[cur_id] + to_add[id]) * b[cur_id]));
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	int q;
	cin >> n >> q;
	par[0] = -1;
	for (int j = 1; j < n; ++j) {
		cin >> par[j];
		--par[j];
		adj[par[j]].pb(j);	
	}
	for (int j = 0; j < n; ++j) cin >> a[j];
	for (int j = 0; j < n; ++j) cin >> b[j];
	dfs_init(0);
	for (int j = 0; j < n; ++j) if (b[j] < 0) b[j] *= -1;
	for (int j = 0; j * sq < n; ++j) build(j);
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) {
			int v, x;
			cin >> v >> x;
			--v;
			update(st[v], ed[v], x);
		} else {
			int v;
			cin >> v;
			--v;
			int b = st[v];
			int e = ed[v];
			int idb = b / sq;
			int ide = e / sq;
			long long res = 0;
			if (idb == ide) {
				for (int j = b; j < e; ++j)
					res = max(res, abs((LL) (a[rev[j]] + to_add[idb]) * ::b[rev[j]]));
				cout << res << '\n';
				continue;
			}
			while (b % sq != 0) {
				res = max(res, abs((LL) (a[rev[b]] + to_add[idb]) * ::b[rev[b]]));
				++b;
			}
			while (e % sq != 0) {
				--e;
				res = max(res, abs((LL) (a[rev[e]] + to_add[ide]) * ::b[rev[e]]));
			}
			b /= sq;
			e /= sq;
			for (int j = b; j < e; ++j)
				res = max(res, get_best(j));
			cout << res << '\n';
		}
	}
}