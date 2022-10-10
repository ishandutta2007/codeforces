#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int used[MAXN], cnt = 0;

void dfs(int s, int p = 0) {
    for(auto v : adj[s]) {
        if(v != p)
            dfs(v, s);
    }
    int c0 = 0;
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(!used[v])
            c0++;
    }
    if(c0 >= 2) {
        used[s] = 1;
        cnt += c0 - 1;
    }
    if(s == 1 && c0 <= 1)
        cnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, md = 0;
    ll x, y;
    cin >> n >> x >> y;
    vector<int> deg(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
        md = max(md, deg[u]);
        md = max(md, deg[v]);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(x >= y) {
        if(md < n - 1)
            cout << y * (n - 1) << '\n';
        else
            cout << y * (n - 2) + x << '\n';
        return 0;
    }

    dfs(1);
    cout << y * (cnt - 1) + x * (n - cnt) << '\n';
}