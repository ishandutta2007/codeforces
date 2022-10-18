#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

const ll inf2 = 2000000003;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
	int find(int x) {
		if (e[x] < 0) return x;
		return e[x] = find(e[x]);
	}
};

struct Node {
	int lo, epar, time = 0;
	vector<pii> ed;
};
vector<Node> nodes;
int nedges = 0;

int add_edge(int a, int b) {
	nodes[a].ed.emplace_back(b, nedges);
	nodes[b].ed.emplace_back(a, nedges);
	return nedges++;
}

void dfs(Node& n, int epar, int& time) {
	n.epar = epar; n.lo = n.time = ++time;
	trav(e, n.ed) if (e.second != epar) {
		Node& o = nodes[e.first];
		n.lo = min(n.lo, o.time ?: (dfs(o, e.second, time), o.lo));
	}
}

vector<bool> find_bridges() {
	int time = 0;
	trav(n, nodes) if (!n.time) dfs(n, -1, time);
	vector<bool> ret(nedges);
	trav(n, nodes)
		if (n.lo == n.time && n.epar != -1) ret[n.epar] = 1;
	return ret;
}

struct Edge {
	int a, b, ind;
	ll w;
};

typedef ll Flow;
struct Edge2 {
	int dest, back;
	Flow f, c;
	int id;
};
typedef vector<vector<Edge2> > graph;

struct PushRelabel {
	graph g;
	vector<Flow> exc;
	vector<Edge2*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), exc(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, int id, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge2 a = {t, sz(g[t]), 0, cap, id};
		Edge2 b = {s, sz(g[s]), 0, rcap, id};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge2& e, Flow f) {
		Edge2 &back = g[e.dest][e.back];
		if (!exc[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; exc[e.dest] += f;
		back.f -= f; back.c += f; exc[back.dest] -= f;
	}
	Flow maxflow(int s, int t) {
		int v = sz(g); H[s] = v; exc[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i,0,v) cur[i] = g[i].data();
		trav(e, g[s]) add_flow(e, e.c);

		for (int hi = 0;;) {
			while (hs[hi].empty()) if (!hi--) return -exc[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while (exc[u] > 0)  // discharge u
				if (cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					trav(e, g[u]) if (e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest]+1, cur[u] = &e;
					if (++co[H[u]], !--co[hi] && hi < v)
						rep(i,0,v) if (hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v + 1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest]+1)
					add_flow(*cur[u], min(exc[u], cur[u]->c));
				else ++cur[u];
		}
	}
};

void dfs3(graph& gr, vi& seen, int at, ll& res, vi& resv) {
	if (seen[at]++) return;
	trav(e, gr[at]) {
		if (e.c > 0) {
			// cerr << "traversing " << at << " to " << e.dest << endl;
			dfs3(gr, seen, e.dest, res, resv);
		}
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	int S, T;
	cin >> S >> T;
	--S, --T;

	UF uf(N);
	vector<Edge> ed;
	ed.reserve(M);
	nodes.resize(N);
	rep(i,0,M) {
		int a, b;
		ll w;
		cin >> a >> b >> w;
		--a, --b;
		if (a == b) continue;
		uf.join(a, b);
		add_edge(a, b);
		ed.push_back({a, b, i+1, w});
	}

	if (uf.find(S) != uf.find(T)) {
		cout << 0 << endl;
		cout << 0 << endl;
		cout << endl;
		exit(0);
	}

	vector<bool> isbr = find_bridges();
	rep(i,0,sz(isbr)) if (isbr[i]) {
		Edge e = ed[i];
		ed.push_back({e.a, e.b, -1, 0});
	}

	PushRelabel pr(N);
	trav(e, ed) {
		pr.add_edge(e.a, e.b, e.ind, e.w + inf2, e.w + inf2);
	}

	ll flow = pr.maxflow(S, T);
	if (flow >= 3 * inf2) {
		cout << -1 << endl;
	}
	else {
		assert(flow >= 2 * inf2);

		ll res = 0;
		vi resv;
		vi seen(N);
		dfs3(pr.g, seen, S, res, resv);

		rep(i,0,N) {
			if (!seen[i]) continue;
			trav(e, pr.g[i]) {
				if (seen[e.dest]) continue;
				res += e.f;
				if (e.id != -1)
					resv.push_back(e.id);
			}
		}

		assert(res == flow);
		assert(sz(resv) <= 2);
		flow -= 2 * inf2;

		cout << flow << endl;
		cout << sz(resv) << endl;
		sort(all(resv));

		trav(x, resv) {
			cout << x << ' ';
		}
		cout << endl;
	}

	exit(0);
}