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

struct HLD {
	vector<vector<int>> graph;
	vector<int> size, pre, pos, nxt, par;
	int t = 0;

	void init(int v, int p = -1) {
		par[v] = p;
		size[v] = 1;
		for(int &u : graph[v]) if(u != par[v]) {
			init(u, v);
			size[v] += size[u];
			if(size[u] > size[graph[v][0]])
				swap(u, graph[v][0]);
		}
	}

	void set_paths(int v) {
		pre[v] = t++;
		for(int &u : graph[v]) if(u != par[v]) {
			nxt[u] = (u == graph[v][0] ? nxt[v] : u);
			set_paths(u);
		}
		pos[v] = t;
	}

	HLD(int n, vector<vector<int>> graph, int root = 0)
		: graph(graph), size(n), pre(n), pos(n), nxt(n), par(n) {
		init(root);
		set_paths(root);
	}

	int lca(int v, int u) {
		while(nxt[v] != nxt[u]) {
			if(pre[v] < pre[u])
				swap(v, u);
			v = par[nxt[v]];
		}
		return (pre[v] < pre[u] ? v : u);
	}

	vector<pair<int, int>> path_up(int v, int u) {
		vector<pair<int, int>> ret;
		while(nxt[v] != nxt[u]) {
			ret.emplace_back(pre[nxt[v]], pre[v]);
			v = par[nxt[v]];
		}
		ret.emplace_back(pre[u], pre[v]);
		return ret;
	}

	int get_vertex(int v) { return pre[v]; }

	vector<pair<int, int>> get_path(int v, int u, bool add_lca = true) {
		int w = lca(v, u);
		auto ret = path_up(v, w);
		auto path_u = path_up(u, w);
		if(add_lca) ret.emplace_back(pre[w], pre[w]);
		while(!path_u.empty()) {
			ret.emplace_back(path_u.back());
			path_u.pop_back();
		}
		return ret;
	}

	pair<int, int> get_subtree(int v) { return {pre[v], pos[v] - 1}; }
};

struct MaxTree {
	using T = PII;
	T f(T a, T b) { return max(a, b); }
	vector<T> nodes;
	int size = 1;

	MaxTree(int n, T val) {
		while(size < n) size *= 2;
		nodes.resize(size * 2, val);
	}

	void update(int pos, T val) {
		nodes[pos += size] = val;
		while(pos /= 2)
			nodes[pos] = f(nodes[pos * 2], nodes[pos * 2 + 1]);
	}

	T query(int l, int r) {
		l += size, r += size;
		T ret = (l != r ? f(nodes[l], nodes[r]) : nodes[l]);
		while(l + 1 < r) {
			if(l % 2 == 0)
				ret = f(ret, nodes[l + 1]);
			if(r % 2 == 1)
				ret = f(ret, nodes[r - 1]);
			l /= 2, r /= 2;
		}
		return ret;
	}
};

struct SumTree {
	using T = LL;
	T f(T a, T b) { return a + b; }
	vector<T> nodes;
	int size = 1;

	SumTree(int n, T val = 0) {
		while(size < n) size *= 2;
		nodes.resize(size * 2, val);
	}

	T query(int pos) {
		T ret = nodes[pos += size];
		while(pos /= 2)
			ret = f(ret, nodes[pos]);
		return ret;
	}

	T query(int l, int r) {
		l += size, r += size;
		T ret = (l != r ? f(nodes[l], nodes[r]) : nodes[l]);
		while(l + 1 < r) {
			if(l % 2 == 0)
				ret = f(ret, nodes[l + 1]);
			if(r % 2 == 1)
				ret = f(ret, nodes[r - 1]);
			l /= 2, r /= 2;
		}
		return ret;
	}

	void update(int l, int r, T val) {
		l += size, r += size;
		nodes[l] += val;
		if(l != r) nodes[r] += val;
		while(l + 1 < r) {
			if(l % 2 == 0)
				nodes[l + 1] = f(nodes[l + 1], val);
			if(r % 2 == 1)
				nodes[r - 1] = f(nodes[r - 1], val);
			l /= 2, r /= 2;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> par(n, -1), dep(n);
	vector<vector<int>> adj(n);
	FOR(i, 1, n - 1) {
		cin >> par[i];
		dep[i] = dep[--par[i]] + 1;
		adj[par[i]].emplace_back(i);
	}

	HLD hld(n, adj);

	vector<int> t(n), w(n);
	vector<vector<int>> upd(k);
	REP(i, m) {
		int v, d, q;
		cin >> v >> d >> q;
		d--, v--;
		upd[d].emplace_back(v);
		t[v] = d, w[v] = q;
	}

	MaxTree locked(n, {-1, -1});
	SumTree sums(n);

	vector<LL> at(n, -1e18);
	REP(i, k) {
		sort(upd[i].begin(), upd[i].end(), [&](int a, int b) { return dep[a] > dep[b]; });
		for(int v : upd[i]) {
			at[v] = sums.query(hld.get_vertex(v));
			int u = v;
			LL delta = w[v];
			while(u && delta) {
				auto p = hld.path_up(u, 0);

				int q = -1;
				for(PII &g : p) {
					q = locked.query(g.ST, g.ND).ND;
					if(q != -1) break;
				}

				if(q == -1) {
					for(PII &g : p)
						sums.update(g.ST, g.ND, delta);
					sums.update(hld.get_vertex(u), hld.get_vertex(u), -delta);

					break;
				}
				else {
					p = hld.path_up(u, q);
					for(PII &g : p)
						sums.update(g.ST, g.ND, delta);
					sums.update(hld.get_vertex(u), hld.get_vertex(u), -delta);

					LL s = sums.query(hld.get_vertex(q));
					if(s >= at[q] + w[q]) {
						locked.update(hld.get_vertex(q), {-1, -1});
						delta = s - (at[q] + w[q]);
						u = q;
					}
					else break;
				}
			}
		
			locked.update(hld.get_vertex(v), {dep[v], v});
		}
	}
	cout << max(sums.query(0), at[0] + w[0]) << "\n";
}