#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 5;
int col[MAXN], par[MAXN], deg[MAXN], in_diam[MAXN], dep[MAXN], del, n, k, cv, cd;
vector<int> adj[MAXN], diam;
bool orz;

void dfs_fill(int s, int c) {
    col[s] = c;
    for(auto v : adj[s]) {
        if(col[v])
            continue;
        int nc = c + del;
        if(nc == 0)
            nc = k;
        if(nc == k + 1)
            nc = 1;
        dfs_fill(v, nc);
    }
}

void dfs_dis(int s, int p, int d) {
    par[s] = p;
    if(d > cd) {
        cd = d;
        cv = s;
    }
    for(auto v : adj[s]) {
        if(v == p || in_diam[v])
            continue;
        dfs_dis(v, s, d + 1);
    }
}

void get_diam() {
    cd = 0;
    dfs_dis(1, 0, 0);
    int u = cv;
    cd = 0;
    dfs_dis(u, 0, 0);
    int v = cv;
    //cout << u << " " << v << " diameter " << endl;
    while(v != 0) {
        diam.push_back(v);
        in_diam[v] = 1;
        v = par[v];
    }
}

void get(int s) {
    cd = 0;
    dfs_dis(s, 0, 0);
    cd = 0;
    dfs_dis(cv, 0, 0);
    if(cd > k)
        orz = false;
}

struct node {
    int l, r, mx, ad;
    node *left, *right;
    int get() { return mx + ad; }
    void merge() { mx = max(left->get(), right->get()); }
    void push() { left->ad += ad; right->ad += ad; ad = 0; }
    node(int l, int r) : l(l), r(r), mx(0), ad(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }
    void upd(int rl, int rr, int v) {
        if(r < rl || rr < l) return;
        if(rl <= l && r <= rr) { ad += v; return; }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }
    int qry(int rl, int rr) {
        if(r < rl || rr < r || rl > rr) return -10000000;
        if(rl <= l && r <= rr) return get();
        push();
        merge();
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    del = 1;
    if(k == 2) {
        cout << "Yes\n";
        del = 1;
        dfs_fill(1, 1);
        for(int i = 1; i <= n; i++)
            cout << col[i] << " ";
        cout << '\n';
        return 0;
    }
    get_diam();
    int d = diam.size();
    for(int i = 0; i < d; i++) {
        col[diam[i]] = (i % k) + 1;
        if(i < d/2)
            del = -1;
        else
            del = 1;
        int nc = col[diam[i]] + del;
        if(nc == 0)
            nc = k;
        if(nc == k + 1)
            nc = 1;
        for(auto v : adj[diam[i]]) {
            if(!in_diam[v])
                dfs_fill(v, nc);
        }
    }
    orz = true;
    for(int i = 0; i < d; i++) {
        int u = diam[i];
        for(auto v : adj[u]) {
            if(!in_diam[v]) {
                get(v);
                cd = 0;
                dfs_dis(v, 0, 1);
                dep[u] = max(dep[u], cd + 1);
            }
        }
        if(dep[u] && dep[u] + min(i, d - 1 - i) >= k)
            orz = false;
    }
    int dd = d/2 - 1;
    node tree(0, dd);
    for(int i = 0; i <= dd; i++) {
        if(i > 0)
            tree.upd(0, i - 1, 1);
        if(!dep[diam[i]]) {
            tree.upd(i, i, -10000000);
            continue;
        }
        int top = tree.qry(max(0, i - k + 3), i - 1);
        if(top + dep[diam[i]] >= k)
            orz = false;
        tree.upd(i, i, dep[diam[i]] - 1);
    }
    tree = node(dd + 1, d - 1);
    for(int i = d - 1; i >= dd + 1; i--) {
        if(i < d - 1)
            tree.upd(i + 1, d - 1, 1);
        if(!dep[diam[i]]) {
            tree.upd(i, i, -10000000);
            continue;
        }
        int top = tree.qry(i + 1, min(d - 1, i + k - 3));
        if(top + dep[diam[i]] >= k)
            orz = false;
        tree.upd(i, i, dep[diam[i]] - 1);
    }
    if(!orz) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for(int i = 1; i <= n; i++)
        cout << col[i] << " ";
    cout << '\n';
}