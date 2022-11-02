#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int MAXN = 1e5 + 10;

int n, m;
vector<int> g[MAXN], rev_g[MAXN], gr[MAXN];
vector<pair <int, int> > ed;
vector<int> order;

bool used[MAXN];
int color[MAXN], sz[MAXN];

vector<int> colors[MAXN], good;

int query(int u, int v) {
    cout << "? " << u + 1 << " " << v + 1 << endl;
    int q;
    cin >> q;
    return q;
} 

void out(int ans) {
    cout << "! " << ans + 1 << endl;
    exit(0);
}

void read() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ed.push_back({u, v});
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }
}

void dfs_order(int v) {
    used[v] = true;
    for (auto i : g[v])
        if (!used[i])
            dfs_order(i);
    order.push_back(v);
}

void dfs_color(int v, int c) {
    color[v] = c;
    for (auto i : rev_g[v])
        if (!color[i])
            dfs_color(i, c);
}

void clear() {
    for (int i = 0; i < n; i++)
        used[i] = false;
}

void run() {
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs_order(i);
    clear();
    
    reverse(order.begin(), order.end());
    int col = 1;
    for (auto i : order)
        if (!color[i])
            dfs_color(i, col++);
    
    for (auto i : ed) {
        int u = color[i.first] - 1, v = color[i.second] - 1;
        if (u != v) {
            gr[u].push_back(v);
            sz[v]++;
        }
    }

    col--;
    
    for (int i = 0; i < n; i++)
        colors[color[i] - 1].push_back(i);

    for (int i = 0; i < col; i++)
        if (sz[i] == 0)
            good.push_back(i);

    int help_root = good.back();
    good.pop_back();

    int root = colors[help_root].back();
    colors[help_root].pop_back();

    while (!good.empty()) {
        int v = good.back();
        good.pop_back();        
        
        while (!colors[v].empty()) {
            int u = colors[v].back();
            colors[v].pop_back();

            int q = query(root, u);
            if (q == 0){
                swap(u, root);
                swap(v, help_root);
            }
        }

        for (auto i : gr[v]) {
            sz[i]--;
            if (sz[i] == 0)
                good.push_back(i);
        }
    }

    out(root);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    return 0;
}