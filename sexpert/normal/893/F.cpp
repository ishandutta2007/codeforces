#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 2e9;

struct node {
    int l, r, mn;
    node *left, *right;

    node(int l, int r, int mn = INF) : l(l), r(r), mn(mn){}

    void build() {
        if(l == r)
            return;
        int m = (l + r)/2;
        left = new node(l, m);
        right = new node(m + 1, r);
        left->build();
        right->build();
    }

    node* upd(int p, int v) {
        if(r < p || p < l)
            return this;
        if(l == r)
            return new node(l, r, v);
        node* res = new node(l, r);
        res->left = left->upd(p, v);
        res->right = right->upd(p, v);
        res->mn = min(res->left->mn, res->right->mn);
        return res;
    }

    int qry(int rl, int rr) {
        if(r < rl || rr < l) return INF;
        if(rl <= l && r <= rr) return mn;
        return min(left->qry(rl, rr), right->qry(rl, rr));
    }
};

int sz[MAXN], tin[MAXN], ht[MAXN], httime[MAXN], val[MAXN], t;
vector<int> adj[MAXN], vh[MAXN];

void dfs(int s, int p = 0) {
    sz[s] = 1;
    tin[s] = ++t;
    ht[s] = p ? ht[p] + 1 : 0;
    vh[ht[s]].push_back(s);
    for(auto v : adj[s]) {
        if(v != p) {
            dfs(v, s);
            sz[s] += sz[v];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, r;
    cin >> n >> r;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(r);
    vector<node*> trees;
    trees.push_back(new node(1, n));
    trees[0]->build();
    for(int h = 0; h < n; h++) {
        for(auto v : vh[h])
            trees.push_back(trees.back()->upd(tin[v], val[v]));
        httime[h] = trees.size() - 1;
    }
    int last = 0, m;
    cin >> m;
    while(m--) {
        int x, k;
        cin >> x >> k;
        x = 1 + (x + last)%n;
        k = (k + last)%n;
        int mht = min(ht[x] + k, n - 1);
        last = trees[httime[mht]]->qry(tin[x], tin[x] + sz[x] - 1);
        cout << last << '\n';
    }
}