#include <bits/stdc++.h>
using namespace std;
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define x first
#define y second
#define ll long long
#define N 805

typedef pair <int, int> pii;
typedef pair <double, int> pdi;

const int inf = 0x3f3f3f3f;
const double linf = 2e18 + 100;
const double eps = 1e-7;

struct edge{
	int t, r, c; double s;
	edge(int t = 0, int r = 0, int c = 0, double s = 0) : t(t), r(r), c(c), s(s) {}
};

vector <edge> g[N];
int cur[N], m, n;
double dist[N];
bool vis[N];

void aeg(int f, int t, int c, double s) {
	g[f].push_back( edge(t, g[t].size(), c, s) );
	g[t].push_back( edge(f, g[f].size() - 1, 0, -s) );
}

bool rlb() {
	double d = linf;
	f0(u, 0, m) if (vis[u])
		for (int i = 0; i < g[u].size(); i ++) {
			edge id = g[u][i];
			if (id.c && !vis[id.t]) d = min(d, dist[id.t] + id.s - dist[u]);
		}
	if (d == linf) return 0;
	for (int u = 0; u < m; u ++) if (vis[u]) dist[u] += d;
	return 1;
}

int inc(int u, int f) {
	if (u == 2*n+1) return f;
	vis[u] = true;
	int ret = 0;
	for (int &i = cur[u]; i < g[u].size(); i ++)
	if (g[u][i].c) { int v = g[u][i].t;
		if (vis[v] || fabs(dist[u] - dist[v] - g[u][i].s) > eps) continue;
		int tmp = inc(v, min(f, g[u][i].c));
		g[u][i].c -= tmp, g[v][g[u][i].r].c += tmp, f -= tmp, ret += tmp;
		if (!f) return ret;
	} return ret;
}

pdi func() {
	double mincost = 0; int flow = 0;
	memset(dist, 0, sizeof dist);
	do {
		memset(cur, 0, sizeof cur);
		while (true) {
			memset(vis, 0, sizeof vis);
			int tmp = inc(0, inf);
			if (!tmp) break;
			flow += tmp;
			mincost += dist[0] * tmp;
		}
	} while ( rlb() );
	return pdi(mincost, flow);
}

double dis(pii &a, pii &b) {
    return hypot(a.x - b.x, a.y - b.y);
}

pii p[N];

int main() {
    scanf("%d", &n);
	f1(i, 1, n) scanf("%d %d", &p[i].y, &p[i].x);
	m = 2 * n + 2;
    sort(p + 1, p + n + 1, greater <pii> ());
    f1(i, 1, n) aeg(0, 2*i, 2, 0);
    f1(i, 1, n) aeg(2*i-1, 2*n+1, 1, 0);
    f1(i, 1, n) f1(j,i+1, n) if (p[i].x > p[j].x) {
        aeg(2*i, 2*j-1, 1, dis(p[i], p[j]));
    }
    pdi rpt = func();
    if (rpt.y != (n-1)) puts("-1");
    else cout << fixed << setprecision(10) << rpt.x << endl;
	return 0;
}