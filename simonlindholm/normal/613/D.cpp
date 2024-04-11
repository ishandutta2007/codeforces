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
	vi time, par;
	vector<ll> dist;
	RMQ<pii> rmq;

	LCA(graph& C) : time(sz(C), -99), par(sz(C)), dist(sz(C)), rmq(dfs(C)) {}

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

vpi compressTree(LCA& lca, const vi& subset) {
	static vi rev; rev.resize(sz(lca.dist));
	vi li = subset, &T = lca.time;
	auto cmp = [&](int a, int b) { return T[a] < T[b]; };
	sort(all(li), cmp);
	int m = sz(li)-1;
	rep(i,0,m) {
		int a = li[i], b = li[i+1];
		int c = lca.query(a, b);
		li.push_back(c);
	}
	sort(all(li), cmp);
	li.erase(unique(all(li)), li.end());
	rep(i,0,sz(li)) rev[li[i]] = i;
	vpi ret = {pii(0, li[0])};
	rep(i,0,sz(li)-1) {
		int a = li[i], b = li[i+1];
		ret.emplace_back(rev[lca.query(a, b)], b);
	}
	return ret;
}

struct Node {
	vi ch;
	bool col;
};

bool solve(vector<Node>& nodes, int at, int& u) {
	Node& n = nodes[at];
	int cnt = 0;
	rep(i,0,sz(n.ch)) {
		cnt += solve(nodes, n.ch[i], u);
	}
	if (n.col) {
		u += cnt;
		return true;
	}
	else {
		if (cnt <= 1) return cnt;
		u++;
		return false;
	}
}

int solve(vector<Node>& nodes) {
	int u = 0;
	solve(nodes, 0, u);
	return u;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<vpi> gr(N);
	rep(i,0,N-1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		gr[a].emplace_back(b, 1);
		gr[b].emplace_back(a, 1);
	}
	LCA lca(gr);
	LCA lca2(gr);

	int Q;
	cin >> Q;
	vi col(N);
	vi li;
	rep(i,0,Q) {
		int m;
		cin >> m;
		li.clear();
		li.reserve(2*m);
		rep(i,0,m) {
			int a;
			cin >> a; --a;
			li.push_back(a);
			col[a] = 1;
		}
		rep(i,0,m) {
			int p = lca.par[li[i]];
			if (p != li[i] && col[p]) {
				cout << -1 << '\n';
				goto fail;
			}
		}
		{
			vpi tr = compressTree(lca, li);
			vector<Node> nodes(sz(tr));
			rep(i,0,sz(tr)) {
				pii pa = tr[i];
				if (pa.first != i)
					nodes[pa.first].ch.push_back(i);
				nodes[i].col = col[pa.second];
			}
			cout << solve(nodes) << '\n';
		}
fail:
		trav(x, li) col[x] = 0;
	}
}