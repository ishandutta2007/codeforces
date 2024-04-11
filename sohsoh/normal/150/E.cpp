#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops,O3")

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

constexpr ll MAXN = 1e5 + 10;

int sz[MAXN], n, tl, tr, ans;
bool B[MAXN];
vector<pll> adj[MAXN], tmp;
vector<int> w_vec;

namespace centroid {
	vector<int> tadj[MAXN];
	vector<pll> centroid_vec;
	int tsz[MAXN];

	int dfs_sz(int v, int p) {
		sz[v] = 1;
		for (auto [u, w] : adj[v])
			if (u != p && !B[u])
				sz[v] += dfs_sz(u, v);
		return sz[v];
	}

	int find_centroid(int v, int p, int n) {
		for (auto [u, w] : adj[v])
			if (u != p && !B[u] && sz[u] * 2 > n)
				return find_centroid(u, v, n);
		return v;
	}

	void build(int v, int p = 0) {
		int tn = dfs_sz(v, 0);
		v = find_centroid(v, 0, tn);
		
		tadj[p].push_back(v);
		tsz[v] = tn;
		B[v] = true;
		centroid_vec.push_back({v, tn});
	
		for (auto [u, w] : adj[v])
			if (!B[u])
				build(u, v);
	}

	inline void build_centroid_vec() {
		build(1, 0);
		queue<int> q;
		q.push(0);

		while (!q.empty()) {	
			int v = q.front();
			q.pop();

			for (int u : tadj[v]) {
				q.push(u);
				centroid_vec.push_back({u, tsz[u]});
			}
		}
	}
}

namespace segment {
	int sg[MAXN << 2], pt;

	inline void init() {
		fill(sg, sg + (MAXN << 2), -MAXN);
		pt = 0;
	}

	void update_t(int ind, int val, int l = 0, int r = n, int v = 1) {
		if (l == r) sg[v] = max(sg[v], val);
		else {
			int mid = (l + r) >> 1;
			if (ind <= mid) update_t(ind, val, l, mid, v << 1);
			else update_t(ind, val, mid + 1, r, v << 1 | 1);
			sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
		}
	}

	int query_t(int ql, int qr, int l = 0, int r = n, int v = 1) {
		if (ql > r || qr < l) return -MAXN;
		if (ql <= l && qr >= r) return sg[v];

		int mid = (l + r) >> 1;
		return max(query_t(ql, qr, l, mid, v << 1),
				query_t(ql, qr, mid + 1, r, v << 1 | 1));
	}

	inline void update(int ind, int val) {
		ind += pt; 
		update_t(ind, val);
	}

	inline int query(int l, int r, int n) {
		l += pt;
		r += pt;
	
		l = max(l, pt);
		r = min(r, n - 1 + pt);	

		if (l > r) return -MAXN;
		return query_t(l, r);
	} 
};

void dfs(int v, int p, int delta, int x, int dist, int tn) {
	if (segment::query(tl - dist, tr - dist, tn) >= -delta) ans = v; // optimize
	tmp.push_back({dist, delta});

	for (auto [u, w] : adj[v]) {
		if (B[u] || u == p) continue;
		dfs(u, v, delta + (w < x ? -1 : 1), x, dist + 1, tn);
	}
}

inline int solve(int x) {
	memset(B, false, sizeof B);
	segment::init();

	ans = 0;
	tmp.clear();

	for (auto [v, tn] : centroid::centroid_vec) {
		if (segment::pt + tn - 1 > n) segment::init();
		segment::update(0, 0);

		for (auto [u, w] : adj[v]) {
			if (!B[u]) {
				dfs(u, v, w < x ? -1 : 1, x, 1, tn);
				if (ans) return ans;
			
				for (pll e : tmp) segment::update(e.X, e.Y);
				tmp.clear();
			}
		}

		segment::pt += tn;
		B[v] = true;
	}

	return ans;
}

int find_ans(int v, int p, int delta, int dist, int x) {
	int ans = 0;
	if (delta >= 0 && dist >= tl && dist <= tr) ans = v;

	for (auto [u, w] : adj[v]) {
		if (u == p) continue;
		ans = max(ans, find_ans(u, v, delta + (w < x ? -1 : 1), dist + 1, x));
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> tl >> tr;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
		w_vec.push_back(w);
	}

	centroid::build_centroid_vec();
	sort(all(w_vec));

	int l = 0, r = int(w_vec.size()) - 1;
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (solve(w_vec[mid])) l = mid;
		else r = mid - 1;
	}

	int v = solve(w_vec[l]);
	cout << v << sep << find_ans(v, 0, 0, 0, w_vec[l]) << endl;
	return 0;
}