/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); i++)
#define cont(i, n)          for(int i = 1; i <= (n); i++)
#define circ(i, a, b)       for(int i = (a); i <= (b); i++)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

struct Netflow {
	struct Edge {
		int to, rev;
		int cap;
		Edge(int to, int rev, int cap) : to(to), rev(rev), cap(cap) {}
	};
	vector<Edge> egs[1 << 15];
	void inline addedge(int u, int v, int cap) {
		egs[u].pub(Edge(v, SZ(egs[v]), cap));
		egs[v].pub(Edge(u, SZ(egs[u]) - 1, 0));
	}
	int dist[1 << 15], iter[1 << 15];
	void inline init() {
		loop(i, 1 << 15) egs[i].clear();
	}
	bool inline bfs(int s, int t) {
		memset(dist, -1, sizeof(dist));
		queue<int> q;
		dist[s] = 0; q.push(s);
		while(SZ(q)) {
			int x = q.front(); q.pop();
			loop(i, SZ(egs[x])) {
				Edge &e = egs[x][i];
				if(e.cap && !~dist[e.to]) {
					dist[e.to] = dist[x] + 1;
					q.push(e.to);
				}
			}
		}
		return ~dist[t];
	}
	int inline dfs(int now, int t, int cap) {
		if(now == t) return cap;
		for(int &i = iter[now]; i < SZ(egs[now]); i++) {
			Edge &e = egs[now][i];
			if(e.cap && dist[e.to] > dist[now]) {
				int f = dfs(e.to, t, min(cap, e.cap));
				if(f) {
					e.cap -= f;
					egs[e.to][e.rev].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	int flow(int s, int t) {
		int ans = 0;
		while(bfs(s, t)) {
			memset(iter, 0, sizeof(iter));
			int tmp;
			while((tmp = dfs(s, t, Inf))) {
				ans += tmp;
			}
		}
		return ans;
	}
} nf;

int n, m;

struct Edge {
	int u, v, w;
	void inline Read() {
		scanf("%d%d%d", &u, &v, &w);
	}
} e[1 << 17];

bool check(int mid) {
	nf.init();
	cont(i, mid) nf.addedge(e[i].u, e[i].v + n, 1);
	cont(i, n) nf.addedge(0, i, 1), nf.addedge(i + n, n << 1 | 1, 1);
	return nf.flow(0, n << 1 | 1) == n;
}

int main() {
	scanf("%d%d", &n, &m);
	cont(i, m) e[i].Read();
	sort(e + 1, e + m + 1, [&](Edge a, Edge b) {
		return a.w < b.w;
	});
	int l = 0, r = m + 1;
	while(r - l > 1) {
		int m = (l + r) >> 1;
		if(check(m)) r = m;
		else l = m;
	}
	if(r == m + 1) puts("-1");
	else printf("%d\n", e[r].w);
	return 0;
}