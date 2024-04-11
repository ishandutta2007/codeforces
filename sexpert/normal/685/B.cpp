#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5 + 5;
const int LOG = 20;
int tree[MAXN], heavy[MAXN][LOG];
vector<int> adj[MAXN];

void dfs(int s) {
    int mx = 0;
    tree[s] = 1;
    for(auto v : adj[s]) {
        dfs(v);
        tree[s] += tree[v];
        if(tree[v] > mx) {
            mx = tree[v];
            heavy[s][0] = v;
        }
    }
}

int qry(int s) {
    int sz = tree[s];
    for(int l = LOG - 1; l >= 0; l--) {
        if(tree[heavy[s][l]] > sz/2)
            s = heavy[s][l];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }
    dfs(1);
    for(int l = 1; l < LOG; l++) {
        for(int v = 1; v <= n; v++) {
            heavy[v][l] = heavy[heavy[v][l - 1]][l - 1];
        }
    }
    while(q--) {
        int r;
        cin >> r;
        cout << qry(r) << '\n';
    }
}