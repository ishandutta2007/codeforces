#include <iostream>
#include <vector>

using namespace std;

int total_ops = 0;

struct DSU {
    vector<int> parent, sizes, parts;
    
    vector<pair<int*, int>> history;

    int bipartite = 1;

    DSU(int n) {
        parent.assign(n, -1);
        sizes.assign(n, 1);
        parts.resize(n);
    }

    int find(int v) {
        if (parent[v] == -1) {
            return v;
        }
        return find(parent[v]);
    }

    int get_parity(int v) {
        if (parent[v] == -1) {
            return 0;
        }
        return parts[v] ^ get_parity(parent[v]);
    }

    void merge(int v, int u) {
        int x = find(v), y = find(u);
        int a = get_parity(v), b = get_parity(u);
        
        if (x == y) {
            if (a == b) {
                history.emplace_back(&bipartite, bipartite);
                bipartite = 0;
            }
            return;
        }

        if (sizes[x] > sizes[y]) {
            swap(x, y);
            // swap(a, b);
        }
        history.emplace_back(&parent[x], parent[x]);
        parent[x] = y;

        history.emplace_back(&sizes[y], sizes[y]);
        sizes[y] += sizes[x];

        history.emplace_back(&parts[x], parts[x]);
        parts[x] = a ^ b ^ 1;
    }

    bool breaks(int v, int u) {
        int x = find(v), y = find(u);
        int a = get_parity(v), b = get_parity(u);
        return x == y && a == b;
    }

    int backup() {
        return history.size();
    }

    void sync(int old_size) {
        while (history.size() > old_size) {
            *history.back().first = history.back().second;
            history.pop_back();
            total_ops++;
        }
    }
};

struct Edge {
    int v, u;
    explicit Edge() {

    }
    Edge(int v_, int u_) : v(v_), u(u_) {

    }
};


void solve(const vector<Edge> &edges, DSU &dsu, vector<int> &res, int l, int r, int ans_l, int ans_r) {
    total_ops += ans_r - ans_l;
    if (l + 1 == r) {
        int backup = dsu.backup();
        dsu.merge(edges[l].v, edges[l].u);
        int i = ans_l;
        while (i < ans_r && !dsu.breaks(edges[i].v, edges[i].u)) {
            dsu.merge(edges[i].v, edges[i].u);
            i++;
        }
        res[l] = i;
        dsu.sync(backup);
        return;
    }
    int m = (l + r) / 2;
    
    int backup = dsu.backup();
    if (r < ans_l) {
        for (int i = m; i < r; i++) {
            dsu.merge(edges[i].v, edges[i].u);
        }
        int temp_backup = dsu.backup();
        int ans_m = ans_l;
        while (ans_m < ans_r && !dsu.breaks(edges[ans_m].v, edges[ans_m].u)) {
            dsu.merge(edges[ans_m].v, edges[ans_m].u);
            ans_m++;
        }
        dsu.sync(temp_backup);
        solve(edges, dsu, res, l, m, ans_l, ans_m);
        dsu.sync(backup);
        for (int i = ans_l; i < ans_m; i++) {
            dsu.merge(edges[i].v, edges[i].u);
        }
        solve(edges, dsu, res, m, r, ans_m, ans_r);
        dsu.sync(backup);
    } else {
        int i = m;
        while (i < ans_r && !dsu.breaks(edges[i].v, edges[i].u)) {
            dsu.merge(edges[i].v, edges[i].u);
            i++;
        }
        dsu.sync(backup);
        for (int j = m; j < ans_l; j++) {
            dsu.merge(edges[j].v, edges[j].u);
        }
        solve(edges, dsu, res, l, m, ans_l, i);
        dsu.sync(backup);
        for (int j = r; j < i; j++) {
            dsu.merge(edges[j].v, edges[j].u);
        }
        solve(edges, dsu, res, m, r, i, ans_r);
        dsu.sync(backup);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    vector<Edge> edges(2 * m);
    for (int i = 0; i < m; i++) {
        int v, u; cin >> v >> u; v--; u--;
        edges[i] = edges[m + i] = Edge(v, u);
    }
    DSU dsu(n);
    vector<int> res(2 * m);
    solve(edges, dsu, res, 0, 2 * m, 0, 2 * m);
    cerr << total_ops << endl;
    while (q--) {
        int l, r; cin >> l >> r;
        l += m - 1;
        swap(l, r);
        if (res[l] >= r) {
            cout << "NO" << '\n';
        } else {
            cout << "YES" << '\n';
        }
    }
}