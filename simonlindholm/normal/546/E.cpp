#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef ll Flow;
struct Edge {
	int dest, back;
	Flow f, c;
};
typedef vector<vector<Edge> > graph;

ll inf = 1000000;

struct PushRelabel {
	graph g;
	vector<Flow> exc;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel(int n) : g(n), exc(n), cur(n), hs(2*n), H(n) {}

	void add_edge(int s, int t, Flow cap, Flow rcap=0) {
		if (s == t) return;
		Edge a = {t, sz(g[t]), 0, cap};
		Edge b = {s, sz(g[s]), 0, rcap};
		g[s].push_back(a);
		g[t].push_back(b);
	}

	void add_flow(Edge& e, Flow f) {
		Edge &back = g[e.dest][e.back];
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

int main() {
	int N, M;
	cin >> N >> M;
	int s = 2*N, t = 2*N+1;
	PushRelabel pr(2*N+2);
	ll sum1 = 0, sum2 = 0;
	rep(i,0,N) {
		int a; cin >> a;
		pr.add_edge(s, i, a);
		sum1 += a;
	}
	rep(i,0,N) {
		int a; cin >> a;
		pr.add_edge(i+N, t, a);
		sum2 += a;
	}
	rep(i,0,N) {
		pr.add_edge(i, i+N, inf);
	}
	rep(i,0,M) {
		int a, b; cin >> a >> b; --a, --b;
		pr.add_edge(a, b+N, inf);
		pr.add_edge(b, a+N, inf);
	}
	bool works = (sum1 == sum2 && pr.maxflow(s, t) == sum1);
	if (works) {
		cout << "YES" << endl;
		vector<vi> mat(N, vi(N));
		rep(i,0,N) {
			trav(e,pr.g[i]) {
				if (e.dest >= N && e.dest < 2*N) {
					int j = e.dest - N;
					mat[i][j] += (int)e.f;
				}
			}
			rep(j,0,N)
				cout << mat[i][j] << ' ';
			cout << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}