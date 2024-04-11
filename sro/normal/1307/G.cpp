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
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Edge {
	int to, cap, rev, cost;
};

struct MinCostFlow {
	vector<Edge> egs[55];
	void inline addedge(int u, int v, int cap, int cost) {
		egs[u].pub({v, cap, SZ(egs[v]), cost});
		egs[v].pub({u, 0, SZ(egs[u]) - 1, -cost});
	}
	int dis[55], prv[55], pre[55];
	bool inq[55];
	bool spfa(int S, int T) {
		memset(dis, Inf, sizeof(dis));
		dis[S] = 0; queue<int> q;
		q.push(S); inq[S] = 1;
		while (SZ(q)) {
			int now = q.front(); q.pop();
			inq[now] = 0;
			loop(i, SZ(egs[now])) {
				Edge &e = egs[now][i];
				if (e.cap && dis[e.to] > dis[now] + e.cost) {
					dis[e.to] = dis[now] + e.cost;
					prv[e.to] = now;
					pre[e.to] = i;
					if (!inq[e.to]) {
						inq[e.to] = 1;
						q.push(e.to);
					}
				}
			}
		}
		return dis[T] != Inf;
	}
	int get(int S, int T) {
		if (!spfa(S, T)) return -1;
		int res = dis[T];
		for(int i = T; i != S; i = prv[i]) {
			Edge &e = egs[prv[i]][pre[i]];
			--e.cap;
			++egs[e.to][e.rev].cap;
		}
		return res;
	}
} nf;

int N, M;
ll pre[2555];
int prs;

int main() {
	scanf("%d%d", &N, &M);
	cont(i, M) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		nf.addedge(u, v, 1, w);
	}
	while (1) {
		int si = nf.get(1, N);
		if (!~si) break;
		pre[++prs] = si;
		pre[prs] += pre[prs - 1];
	}
	int Q; scanf("%d", &Q);
	while (Q--) {
		int x; scanf("%d", &x);
		double ans = Inf;
		cont(i, prs) ans = min(ans, 1. * (pre[i] + x) / i);
		printf("%.10lf\n", ans);
	}
	return 0;
}