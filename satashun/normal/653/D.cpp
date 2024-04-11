#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#define MAX_V 60
const int INF = 2000000;

struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {};
};

vector<edge> G[MAX_V];
int level[MAX_V]; 
int iter[MAX_V]; 

void add_edge(int from, int to, int cap)
{
    G[from].push_back(edge(to, cap, (int)G[to].size()));
    G[to].push_back(edge(from, 0, (int)G[from].size() - 1));
}

void bfs(int s)
{
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);

    while (!que.empty()) {
	int v = que.front(); que.pop();
	for (edge &e : G[v]) {
	    if (e.cap > 0 && level[e.to] < 0) {
		level[e.to] = level[v] + 1;
		que.push(e.to);
	    }
	}
    }
}

int dfs(int v, int t, int f)
{
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); i++) {
	edge &e = G[v][i];
	if (e.cap > 0 && level[v] < level[e.to]) {
	    int d = dfs(e.to, t, min(f, e.cap));
	    if (d > 0) {
		e.cap -= d;
		G[e.to][e.rev].cap += d;
		return d;
	    }
	}
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while (true) {
	bfs(s);
	if (level[t] < 0) return flow;
	memset(iter, 0, sizeof(iter));
	int f;
	while ((f = dfs(s, t, INF)) > 0) flow += f;
    }
}

int n, m, x;
int a[510], b[510], c[510];

int main() {
    cin >> n >> m >> x;

    rep(i, m) {
	cin >> a[i] >> b[i] >> c[i];
	--a[i]; --b[i];
    }

    double lo = 1e-7, hi = 1e7;

    rep(t, 100) {
	double mc = (lo + hi) / 2;

	rep(i, n) G[i].clear();

	rep(i, m) {
	    int cap = min((double)c[i] / mc, 1e6);
	    add_edge(a[i], b[i], cap);
	}

	int f = max_flow(0, n - 1);

	if (f >= x) lo = mc;
	else hi = mc;
    }

    printf("%.8f\n", lo * x);

    return 0;
}