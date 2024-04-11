#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef long double ld;

const int MAXN = 5e5 + 100;

struct edge {
        int from, to, num;
};

struct dsu {
        int r[MAXN];
        int p[MAXN];
        void clear(int n) {
                forn(i, n) {
                        r[i] = 0;
                        p[i] = i;
                }
        }

        int get(int v) {
                if (v == p[v]) {
                        return v;
                } else {
                        return p[v] = get(p[v]);
                }
        }

        bool unite(int u, int v) {
                u = get(u);
                v = get(v);
                if (u == v) {
                        return false;

                }
                if (r[u] < r[v]) {
                        p[u] = v;
                } else {
                        p[v] = u;
                        if (r[v] == r[u]) {
                                r[u]++;
                        }
                }
                return true;
        }

};

vector<edge> g[MAXN];
edge par[MAXN];
int val[MAXN];
int dpt[MAXN];
bool used[MAXN];
dsu d;

void dfs(int v, int curd) {
        used[v] = true;
        dpt[v] = curd;
        for (auto& e : g[v]) {
                if (used[e.to]) {
                        continue;
                }
                par[e.to] = e;
                dfs(e.to, curd + 1);
        }
}

int ffree[MAXN];

void pushUp(int& v, int w) {
        if (v == ffree[d.get(v)]) {
                int parv = par[v].from;
                int ofree = ffree[d.get(parv)];
                d.unite(parv, v);
                val[par[v].num] = w;
                ffree[d.get(v)] = ofree;
                v = ofree;
        } else {
                v = ffree[d.get(v)];
        }
}

void setPath(const edge& e) {
        int u = e.from;
        int v = e.to;
        int w = e.num;
        while (u != v) {
                //cerr << u << ' ' << v << '\n';
                if (dpt[u] < dpt[v]) {
                        pushUp(v, w);
                } else {
                        pushUp(u, w);
                }
        }
}

int main() {
        //freopen("d.in", "r", stdin);
        //freopen("a.out", "w", stdout);
        cin.sync_with_stdio(0);
        cin.tie(0);
        int n, k, m;cin >> n >> k >> m;
        d.clear(n);
        forn(i, k) {
                int u, v;
                cin >> u >> v;
                u--, v--;
                g[u].push_back({u, v, i});
                g[v].push_back({v, u, i});
                d.unite(u, v);
        }

        vector<edge> f;

        forn(i, m) {
                int u, v, w;
                cin >> u >> v >> w;
                u--, v--;
                if (!d.unite(u, v)) {
                        f.push_back({u, v, w});
                } else {
                        g[u].push_back({u, v, k});
                        g[v].push_back({v, u, k});
                }
        }

        dfs(0, 0);

        d.clear(n);
        forn(i, n) {
                ffree[i] = i;
        }
        for (auto& e : f) {
                setPath(e);
        }

        long long sum = 0;
        forn(i, k) {
                sum += val[i];
                if (val[i] == 0) {
                        sum = -1;
                        break;
                }
        }
        cout << sum << '\n';

        return 0;
}