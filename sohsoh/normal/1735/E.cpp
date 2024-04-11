#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

struct FlowEdge {
	int v, u;
	int cap, flow = 0;
	FlowEdge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

struct Flow {
	const int flow_inf = 1e9;
	vector<FlowEdge> edges;
	vector<vector<int>> adj;
	int n, m = 0;
	int s, t;
	vector<int> level, ptr;
	queue<int> q;

	Flow(int n, int s, int t) : n(n), s(s), t(t) {
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int v, int u, int cap) {
		edges.emplace_back(v, u, cap);
		edges.emplace_back(u, v, 0);
		adj[v].push_back(m);
		adj[u].push_back(m + 1);
		m += 2;
	}

	bool bfs() {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int id : adj[v]) {
				if (edges[id].cap - edges[id].flow < 1)
					continue;
				if (level[edges[id].u] != -1)
					continue;
				level[edges[id].u] = level[v] + 1;
				q.push(edges[id].u);
			}
		}
		return level[t] != -1;
	}

	int dfs(int v, int pushed) {
		if (pushed == 0)
			return 0;
		if (v == t)
			return pushed;
		for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
			int id = adj[v][cid];
			int u = edges[id].u;
			if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
				continue;
			int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
			if (tr == 0)
				continue;
			edges[id].flow += tr;
			edges[id ^ 1].flow -= tr;
			return tr;
		}
		return 0;
	}

	int flow() {
		int f = 0;
		while (true) {
			fill(level.begin(), level.end(), -1);
			level[s] = 0;
			q.push(s);
			if (!bfs())
				break;
			fill(ptr.begin(), ptr.end(), 0);
			while (int pushed = dfs(s, flow_inf)) {
				f += pushed;
			}
		}
		return f;
	}
};

const ll MAXN = 1e6 + 10;

int n;
vector<pll> a_vec, b_vec;
vector<int> ta, tb;

inline vector<pll> f(vector<int> vec) {
	sort(all(vec));
	vector<pll> ans;
	for (int e : vec) {
		if (ans.empty() || ans.back().X != e) ans.push_back({e, 1});
		else ans.back().Y++;
	}

	return ans;
}

inline int ind(int x) {
	auto it = lower_bound(all(b_vec), pll(x, -1));
	if (it != b_vec.end() && it -> X == x) return it - b_vec.begin();
	return -1;
}

inline int solve(int d, bool flag = false) {
	int s = 0, t = 2 * n + 2;
	Flow flow(2 * n + 5, s, t);

	for (int i = 0; i < int(a_vec.size()); i++)
		flow.add_edge(s, i + 1, a_vec[i].Y);

	int ts = a_vec.size();
	for (int i = 0; i < int(b_vec.size()); i++)
		flow.add_edge(ts + i + 1, t, b_vec[i].Y);

	vector<pll> vec;
	for (int i = 0; i < int(a_vec.size()); i++) {
		int x = a_vec[i].X, c = a_vec[i].Y, s = 0;

		int j = ind(d - x);
		if (j >= 0) {
			flow.add_edge(i + 1, ts + j + 1, n);
			vec.push_back({flow.m - 1, x});
			s += b_vec[j].Y;
		}

		j = ind(x + d);
		if (j >= 0) {
			flow.add_edge(i + 1, ts + j + 1, n);
			vec.push_back({flow.m - 1, -x});
			s += b_vec[j].Y;
		}
		
		j = ind(x - d);
		if (j >= 0) {
			flow.add_edge(i + 1, ts + j + 1, n);
			vec.push_back({flow.m - 1, x});	
			s += b_vec[j].Y;
		}

		if (s < c) return 0;
	}


	int f = flow.flow();
	if (f < n) return 0;

	cout << "YES" << endl;
	vector<int> ans;
	for (auto [ind, pos] : vec) {
		ind--;
		for (int i = 0; i < flow.edges[ind].flow; i++) {
			ans.push_back(pos);
		}
	}

	sort(all(ans));
	int wtf = max(-ans[0], 0);
	
	for (int e : ans)
		cout << e + wtf << sep;

	cout << endl;
	if (flag) cout << wtf + d << sep << wtf << endl;
	else cout << wtf << sep << wtf + d << endl;
	return 1;
}

// swap p1, p2

inline int solve() {
	a_vec.clear();
	b_vec.clear();
	ta.clear();
	tb.clear();

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		ta.push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		tb.push_back(x);
	}

	a_vec = f(ta);
	b_vec = f(tb);

	vector<int> vec;
	for (auto [x, c] : b_vec) {
		vec.push_back(x - a_vec[0].X);
		vec.push_back(x + a_vec[0].X);
	}

	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	for (int e : vec)
		if (solve(e))
			return 0;

	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}