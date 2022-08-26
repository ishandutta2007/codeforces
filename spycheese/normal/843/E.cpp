#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }
mt19937 mmtw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(mmtw) % (y - x + 1) + x; }

// ========================================================================= //
namespace dinic {
    int const INF = 100 + (int) 1e9;
    ll const INFL = 100 + (ll) 1e18;
    int const N = 200200;

    struct edge_t {
        int to, cap, flow;
        
        edge_t(int to, int cap)
            : to(to)
            , cap(cap)
            , flow(0)
        {}
    };

    vector<edge_t> all;
    vector<int> g[N];
    int index[N], dist[N];

    void add_edge(int from, int to, int cap1, int cap2) {
        g[from].push_back(all.size());
        all.emplace_back(to, cap1);
        g[to].push_back(all.size());
        all.emplace_back(from, cap2);
    }

    void init_graph(int n) {
        all.clear();
        for (int i = 0; i < n; ++i) {
            g[i].clear();
        }
    }

    void clear_flow() {
        for (auto& edge : all) {
            edge.flow = 0;
        }
    }

    int dfs(int v, int sink, int flow) {
        if (v == sink || flow == 0) {
            return flow;
        }
        for (int& i = index[v]; i < (int)g[v].size(); ++i) {
            int x = g[v][i];
            auto& e = all[x];
            int to = e.to;
            int diff = e.cap - e.flow;
            if (diff > 0 && dist[v] - 1 == dist[to]) {
                int now = dfs(to, sink, min(flow, diff));
                if (now > 0) {
                    e.flow += now;
                    all[x ^ 1].flow -= now;
                    return now;
                }
            }
        }
        return 0;
    }

    ll max_flow(int source, int sink, int n) {
        clear_flow();
        ll ret = 0;
        while (true) {
            static int q[N];
            memset(dist, 63, sizeof(int) * n);
            int tail = 0;
            dist[q[tail++] = sink] = 0;
            for (int i = 0; i < tail; ++i) {
                int v = q[i];
                for (int x : g[v]) {
                    int to = all[x].to;
                    if (all[x ^ 1].flow < all[x ^ 1].cap && dist[to] > INF) {
                        dist[q[tail++] = to] = dist[v] + 1;
                    }
                }
            }
            if (dist[source] > INF) {
                break;
            }
            memset(index, 0, n * sizeof(int));
            while (int flow = dfs(source, sink, INF)) {
                ret += flow;
            }
        }
        return ret;
    }
}

//void add_edge(int from, int to, int cap1, int cap2) {
//void init_graph(int n) {
//ll max_flow(int source, int sink, int n) {

const int N = 111;

struct Edge {
    bool g;
    int x, y;
    int cap = 0, flow = 0;
};

int n, m, s1, s2;
vector < int > e[N], eb[N];
vector < Edge > es;

bool vis[N];
bool vis11[N];

void dfs1(int v) {
    if (vis11[v])
        return;
    vis11[v] = true;
    for (int i : dinic::g[v]) {
        dinic::edge_t edge = dinic::all[i];
        if (edge.cap != edge.flow)
            dfs1(edge.to);
    }
}

bool dfs2(int v, int fin) {
    if (v == fin)
        return true;
    if (vis[v])
        return false;
    vis[v] = true;
    for (int i : e[v]) {
        Edge &ee = es[i];
        if (!ee.g)
            continue;
        ++ee.cap;
        ++ee.flow;
        if (dfs2(ee.y, fin))
            return true;
        --ee.cap;
        --ee.flow;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d%d%d%d", &n, &m, &s1, &s2);
    --s1; --s2;
    dinic::init_graph(n);
    for (int i = 0; i < m; ++i) {
        int x, y, g;
        scanf("%d%d%d", &x, &y, &g);
        --x;
        --y;
        e[x].push_back(sz(es));
        Edge ce;
        ce.x = x;
        ce.y = y;
        ce.g = g;
        es.push_back(ce);
        if (g) {
            dinic::add_edge(x, y, 1, 0);
            dinic::add_edge(y, x, dinic::INF, 0);
        } else {
            dinic::add_edge(x, y, dinic::INF, 0);
        }
    }

    int flw = dinic::max_flow(s1, s2, n);

    dfs1(s1);
    for (Edge &ee : es) {
        if (ee.g) {
            ++ee.flow;
            ++ee.cap;
            memset(vis, 0, sizeof(vis));
            dfs2(s1, ee.x);
            memset(vis, 0, sizeof(vis));
            dfs2(ee.y, s2);
            if (!(vis11[ee.x] && !vis11[ee.y])) {
                ++ee.cap;
            }
        } else
            ee.cap = 1;
    }

    cout << flw << "\n";
    for (Edge const& ee : es)
        cout << ee.flow << " " << ee.cap << "\n";
    return 0;
}