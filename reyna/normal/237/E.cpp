//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

#define prev _prev

const int N = 305, M = N * N;
int cnt, ec;
int read() { int x; cin >> x; return x; }

int from[M], to[M], cap[M], cost[M], head[N], prev[M], ind[26];

void add_edge(int u, int v, int cp, int cst) {
	from[ec] = u, to[ec] = v, cap[ec] = cp, cost[ec] = cst, prev[ec] = head[u], head[u] = ec++;
}

void add_edge(int u, int v, int uv, int vu, int cuv, int cvu) {
	add_edge(u, v, uv, cuv);
	add_edge(v, u, vu, cvu);
}

int d[N], q[N * N * N], mark[N], par[N];
int spfa(int source, int sink) {
	memset(d, 63, sizeof d);
	memset(par, -1, sizeof par);
	int h = 0, t = 0;
	d[source] = 0;
	q[t++] = source;
	while (h != t) {
		int v = q[h++];
		mark[v] = 0;
		for (int e = head[v]; ~e; e = prev[e]) if (cap[e]) {
			int u = to[e], w = cost[e];
			if (d[v] + w < d[u]) {
				d[u] = d[v] + w;
				par[u] = e;
				if (!mark[u]++)
					q[t++] = u;
			}
		}
	}
	if (d[sink] > 1e9)
		return 0;
	int v = sink;
	while (v != source) {
		int e = par[v], u = from[e];
		cap[e]--;
		cap[e ^ 1]++;
		v = u;
	}
	return d[sink];
}

int mcmf(int source, int sink) {
	int res = 0;
	while (true) {
		int add_cost = spfa(source, sink);
		if (add_cost <= 0)
			break;
		res += add_cost;
	}
	return res;
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(head, -1, sizeof head);
	string t; cin >> t;
	int op = (int) t.size(), n, source = cnt++, sink = cnt++;
	cin >> n;
	rep(j, 26)
		ind[j] = cnt++;
	rep(i, n) {
		string foo;
		cin >> foo;
		int max_use;
		cin >> max_use;
		int par = cnt++;
		add_edge(source, par, max_use, 0, 0, 0);
		rep(j, (int) foo.size()) {
			int bar = foo[j] - 'a';
			add_edge(par, ind[bar], 1, 0, i + 1, -i - 1);
		}
	}
	rep(i, op) {
		int foo = t[i] - 'a';
		add_edge(ind[foo], sink, 1, 0, 0, 0);
	}
	int res = mcmf(source, sink);
	rep(e, ec) if (to[e] == sink && cap[e] != 0) {
		cout << -1;
		return 0;
	}
	cout << res;
}