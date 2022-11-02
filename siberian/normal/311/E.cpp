#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define all(a) (a).begin(), (a).end()

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define int ll

const int INF = 1e9 + 229;
    
struct Dinic{
    struct Edge{
        int to, cap, flow;
        Edge() = delete;
        Edge(int _to, int _cap)
            : to(_to)
            , cap(_cap)
            , flow(0)
            {}
        int getCap() const {
            return cap - flow;
        }
    };
    int n;
    int s, t;
    vector<Edge> edges;
    vector<vector<int>> g;
    Dinic() = delete;
    Dinic(int _n, int _s, int _t) 
        : n(_n)
        , s(_s)
        , t(_t)
        , edges()
        , g(n, vector<int>())
        {}
    void addEdge(int from, int to, int cap) {
        g[from].push_back(edges.size());
        edges.emplace_back(to, cap);
        g[to].push_back(edges.size());
        edges.emplace_back(from, 0);
        // cerr << "from = " << from << " to = " << to << " cap = " << cap << endl;
        // cerr << from << " " << to << " " << cap << endl;
    }
    vector<int> dist;
    queue<int> q;
    bool bfs() {
        dist.assign(n, INF);
        dist[s] = 0;
        q.push(s);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto i : g[v]) {
                int to = edges[i].to;
                if (edges[i].getCap() < 1) continue;
                if (dist[to] != INF) continue;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
        return dist[t] != INF;
    }
    vector<int> pos;
    int dfs(int v, int flow) {
        // cerr << "v = " << v << endl;
        if (v == t) return flow;
        if (flow == 0) return flow;
        int res = 0;
        for (; pos[v] < g[v].size(); ++pos[v]) {
            int ind = g[v][pos[v]];
            if (edges[ind].getCap() < 1) continue;
            int to = edges[ind].to;
            if (dist[to] != dist[v] + 1) continue;
            assert(edges[ind].getCap() >= 0);
            int add = dfs(to, min(flow, edges[ind].getCap()));
            if (add == 0) continue;
            edges[ind].flow += add;
            edges[ind ^ 1].flow -= add;
            res += add;
            flow -= add;
        }
        return res;
    }
    int getMaxFlow() {
        int ans = 0;
        while (bfs()) {
            while (true) {
                pos.assign(n, 0);
                int x = dfs(s, INF);
                if (x == 0) break;
                ans += x;
            }
        }
        return ans;
    }
};

const int N = 1e4 + 10;
const int M = 2e3 + 10;
const int K = 10;

int n, m, g;
int type[N];
int v[N];

int need[M];
int w[M];
int k[M];
int ind[M][K];
int typeW[M];

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    cin >> n >> m >> g;
    for (int i = 0; i < n; ++i) {
        cin >> type[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> need[i] >> w[i] >> k[i];
        for (int j = 0; j < k[i]; ++j) {
            cin >> ind[i][j];
            --ind[i][j];
        }
        cin >> typeW[i];
    }

    int s = m + n;
    int t = m + n + 1;
    Dinic st(m + n + 2, s, t);
    
    for (int i = 0; i < n; ++i) {
        int id = i + m;
        if (type[i] == 0) {
            st.addEdge(s, id, v[i]);
            st.addEdge(id, t, 0);
        } else {
            st.addEdge(s, id, 0);
            st.addEdge(id, t, v[i]);
        }
    }

    // cerr << "puhh" << endl;

    int ans = 0;

    for (int i = 0; i < m; ++i) {
        ans += w[i];
        if (need[i] == 0) {
            st.addEdge(s, i, w[i] + (typeW[i] ? g : 0));
            for (int j = 0; j < k[i]; ++j) {
                st.addEdge(i, m + ind[i][j], INF);
            }
        } else {
            st.addEdge(i, t, w[i] + (typeW[i] ? g : 0));
            for (int j = 0; j < k[i]; ++j) {
                st.addEdge(m + ind[i][j], i, INF);
            }
        }
    }

    // cerr << "end Init" << endl;
    // cerr << "ans = " << ans << endl;
    int maxFLow = st.getMaxFlow();
    // cerr << "maxFLow = " << maxFLow << endl;
    cout << ans - maxFLow << endl;
    return 0;
}