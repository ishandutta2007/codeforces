#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 205;
const ll INF = (ll)3e18 + 50;

struct edge {
    int u, v, g, s;
};

int n, m;
int G, S;
vector<edge> E, Eb;

struct DSU {
    int f[N];

    void init() {
        for(int j = 0; j < n; j++) f[j] = j;
    }

    int find(int v) {
        return f[v] == v ? v : f[v] = find(f[v]);
    }

    int unite(int u, int v) {
        f[find(u)] = f[find(v)];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
} d1, d2;

ll check_cur() {
    d2.init();
    sort(Eb.begin(), Eb.end(), [](const edge &e1, const edge &e2) {
        return e1.s < e2.s;
    });//    for(int i = 0; i < n; i++) d2.f[i] = d1.f[i];
    ll res = 0;
    vector<edge> cur_E;
    for(edge e : Eb) {
        if(!d2.same(e.u, e.v)) {
            res = e.s;
            d2.unite(e.u, e.v);
            cur_E.push_back(e);
        }
    }
    Eb = cur_E;
    for(int i = 1; i < n; i++) if(!d2.same(0, i)) return -1;
    return res;
}

int main() {
    cin >> n >> m >> G >> S;
    for(int i = 0; i < m; i++) {
        int u, v, g, s;
        cin >> u >> v >> g >> s;
        u--, v--;
        E.push_back({u, v, g, s});
    }

    d1.init();
    sort(E.begin(), E.end(), [](const edge &e1, const edge &e2) {
        return e1.g < e2.g;
    });
    ll res = INF;
    ll cg = 0;
    for(edge e : E) {
        cg = e.g;
        Eb.push_back(e);
        ll cur = check_cur();
        if(cur != -1) res = min(res, cur * S + cg * G);
    }
    cout << (res == INF ? -1 : res) << endl;
}