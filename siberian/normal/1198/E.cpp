#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x1 x1228
#define y1 y1228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

struct edge{
    int to, cap, flow;
    edge() {}
    edge(int _to, int _cap) {
        to = _to, cap = _cap, flow = 0;
    }
    int get_cap() {
        return cap - flow;
    }
};

struct max_flow{
    vector<edge> Edge;
    vector<vector<int>> g;
    int n;
    int s, f;

    max_flow() {}

    void add_edge(int from, int to, int cap) {
        g[from].push_back(Edge.size());
        Edge.push_back({to, cap});
        g[to].push_back(Edge.size());
        Edge.push_back({from, 0});
    }

    max_flow(int _n, int _s, int _f) {
        n = _n, s = _s, f = _f;
        g.assign(n, {});
        Edge.clear();
    }

    vector<int> dist;
    queue<int> q;

    const int INF = 1e9 + 10;

    bool bfs() {
        dist.assign(n, INF);
        dist[s] = 0;
        q.push(s);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto i : g[v]) {
                if (Edge[i].get_cap() < 1) continue;
                int to = Edge[i].to;
                if (dist[to] != INF) continue;
                dist[to] = dist[v] + 1;
                q.push(to);
            }  
        }
        return dist[f] != INF;
    }

    vector<int> pos;

    int dfs(int v, int flow) {
        if (v == f) return flow;
        for (; pos[v] < g[v].size(); pos[v]++) {
            int ind = g[v][pos[v]];
            if (Edge[ind].get_cap() < 1) continue;
            int to = Edge[ind].to;
            if (dist[to] != dist[v] + 1) continue;
            int add = dfs(to, min(flow, Edge[ind].get_cap()));
            if (add) {
                Edge[ind].flow += add;
                Edge[ind ^ 1].flow -= add;
                return add;
            }
        }
        return 0;
    }

    int get_flow() {
        int ans = 0;
        while (bfs()) {
            pos.assign(n, 0);
            while (true) {
                int add = dfs(s, INF);
                ans += add;
                //cout << add << endl;
                if (!add) break;
            }
        } 
        return ans;
    }
};

const int MAXM = 51;

int n, m;
int x1[MAXM], y1[MAXM], x2[MAXM], y2[MAXM];
vector<int> x, y;

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x2[i]++;
        y2[i]++;
        x.push_back(x1[i]);
        x.push_back(x2[i]);
        y.push_back(y1[i]);
        y.push_back(y2[i]);
    }
}

int ans;

void run() {
    sort(all(x));
    x.resize(unique(all(x)) - x.begin());
    sort(all(y));
    y.resize(unique(all(y)) - y.begin());

    max_flow g(x.size() + y.size() + 2, x.size() + y.size(), x.size() + y.size() + 1);
    for (int i = 0; i < (int) x.size() - 1; i++) {
        g.add_edge(g.s, i, x[i + 1] - x[i]);
    }
    for (int i = 0; i < (int) y.size() - 1; i++) {
        g.add_edge(i + x.size(), g.f, y[i + 1] - y[i]);
    }

    for (int el = 0; el < m; el++) {
        for (int i = 0; i < (int) x.size() - 1; i++) {
            for (int j = 0; j < (int) y.size() - 1; j++) {
                if (x1[el] <= x[i] && x[i + 1] <= x2[el] && y1[el] <= y[j] && y[j + 1] <= y2[el])
                    g.add_edge(i, j + x.size(), (x[i + 1] - x[i]) + (y[j + 1] - y[j]));
            }
        }
    }
    ans = g.get_flow();
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}