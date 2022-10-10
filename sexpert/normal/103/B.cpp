#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
int vist[MAXN];
vector<int> adj[MAXN];

void dfs(int s) {
    vist[s] = 1;
    for(auto v : adj[s]) {
        if(!vist[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(m != n) {
        cout << "NO\n";
        return 0;
    }
    dfs(1);
    for(int v = 1; v <= n; v++) {
        if(!vist[v]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "FHTAGN!\n";
}