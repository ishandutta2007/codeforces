#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN], ts;
vector<pair<int, int>> edg;
int ps[MAXN], id[MAXN];
bool good;

void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        id[i] = 0;
        ps[i] = -1;
    }
    edg.clear();
    ts.clear();
    
    for(int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        edg.push_back({u, v});
        if(t == 1) {
            adj[u].push_back(v);
            id[v]++;
        }
    }
    
    queue<int> ready;
    for(int i = 1; i <= n; i++) {
        if(!id[i]) {
            ready.push(i);
        }
    }
    while(ready.size()) {
        int u = ready.front(); ready.pop();
        ps[u] = ts.size();
        ts.push_back(u);
        for(auto v : adj[u]) {
            id[v]--;
            if(id[v] == 0)
                ready.push(v);
        }
    }
    if(ts.size() < n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto& [u, v] : edg) {
        if(ps[u] < ps[v])
            cout << u << " " << v << '\n';
        else
            cout << v << " " << u << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}