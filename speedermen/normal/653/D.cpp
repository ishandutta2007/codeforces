#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MD = 1000000007;

#define ll long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, a, b) for (int _tmp = b, i = a; i <= _tmp; ++i)

typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < vi > vvi;

const int MAXN = 500; //  
const int INF = 1000000000; // -

int n, s, t, vis[MAXN], d[MAXN], ptr[MAXN], q[MAXN], pt;
vector <int> g[MAXN];

struct Edge {
    int from, to, cap, flow;
} e[MAXN * MAXN];

void addEdge(int u, int v, int c) {
    e[pt].from = u;
    e[pt].to = v;
    e[pt].flow = 0;
    e[pt].cap = c;
    g[u].push_back(pt++);
    e[pt].from = v;
    e[pt].to = u;
    e[pt].flow = c;
    e[pt].cap = c;
    g[v].push_back(pt++);
}

bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt) {
        int v = q[qh++];
        for (int id = 0; id < (int)g[v].size(); ++id) {
            int y = g[v][id];
            int to = e[y].to;
            if (d[to] == -1 && e[y].flow < e[y].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (int & id=ptr[v]; id< (int)g[v].size(); ++id) {
        int y = g[v][id];
        int to = e[y].to;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[y].cap - e[y].flow));
        if (pushed) {
            e[y].flow += pushed;
            e[y ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, INF)) {
            flow += pushed;
        }
    }
    return flow;
}

int main()
{
//  freopen("input.txt", "rt", stdin);
//  freopen("output.txt", "wt", stdout);
    ios_base::sync_with_stdio(0);
    int m, x;
    cin >> n >> m >> x;
    s = 0; t = n - 1;
    vector < tuple <int, int, int> > edges;
    FOR(i, 0, m - 1) {
        int x, y, cp;
        cin >> x >> y >> cp;
        x--;
        y--;
        edges.push_back(make_tuple(x, y, cp));
    }
    double l = 0.000001, r = 1e9;
    for (int it = 0; it < 100; ++it) {
        double m = (l + r) * 0.5;
        pt = 0;
        for (int i = 0; i < (int)edges.size(); ++i) {
            addEdge(get<0>(edges[i]), get<1>(edges[i]), min((long long)(get<2>(edges[i]) / m), x * 1LL));
        }
        if (dinic() >= x) {
            l = m;
        } else {
            r = m;
        }
    }
    cout.precision(6);
    cout << fixed << (l + r) / 2 * x << endl;
    return 0;
}