#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e18 + 7;
const int N = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 21;

struct Edge {
    ll v, u, w;
};

vector <vector <pair <ll, ll> > > gr;

int n, m;

struct Tree {
    ll s;
    vector <vector <pair <ll, ll> > > tree;
    ll sumw[N];
    int h[N];
    int binup[LOGN][N];
    void dfs(ll v, ll p, ll w) {
        binup[0][v] = p;
        if (p != -1) {
            h[v] = h[p] + 1;
            sumw[v] = sumw[p] + w;
        }
        for (ll i = 1; i < LOGN; i++) {
            if (binup[i - 1][v] == -1) continue;
            binup[i][v] = binup[i - 1][binup[i - 1][v]];
        }
        for (auto e : tree[v]) {
            dfs(e.first, v, e.second);
        }
    }

    ll up(ll v, ll d) {
        for (ll i = LOGN - 1; i >= 0; i--) {
            if (d < (1LL << i)) continue;
            d -= 1LL << i;
            v = binup[i][v];
        }
        return v;
    }

    ll lca(ll v, ll u) {
        if (h[v] > h[u]) swap(v, u);
        ll d = h[u] - h[v];
        u = up(u, d);
        if (v == u) {
            return v;
        }
        for (ll i = LOGN - 1; i >= 0; i--) {
            if (binup[i][v] == binup[i][u]) continue;
            v = binup[i][v];
            u = binup[i][u];
        }
        return binup[0][v];
    }

    ll sump(ll v, ll u) {
        return sumw[v] + sumw[u] - 2 * sumw[lca(v, u)];
    }
    void init() {
        for (ll i = 0; i < LOGN; i++) {
            fill_n(binup[i], N, -1);
        }
        dfs(s, -1, 0);
    }
    Tree(vector <vector <pair <ll, ll> > > a , ll s) : s(s) {
        tree = a;
        init();
    }
};

Tree get_tree(ll s) {
    vector <ll> d(n, INF);
    vector <pair <ll, ll> > p(n);
    d[s] = 0;
    set <pair <ll, ll> > q;
    q.insert({d[s], s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        for (auto e : gr[v]) {
            ll u = e.first, w = e.second;
            if (d[u] > d[v] + w) {
                q.erase({d[u], u});
                d[u] = d[v] + w;
                p[u] = {v, w};
                q.insert({d[u], u});
            }
        }
    }
    vector <vector <pair <ll, ll> > > tree(n);
    for (ll i = 0; i < n; i++) {
        if (i == s) continue;
        ll v = p[i].first, w = p[i].second;
        tree[v].push_back({i, w});
    }
    Tree t(tree, s);
    return t;
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
    cin >> n >> m;
    gr.resize(n);
    for (int i = 0; i < m; i++) {
        ll v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        gr[v].push_back({u, w});
        gr[u].push_back({v, w});
    }
    auto t = get_tree(0);
    set <pair <ll, ll> > edges;
    for (ll v = 0; v < n; v++) {
        for (auto e : t.tree[v]) {
            edges.insert({e.first, v});
            edges.insert({v, e.first});
        }
    }
    vector <int> roots;
    roots.push_back(0);
    for (ll v = 0; v < n; v++) {
        for (auto e : gr[v]) {
            ll u = e.first, w = e.second;
            if (u > v) continue;
            if (edges.find({v, u}) == edges.end()) {
                roots.push_back(v);
            }
        }
    }
    ll qu;
    cin >> qu;
    vector <ll> res(qu, INF);
    vector <pair <int, int> > queries(qu);
    for (ll i = 0; i < qu; i++) {
        ll v, u;
        cin >> v >> u;
        v--, u--;
        queries[i] = {v, u};
    }
    for (int s : roots) {
        t = get_tree(s);
        for (int i = 0; i < qu; i++) {
            res[i] = min(res[i], t.sump(queries[i].first, queries[i].second));
        }
    }
    for (int i = 0; i < qu; i++) {
        cout << res[i] << " ";
    }
}