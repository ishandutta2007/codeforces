//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define link Tavas
#define set upd_set
typedef pair<int, int> pii;
const int N = 1e5 + 9;
int n, sz[N], from[N], to[N], len[N], nx = 1, sum[N << 2], ch[N << 2];
long long ans[N];
vector<pii> adj[N];
map<int, int> link;
void shift(int v, int b, int e) {
	if (ch[v] == -1)
		return;
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	ch[l] = ch[v];
	ch[r] = ch[v];
	sum[l] = (mid - b) * 1LL * ch[v];
	sum[r] = (e - mid) * 1LL * ch[v];
	ch[v] = -1;	
}
void set(int i, int j, int x, int v = 1, int b = 0, int e = nx) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		ch[v] = x;
		sum[v] = (e - b) * 1LL * x;
		return;
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	shift(v, b, e);
	set(i, j, x, l, b, mid);
	set(i, j, x, r, mid, e);
	sum[v] = sum[l] + sum[r];
}
int query(int i, int j, int v = 1, int b = 0, int e = nx) {
	if (i >= e || b >= j)
		return 0;
	if (i <= b && e <= j)
		return sum[v];
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	shift(v, b, e);
	return query(i, j, l, b, mid) + query(i, j, r, mid, e);	
}
void dfs_sz(int v, int p = -1) {
	sz[v] = 1;
	for (auto e: adj[v])
		if (e.first != p)
			dfs_sz(e.first, v), sz[v] += sz[e.first];
}
void adjust(int w, int e) {
	int cnt = query(0, w + 1);
//	cout << e << ' ' << cnt << ' ' << w << ' ' << nx << endl;
	ans[e] = cnt;
	set(0, w, 0);
	set(w, w + 1, cnt);
}
void dfs_fill(int v, int p = -1, int w = 0, int to = 1) {
	set(w, w + 1, query(w, w + 1) + to);
	for (auto e: adj[v])
		if (e.first != p)
			dfs_fill(e.first, v, max(w, len[e.second]));
}
void dfs_ans(int v, int p = -1, int eid = -1) {
	int id = -1, edge_id = -1;
	for (auto e: adj[v]) if (e.first != p) {
		int u = e.first;
		if (id == -1 || sz[u] > sz[id])
			id = u, edge_id = e.second;
	}
	for (auto e: adj[v]) if (e.first != id && e.first != p) {
		int u = e.first, w = len[e.second], ed = e.second;
		dfs_ans(u, v, ed);
		set(0, nx, 0);
	}
	if (id != -1)
		dfs_ans(id, v, edge_id);
	for (auto e: adj[v]) if (e.first != id && e.first != p) {
		int u = e.first, w = len[e.second], ed = e.second;
		dfs_fill(u, v, w, 1);
	}
	set(0, 1, query(0, 1) + 1);
	if (~eid)
		adjust(len[eid], eid);
}
int par[N], q[N], bg, ed;
int find(int v) {
	return (v == par[v]? v: par[v] = find(par[v]));	
}
void unite(int u, int v) {
	u = find(u), v = find(v);
	par[u] = v;
	sz[v] += sz[u];
}
bool cmp(int x, int y) {
	return len[x] < len[y];	
}
int edge[N];
vector<int> wei;
int main() {
	memset(ch, -1, sizeof ch);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w; cin >> u >> v >> w; --u, --v;
		len[i] = w;
		wei.push_back(w);
		from[i] = u, to[i] = v;
	}
	sort(wei.begin(), wei.end());
	wei.resize(unique(wei.begin(), wei.end()) - wei.begin());
	nx = wei.size();
	for (int i = 0; i < nx; ++i)
		link[wei[i]] = i + 1;
	for (int i = 0; i < n - 1; ++i) {
		int u = from[i], v = to[i], c = link[len[i]];
		len[i] = c - 1;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		edge[i] = i;
	}
	dfs_sz(0);
	dfs_ans(0);
//	cout << ans[1] << endl;
	for (int i = 0; i < n; ++i)
		par[i] = i, sz[i] = 1;
	int last = -1;
	len[n - 1] = -1;
	edge[n - 1] = n - 1;
	sort(edge, edge + n - 1, cmp);
	for (int i = 0; i < n - 1; ++i) {
		int id = edge[i];
		q[ed++] = id;
		unite(from[id], to[id]);
		if (len[id] != len[edge[i + 1]]) {
			while (bg != ed) {
				int v = q[bg++];
		//		cout << v << ' ' << ans[v] << ' ' << sz[find(from[v])] << endl;
				ans[v] = (ans[v] * (sz[find(from[v])] - ans[v])) * 2;
			}
		}
	}
	long long most = 0;
	for (int i = 0; i < n - 1; ++i)
		most = max(most, ans[i]);
	int cnt = 0;
	for (int i = 0; i < n - 1; ++i)
		cnt += (ans[i] == most);
	cout << most << ' ' << cnt << '\n';
	for (int i = 0; i < n - 1; ++i)
		if (ans[i] == most)
			cout << i + 1 << ' ';
	return 0;
}