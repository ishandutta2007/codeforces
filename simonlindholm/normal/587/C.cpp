#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }


typedef vector<pii> vpi;
const pii inf(1 << 29, -1);
typedef vector<vpi> graph;

const int INF = 1 << 29;

struct Coll {
	array<int, 10> people;
	Coll() : people() { rep(i,0,10) people[i] = INF; }
	Coll(const array<int, 10>& p) : people(p) {}
};
Coll merge(const Coll& a, const Coll& b) {
	array<int, 10> ar;
	int i = 0, j = 0;
	rep(k,0,10) {
		if (a.people[i] < b.people[j]) ar[k] = a.people[i++];
		else if (a.people[i] > b.people[j]) ar[k] = b.people[j++];
		else ar[k] = b.people[j++], i++;
	}
	return ar;
}

template<class T>
struct RMQ {
	vector<vector<T>> jmp;

	RMQ(const vector<T>& V) {
		int N = sz(V), on = 1, depth = 1;
		while (on < sz(V)) on *= 2, depth++;
		jmp.assign(depth, vector<T>(N));
		jmp[0] = V;
		rep(i,0,depth-1) rep(j,0,N)
			jmp[i+1][j] = min(jmp[i][j],
			jmp[i][min(N - 1, j + (1 << i))]);
	}

	T query(int a, int b) {
		if (b <= a) return inf;
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	vector<Coll> colls;
	vector<vector<pair<int, Coll> > > jumps;
	vi time, par;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(const vector<Coll>& colls, graph& C) : colls(colls), jumps(sz(C)), time(sz(C), -99), par(sz(C)), dist(sz(C)), rmq(dfs(C)) {}

	vpi dfs(graph& C) {
		vector<tuple<int, int, int, ll> > q(1);
		vpi ret;
		int T = 0, v, p, d; ll di;
		while (!q.empty()) {
			tie(v, p, d, di) = q.back();
			q.pop_back();
			if (d) ret.emplace_back(d, p);
			time[v] = T++;
			dist[v] = di;
			par[v] = p;
			if (d) {
				assert(p != v);
				jumps[v] = {{p, colls[v]}};
				while (jumps[jumps[v].back().first].size() >= jumps[v].size()) {
					int la = sz(jumps[v]) - 1;
					auto pa = jumps[jumps[v][la].first][la];
					jumps[v].push_back({pa.first, merge(pa.second, jumps[v][la].second)});
				}
			}
			trav(e, C[v]) if (e.first != p)
				q.emplace_back(e.first, v, d+1, di + e.second);
		}
		return ret;
	}

	int query(int a, int b) {
		if (a == b) return a;
		a = time[a], b = time[b];
		return rmq.query(min(a, b), max(a, b)).second;
	}

	ll distance(int a, int b) {
		int lca = query(a, b);
		return dist[a] + dist[b] - 2 * dist[lca];
	}
};


int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<vpi> gr(N);
	rep(i,0,N-1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back({v, 1});
		gr[v].push_back({u, 1});
	}
	vector<Coll> colls(N);
	rep(i,0,M) {
		int c;
		cin >> c;
		--c;
		Coll C;
		C.people[0] = i;
		colls[c] = merge(colls[c], C);
	}
	LCA lca(colls, gr);

	auto fcol = [&](int node, int dist) {
		Coll r{};
		assert(dist >= 0);
		for (int i = 0; dist; ++i) {
			if (dist & (1 << i)) {
				dist &= ~(1 << i);
				auto pa = lca.jumps[node][i];
				node = pa.first;
				r = merge(r, pa.second);
			}
		}
		return r;
	};

	rep(i,0,Q) {
		int u, v, a;
		cin >> u >> v >> a;
		--u, --v;
		int l = lca.query(u, v);
		Coll A = fcol(u, (int)(lca.dist[u] - lca.dist[l]));
		Coll B = fcol(v, (int)(lca.dist[v] - lca.dist[l]));
		Coll C = merge(merge(A, B), lca.colls[l]);
		vi V;
		rep(i,0,a) {
			if (C.people[i] != INF)
				V.push_back(C.people[i]);
		}
		cout << sz(V);
		trav(x, V) cout << ' ' << x+1;
		cout << '\n';
	}
}