#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e5 + 10;
ll BIT[MAXN];
int up[MAXN][18], h[MAXN], tin[MAXN], tout[MAXN], a[MAXN], curt;
vector<int> adj[MAXN];

struct node {
    int l, r;
    ll val, lz;
    node *left, *right;

    ll get() {
        return val + lz*(r - l + 1);
    }
    void merge() {
        val = left->get() + right->get();
    }
    void push() {
        left->lz += lz;
        right->lz += lz;
        lz = 0;
    }

    node(int l, int r) : l(l), r(r), val(0), lz(0) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int rl, int rr, int v) {
        if(r < rl || rr < l)
            return;
        if(rl <= l && r <= rr) {
            lz += v;
            return;
        }
        push();
        left->upd(rl, rr, v);
        right->upd(rl, rr, v);
        merge();
    }

    ll qry(int rl, int rr) {
        if(r < rl || rr < l)
            return 0;
        if(rl <= l && r <= rr)
            return get();
        push();
        merge();
        return left->qry(rl, rr) + right->qry(rl, rr);
    }
};
node tree(0, 0);

void dfs(int s, int p = 1) {
    h[s] = (p == s ? 0 : h[p] + 1);
    up[s][0] = p;
    tin[s] = ++curt;
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
    tout[s] = curt;
}

int jmp(int u, int k) {
    for(int l = 17; l >= 0; l--)
        if((1 << l) & k)
            u = up[u][l];
    return u;
}

int lca(int u, int v, int r) {
    if(r == 1) {
        if(h[v] > h[u])
            swap(u, v);
        u = jmp(u, h[u] - h[v]);
        if(u == v)
            return u;
        for(int l = 17; l >= 0; l--) {
            if(up[u][l] != up[v][l]) {
                u = up[u][l];
                v = up[v][l];
            }
        }
        return up[u][0];
    }
    else {
        int luv = lca(u, v, 1), lru = lca(r, u, 1), lrv = lca(r, v, 1);
        int duv = h[u] + h[v] - 2*h[luv];
        int dru = h[r] + h[u] - 2*h[lru];
        int drv = h[r] + h[v] - 2*h[lrv];
        // duv = dru + drv - 2*dl
        int dl = (dru + drv - duv)/2;
        if(dl <= h[r] - h[lru])
            return jmp(r, dl);
        dl -= (h[r] - h[lru]);
        dl = (h[u] - h[lru]) - dl;
        return jmp(u, dl);
    }
}

ll qry(int u, int rt) {
    if(u == rt)
        return tree.get();
    else if(tin[u] < tin[rt] && tout[rt] <= tout[u]) {
        int x = jmp(rt, h[rt] - h[u] - 1);
        return tree.get() - tree.qry(tin[x], tout[x]);
    }
    return tree.qry(tin[u], tout[u]);
}

int main() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    tree = node(1, n);
    for(int i = 1; i <= n; i++)
        tree.upd(tin[i], tin[i], a[i]);
    for(int l = 0; l < 17; l++)
        for(int u = 1; u <= n; u++)
            up[u][l + 1] = up[up[u][l]][l];
    int rt = 1;
    //for(int i = 1; i <= n; i++)
    //    cout << "[" << tin[i] << ", " << tout[i] << "] " << h[i] << endl;
    for(int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if(t == 1)
            cin >> rt;
        if(t == 2) {
            int u, v, x;
            cin >> u >> v >> x;
            int l = lca(u, v, rt);
            //cout << "lca = " << l << endl;
            if(l == rt)
                tree.upd(1, n, x);
            else if(tin[l] < tin[rt] && tout[rt] <= tout[l]) {
                int k = jmp(rt, h[rt] - h[l] - 1);
                tree.upd(1, n, x);
                tree.upd(tin[k], tout[k], -x);
            }
            else
                tree.upd(tin[l], tout[l], x);
        }
        if(t == 3) {
            int u;
            cin >> u;
            cout << qry(u, rt) << '\n';
        }
    }
}