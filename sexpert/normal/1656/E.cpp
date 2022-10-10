#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
vector<int> adj[MAXN];
int deg[MAXN], co[MAXN];

void dfs(int s, int c, int p = 0) {
    co[s] = c;
    for(auto v : adj[s])
        if(v != p)
            dfs(v, c^1, s);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << (co[i] ? deg[i] : -deg[i]) << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}