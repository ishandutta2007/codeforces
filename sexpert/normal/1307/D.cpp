#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2e5 + 10;
vi adj[MAXN];
int be[MAXN];

struct node {
    int l, r, ma;
    node *left, *right;

    node(int l, int r) : l(l), r(r), ma(-1) {
        if(l < r) {
            int m = (l + r)/2;
            left = new node(l, m);
            right = new node(m + 1, r);
        }
    }

    void upd(int p, int v) {
        if(r < p || p < l) return;
        if(l == r) { ma = v; return; }
        left->upd(p, v);
        right->upd(p, v);
        ma = max(left->ma, right->ma);
    }

    int qry(int rl, int rr) {
        if(rr < l || r < rl) return -2;
        if(rl <= l && r <= rr) return ma;
        return max(left->qry(rl, rr), right->qry(rl, rr));
    }
};

void bfs(int s, vector<int> &di) {
    fill(di.begin(), di.end(), -1);
    di[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : adj[u]) {
            if(di[v] == -1) {
                di[v] = di[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vi spec;
    vector<vi> di(2, vi(n + 1));
    for(int i = 0; i < k; i++) {
        int u;
        cin >> u;
        spec.push_back(u);
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1, di[0]);
    bfs(n, di[1]);

    node tree(0, n + 5);
    int ans = 0;
    memset(be, -1, sizeof be);
    for(auto u : spec) {
        int a = di[0][u], b = di[1][u];
        int lo = 1, hi = n;
        while(lo < hi) {
            int mi = (lo + hi + 1)/2;
            int x = tree.qry(max(mi - b - 1, 0), n + 5);
            if(x != -1 && x >= mi - a - 1)
                lo = mi;
            else
                hi = mi - 1;
        }
        ans = max(ans, lo);
        if(b > be[a]) {
            tree.upd(a, b);
            be[a] = b;
        }
    }
    cout << min(ans, di[0][n]) << '\n';
}