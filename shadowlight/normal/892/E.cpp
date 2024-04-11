#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-8;
const int LOGN = 30;

vector <int> p, r;

void create(int v) {
    p[v] = v;
    r[v] = 0;
}

int get_root(int v) {
    if (p[v] == v) {
        return v;
    }
    return get_root(p[v]);
}

vector <int> rp, pp;
vector <bool> changed;
vector <int> was_changed;

void unite(int v, int u, bool need = 0) {
    v = get_root(v);
    u = get_root(u);
    if (v == u) return;
    if (!changed[u] && need) {
        changed[u] = true;
        was_changed.push_back(u);
        rp[u] = r[u];
        pp[u] = p[u];
    }
    if (!changed[v] && need) {
        changed[v] = true;
        was_changed.push_back(v);
        rp[v] = r[v];
        pp[v] = p[v];
    }
    if (r[v] > r[u]) {
        swap(v, u);
    }
    if (r[v] == r[u]) {
        r[u]++;
    }
    p[v] = u;
}

bool isUnited(int v, int u) {
    return get_root(v) == get_root(u);
}

struct Edge {
    int v, u, w;
};

struct Query {
    int id;
    vector <Edge> edges;
};

bool operator<(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    int n, m;
    cin >> n >> m;
    p.resize(n, 0);
    r.resize(n, 0);
    rp.resize(n, 0);
    pp.resize(n, 0);
    changed.resize(n, false);
    for (int i = 0; i < n; i++) {
        create(i);
    }
    vector <Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        edges[i] = {v, u, w};
    }
    vector <vector <Query> > data(MAXN);
    int qu;
    cin >> qu;
    for (int i = 0; i < qu; i++) {
        int k;
        cin >> k;
        map <int, vector <Edge> > all;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            all[edges[x].w].push_back(edges[x]);
        }
        for (auto p : all) {
            data[p.first].push_back({i, p.second});
        }
    }
    sort(edges.begin(), edges.end());
    vector <bool> ans(qu, true);
    int pw = 0;
    for (auto e : edges) {
        if (e.w == pw) {
            unite(e.v, e.u);
            continue;
        }
        pw = e.w;
        for (auto Q : data[e.w]) {
            bool fl = 0;
            for (auto E : Q.edges) {
                if (isUnited(E.v, E.u)) {
                    fl = 1;
                }
                unite(E.v, E.u, true);
            }
            for (int v : was_changed) {
                changed[v] = false;
                r[v] = rp[v];
                p[v] = pp[v];
            }
            was_changed.clear();
            if (fl) {
                ans[Q.id] = false;
            }
        }
        unite(e.v, e.u);
    }
    for (int i = 0; i < qu; i++) {
        cout << (ans[i] ? "YES" : "NO") << "\n";
    }
}