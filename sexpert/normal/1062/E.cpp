#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5, MAXL = 25;
int parent[MAXN][MAXL], lcatable[MAXN][MAXL], lv[MAXN];
vector<int> adj[MAXN];

void dfs(int s, int p = 0) {
    lv[s] = (p == 0 ? 0 : lv[p] + 1);
    parent[s][0] = p;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
    }
}

void buildLCA() {
    dfs(1);
    for(int l = 1; l < MAXL; l++) {
        for(int v = 1; v < MAXN; v++) {
            if(parent[v][l - 1] == 0)
                continue;
            parent[v][l] = parent[parent[v][l - 1]][l - 1];
        }
    }
}

int LCA(int u, int v) {
    if(lv[u] < lv[v])
        swap(u, v);
    int diff = lv[u] - lv[v];
    for(int l = MAXL - 1; l >= 0; l--) {
        if(diff >= (1 << l)) {
            diff -= (1 << l);
            u = parent[u][l];
        }
    }
    //cout << "finding lca of " << u << " " << v << endl;
    if(u == v)
        return u;
    for(int l = MAXL - 1; l >= 0; l--) {
        if(parent[u][l] != parent[v][l]) {
            u = parent[u][l];
            v = parent[v][l];
        }
    }
    return parent[u][0];
}

void buildLCAs() {
    // lcatable[n][l] stores LCA(n, n + 1, ..., n + 2^l - 1)
    for(int n = 1; n < MAXN; n++)
        lcatable[n][0] = n;
    for(int l = 1; l < MAXL; l++) {
        int po = 1 << (l - 1);
        for(int n = 1; n + 2*po - 1 < MAXN; n++)
            lcatable[n][l] = LCA(lcatable[n][l - 1], lcatable[n + po][l - 1]);
    }
}

int query(int l, int r) {
    if(l > r)
        return -1;
    int m = r - l + 1, po = 0, p;
    for(p = 24; p >= 0; p--) {
        if(m & (1 << p)) {
            po = (1 << p);
            break;
        }
    }
    //cout << "Calculating LCA as LCA of ranges [" << l << ", " << l + po - 1 << "] and [" << r - po + 1 << ", " << r << "]." << endl;
    //cout << l << " " << p << " " << lcatable[l][p] << endl;
    //cout << r - po + 1 << " " << p << " " << lcatable[r - po + 1][p] << endl;
    int re = LCA(lcatable[l][p], lcatable[r - po + 1][p]);
    //cout << "LCA of range [" << l << ", " << r << "] is " << re << endl;
    return re;
}

void solve(int l, int r) {
    int dlca = query(l, r);
    int ll = l, rr = r;
    while(rr - ll > 2) {
        int m = (ll + rr)/2, llca = query(ll, m), rlca = query(m + 1, rr);
        if(llca == dlca && rlca == dlca) {
            cout << l << " " << lv[dlca] << endl;
            return;
        }
        if(llca != dlca && rlca != dlca) {
            cout << l << " " << lv[dlca] << endl;
            return;
        }
        if(rlca == dlca)
            ll = m + 1;
        else
            rr = m;
    }
    // cout << "range of candidates [" << ll << " " << rr << "]" << endl;
    int rem = l;
    for(int i = ll; i <= rr; i++) {
        int lq = query(l, i - 1), rq = query(i + 1, r), q;
        if(lq == -1)
            q = rq;
        else if(rq == -1)
            q = lq;
        else
            q = LCA(lq, rq);
        if(lv[q] > lv[dlca]) {
            rem = i;
            dlca = q;
        }
    }
    cout << rem << " " << lv[dlca] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    buildLCA();
    buildLCAs();
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        solve(l, r);
    }
}