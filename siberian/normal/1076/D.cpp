#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll	

struct edge{
	int to, cost, ind;
	edge () {}
	edge (int _to, int _cost, int _ind) {
		to = _to, cost = _cost, ind = _ind;
	}
};

const int MAXN = 3e5 + 10;
int n, m, k;
vector<edge> g[MAXN];
vector<pair<pair<int, int>, int>> ed;

void read() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		ed.push_back({{u, v}, cost});
		g[u].push_back({v, cost, i + 1});
		g[v].push_back({u, cost, i + 1});
	}
}

set<int> del;
int d[MAXN];
const int INF = 1e18;

void build() {
	set<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		d[i] = INF;
	d[0] = 0;
	q.insert({0, 0});
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());
		for (auto [to, cost, ind] : g[v]) {
			if (d[to] <= d[v] + cost) continue;
			q.erase({d[to], to});
			d[to] = d[v] + cost;
			q.insert({d[to], to});
		}
	}
}

void out_ans() {
	if (m - del.size() > k) return;
	while(m - del.size() < k) del.erase(del.begin());
	set<int> ans;
	for (int i = 1; i <= m; i++)
		ans.insert(i);
	for (auto i : del) ans.erase(i);
	cout << ans.size() << endl;
	for (auto i : ans) 
		cout << i << " ";
	cout << endl;
	exit(0);
}

int used[MAXN];

void dfs(int v) {
	for (auto [to, cost, ind] : g[v]) {
		if (d[to] - cost != d[v]) continue;
		if (used[to]) {
			del.insert(ind);
			out_ans();
			continue;
		}
		used[to] = ind;
		dfs(to);
	}
}

void solve() {
	read();	
	build();
	
	/*cout << "d = " << endl;
	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
	cout << endl;*/
	for (int i = 0; i < m; i++) {
		int v = ed[i].first.first;
		int u = ed[i].first.second;
		int cost = ed[i].second;
		if (d[u] > d[v]) swap(u, v);
		//cout << "val = ";
		//cout << u << " " << v << " " << cost << endl;
		if (d[u] + cost == d[v]) {
			continue;	
		}
		//cout << "i = " << i << endl;
		del.insert(i + 1);
		out_ans();
	}
	dfs(0);
	vector<int> have;
	for (int i = 0; i < n; i++) {
		if (used[i]) have.push_back(used[i] - 1);
	}
	sort(all(have), [&] (int a, int b) {return max(d[ed[a].first.first], d[ed[a].first.second]) < max(d[ed[b].first.first], d[ed[b].first.second]);});
	while (!have.empty()) {
		del.insert(have.back() + 1);
		have.pop_back();
		out_ans();
	}
	assert(false);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}