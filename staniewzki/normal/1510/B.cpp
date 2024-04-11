#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, l, r) for(int i = (l); i <= (r); ++i)
#define REP(i, n) FOR(i, 0, (n) - 1)
#define ssize(x) int(x.size())
template<class A, class B> auto& operator<<(ostream &o, pair<A, B> p) {
	return o << '(' << p.first << ", " << p.second << ')';
}
template<class T> auto operator<<(ostream &o, T x) -> decltype(x.end(), o) {
	o << '{'; int i = 0; for(auto e : x) o << (", ")+2*!i++ << e; return o << '}';
}
#ifdef DEBUG
#define debug(x...) cerr << "[" #x "]: ", [](auto... $) {((cerr << $ << "; "), ...); }(x), cerr << '\n'
#else
#define debug(...) {}
#endif

struct MCMF {
	struct Edge {
		int v, u, flow, cap;
		LL cost;
		friend ostream& operator<<(ostream &os, Edge &e) {
			return os << vector<LL>{e.v, e.u, e.flow, e.cap, e.cost};
		}
	};

	int n;
	const LL inf_LL = 1e18;
	const int inf_int = 1e9;
	vector<vector<int>> graph;
	vector<Edge> edges;

	MCMF(int N) : n(N), graph(n) {}

	void add_edge(int v, int u, int cap, LL cost) {
		debug(v, u, cap, cost);
		int e = ssize(edges);
		graph[v].emplace_back(e);
		graph[u].emplace_back(e + 1);
		edges.emplace_back(Edge{v, u, 0, cap, cost});
		edges.emplace_back(Edge{u, v, 0, 0, -cost});
	}

	pair<int, LL> augment(int source, int sink) {
		debug(source, sink);

		vector<LL> dist(n, inf_LL);
		vector<int> from(n, -1);
		dist[source] = 0;
		deque<int> que = {source};
		vector<bool> inside(n);
		inside[source] = true;

		while(ssize(que)) {
			int v = que.front();
			inside[v] = false;
			que.pop_front();

			for(int i : graph[v]) {
				Edge &e = edges[i];
				if(e.flow != e.cap and dist[e.u] > dist[v] + e.cost) {
					dist[e.u] = dist[v] + e.cost;
					from[e.u] = i;
					if(not inside[e.u]) {
						inside[e.u] = true;
						que.emplace_back(e.u);
					}
				}
			}
		}
		if(from[sink] == -1)
			return {0, 0};

		int flow = inf_int, e = from[sink];
		while(e != -1) {
			flow = min(flow, edges[e].cap - edges[e].flow);
			e = from[edges[e].v];
		}
		e = from[sink];
		while(e != -1) {
			edges[e].flow += flow;
			edges[e ^ 1].flow -= flow;
			e = from[edges[e].v];
		}
		return {flow, flow * dist[sink]};
	}

	pair<int, LL> operator()(int source, int sink) {
		int flow = 0;
		LL cost = 0;
		pair<int, LL> got;
		do {
			got = augment(source, sink);
			flow += got.first;
			cost += got.second;
		} while(got.first);
		return {flow, cost};
	}

	using T = int;
	map<pair<int, int>, T> get_flowing() {
		map<pair<int, int>, T> ret;
		REP(v, n)
			for(int i : graph[v]) {
				if(i % 2)
					continue;
				Edge &e = edges[i];
				ret[make_pair(v, e.u)] = e.flow;
			}
		return ret;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int d, n;
	cin >> d >> n;

	vector<int> val(n);
	REP(i, n) {
		int x = 0;
		REP(j, d) {
			char c;
			cin >> c;
			x += (c == '1') << j;
		}
		val[i] = x;
	}

	sort(val.begin(), val.end(),
		[&](int a, int b) {
			return __builtin_popcount(a) >
				   __builtin_popcount(b);
		}
	);

	MCMF flow(2 * n + 2);
	int source = 2 * n;
	int sink = 2 * n + 1;
	REP(i, n) {
		flow.add_edge(source, 2 * i, 1, -(__builtin_popcount(val[i]) + 1));
		flow.add_edge(2 * i + 1, sink, 1, 0);
	}

	REP(i, n) REP(j, i) {
		if((val[i] | val[j]) == val[j]) {
			flow.add_edge(2 * i, 2 * j + 1, 1, 0);
			debug(i, j);
		}
	}

	flow(source, sink);

	auto flowing = flow.get_flowing();
	debug(flowing);

	vector<int> vis(n);
	vector<char> output;
	for(int i = n - 1; i >= 0; i--) {
		if(vis[i]) continue;

		if(ssize(output))
			output.emplace_back('R');

		int ptr = i, cur = 0;
		while(true) {
			vis[ptr] = true;

			REP(j, d) {
				if(val[ptr] & (1 << j) && !(cur & (1 << j))) {
					cur ^= (1 << j);
					output.emplace_back('0' + j);
				}
			}

			bool found = false;
			for(int j = ptr - 1; j >= 0; j--) {
				if(flowing[make_pair(2 * ptr, 2 * j + 1)]) {
					ptr = j;
					found = true;
					break;
				}
			}

			if(!found) break;
		}
	}

	cout << ssize(output) << "\n";
	for(char c : output)
		cout << c << " ";
	cout << "\n";
}