#include<bits/stdc++.h>
using namespace std;
 
ostream& operator<<(ostream &out, string str) {
	for(char c : str) out << c;
	return out;
}
 
template<class L, class R> ostream& operator<<(ostream &out, pair<L, R> p) {
	return out << "(" << p.first << ", " << p.second << ")";
}
 
template<class T> auto operator<<(ostream &out, T a) -> decltype(a.begin(), out) {
	out << "{";
	for(auto it = a.begin(); it != a.end(); it = next(it))
		out << (it != a.begin() ? ", " : "") << *it;
	return out << "}";
}
 
void dump() { cerr << "\n"; }
template<class T, class... Ts> void dump(T a, Ts... x) {
	cerr << a << ", ";
	dump(x...);
}
 
#ifdef DEBUG
#  define debug(...) cerr << "[" #__VA_ARGS__ "]: ", dump(__VA_ARGS__)
#else
#  define debug(...) false
#endif
 
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ST first
#define ND second
 
template<class T> int size(T && a) { return a.size(); }
 
using LL = long long;
using PII = pair<int, int>;

struct JumpPtr {
	int LOG = 20;
	vector<vector<int>> graph, jump;
	vector<int> par, dep;
	void par_dfs(int v) {
		for(int u : graph[v]) {
			if(u != par[v]) {
				par[u] = v;
				dep[u] = dep[v] + 1;
				par_dfs(u);
			}
		}
	}
	JumpPtr(vector<vector<int>> &graph, int root = 0) : graph(graph) {
		int n = size(graph);
		par.resize(n, -1);
		dep.resize(n);
		par_dfs(root);
		jump.resize(LOG, vector<int>(n));
		jump[0] = par;
		FOR(i, 1, LOG - 1) REP(j, n)
			jump[i][j] = jump[i - 1][j] == -1 ? -1 : jump[i - 1][jump[i - 1][j]];
	}
	int jump_up(int v, int k) {
		for(int i = LOG - 1; i >= 0; i--)
			if(k & (1 << i))
				v = jump[i][v];
		return v;
	}
	int get_par(int v) { return par[v]; }
	int lca(int a, int b) {
		if(dep[a] < dep[b]) swap(a, b);
		int delta = dep[a] - dep[b];
		a = jump_up(a, delta);
		if(a == b) return a;
		
		for(int i = LOG - 1; i >= 0; i--) {
			if(jump[i][a] != jump[i][b]) {
				a = jump[i][a];
				b = jump[i][b];
			}
		}
		return par[a];		
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	map<int, map<int, int>> edges;
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		adj[a - 1].emplace_back(b - 1);
		adj[b - 1].emplace_back(a - 1);
		a--, b--;
		edges[a][b] = i;
		edges[b][a] = i;
	}

	JumpPtr ptr(adj);
	vector<int> val(n, 1);
	int q;
	cin >> q;
	vector<int> a(q), b(q), g(q);
	REP(i, q) {
		cin >> a[i] >> b[i] >> g[i];
		a[i]--, b[i]--;
		int lca = ptr.lca(a[i], b[i]);
		auto update = [&](int x) {
			while(x != lca) {
				val[x] = max(val[x], g[i]);
				x = ptr.get_par(x);
			}
		};
		update(a[i]), update(b[i]);
	}

	REP(i, n) debug(i, val[i]);

	REP(i, q) {
		int lca = ptr.lca(a[i], b[i]);
		int mn = 1e6;
		auto search = [&](int x) {
			while(x != lca) {
				mn = min(mn, val[x]);
				x = ptr.get_par(x);
			}
		};
		search(a[i]), search(b[i]);
		if(mn != g[i]) {
			cout << "-1\n";
			return 0;
		}
	}

	vector<int> ans(n);
	REP(i, n) {
		int p = ptr.get_par(i);
		if(p == -1) continue;
		ans[edges[i][p]] = val[i];
	}

	REP(i, n - 1) cout << ans[i] << " ";
	cout << "\n";
}