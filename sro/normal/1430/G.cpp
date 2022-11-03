#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
#define int long long
typedef long double lf;
const int INF = 0x3f3f3f3f3f3f3f3fll;

template<typename Tp>
void inline read(Tp &x) {
	char ch = 233; x = 0;
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch & 15);
		ch = getchar();
	}
}

struct Edge {
	int to, cap, rev;
	Edge(int to, int cap, int rev): to(to), cap(cap), rev(rev) {}
};

struct NetFlow {
	vector<Edge> egs[11005];
	void inline addedge(int u, int v, int cap) {
		egs[u].emb(v, cap, SZ(egs[v]));
		egs[v].emb(u, 0, SZ(egs[u]) - 1);
	}
	int dist[11005];
	bool inline bfs(int s, int t) {
		memset(dist, -1, sizeof(dist));
		dist[s] = 0;
		queue<int> q; q.push(s);
		while (SZ(q)) {
			int x = q.front(); q.pop();
			parse(e, egs[x]) {
				if (e.cap && !~dist[e.to]) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
		return ~dist[t];
	}
	int iter[11005];
	int inline dfs(int x, int t, int cap) {
		if (x == t) return cap;
		for (int &i = iter[x]; i < SZ(egs[x]); ++i) {
			Edge &e = egs[x][i];
			if (e.cap && dist[e.to] == dist[x] + 1) {
				int f = dfs(e.to, t, min(cap, e.cap));
				if (f) {
					e.cap -= f;
					egs[e.to][e.rev].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	int inline get(int s, int t) {
		int res = 0;
		while (bfs(s, t)) {
			memset(iter, 0, sizeof(iter));
			for (int tmp; (tmp = dfs(s, t, INF)); res += tmp) ;
		}
		return res;
	}
} nf;

const int S = 0, T = 11004;
int n, m;
int eg[105][105];
int deg[105];
bitset<105> kn[105];
vector<int> vi[105];
int val[105];
int ans[105];
vector<int> ts;

int inline id(int i, int j) {
	return i * 105 + j + 1;
}

signed main() {
	read(n); read(m);
	cont(i, m) {
		int u, v, w;
		read(u); read(v); read(w);
		eg[u][v] = w; ++deg[v];
		val[u] += w; val[v] -= w;
	}
	queue<int> q;
	cont(i, n) kn[i].set(i);
	cont(i, n) if (!deg[i]) q.push(i);
	while (SZ(q)) {
		int x = q.front(); q.pop();
		ts.pub(x);
		cont(to, n) if (eg[x][to]) {
			--deg[to];
			bool is = 1;
			loop(i, SZ(vi[to])) {
				if ((kn[x] | kn[vi[to][i]]) == kn[x]) {
					vi[to].erase(vi[to].begin() + i);
					--i;
				} else if ((kn[x] & kn[vi[to][i]]) == kn[x]) {
					is = 0;
				}
			}
			if (is) vi[to].pub(x);
			kn[to] |= kn[x];
			if (!deg[to]) q.push(to);
		}
	}
	cont(i, n) nf.addedge(S, id(i, 0), INF);
	cont(i, n) nf.addedge(id(i, 101), T, INF);
	cont(i, n) loop(j, 101) nf.addedge(id(i, j), id(i, j + 1), j ? val[i] * j + 1e9 : INF);
	cont(i, n) parse(j, vi[i]) loop(k, 101) nf.addedge(id(i, k), id(j, k + 1), INF);
	nf.get(S, T);
	// cerr<<nf.get(S, T)<<endl;
	cont(i, n) loop(j, 101) if (~nf.dist[id(i, j)] && !~nf.dist[id(i, j + 1)]) ans[i] = j;
	cont(i, n) printf("%lld%c", ans[i], " \n"[i == n]);
	return 0;
}
/*

3 2
2 1 4
1 3 2

5 4
1 2 1
2 3 1
1 3 6
4 5 8

5 5
1 2 1
2 3 1
3 4 1
1 5 1
5 4 10

*/