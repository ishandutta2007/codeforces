#include <bits/stdc++.h>
using namespace std;
typedef array<int, 3> ar;
typedef pair<int, int> ii;

const int MAXN = 5e5 + 10;
ar edges[MAXN];
vector<ar> se;
int rep[MAXN], sz[MAXN], cnt[MAXN];
bool ans[MAXN];
vector<ii> byw[MAXN], check[MAXN], ops;

void init() {
    iota(rep, rep + MAXN, 0);
    fill(sz, sz + MAXN, 1);
}

int find(int u) {
    return (rep[u] == u ? u : find(rep[u]));
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) {
        ops.push_back({-1, -1});
        return false;
    }
    if(sz[u] < sz[v])
        swap(u, v);
    rep[v] = u;
    sz[u] += sz[v];
    ops.push_back({u, v});
    return true;
}

void undo() {
    auto p = ops.back(); ops.pop_back();
    if(p.first > -1) {
        rep[p.second] = p.second;
        sz[p.first] -= sz[p.second];
    }
}

void kruskal() {
    for(int w = 1; w < MAXN; w++) {
        int prv = 0;
        for(int i = 0; i < check[w].size(); i++) {
            if(i > 0 && check[w][i].first != check[w][i - 1].first) {
                while(prv < i) {
                    undo();
                    prv++;
                }
            }
            auto p = check[w][i];
            int x = p.second;
            auto e = edges[x];
            ans[p.first] &= (join(e[0], e[1]));
        }
        while(prv < check[w].size()) {
            undo();
            prv++;
        }
        for(auto e : byw[w])
            join(e.first, e.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i + 1] = {u, v, w};
        byw[w].push_back({u, v});
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int k;
        cin >> k;
        while(k--) {
            int x;
            cin >> x;
            check[edges[x][2]].push_back({i, x});
        }
    }
    fill(ans, ans + MAXN, true);
    init();
    kruskal();
    for(int i = 0; i < q; i++)
        cout << (ans[i] ? "YES" : "NO") << '\n';
}