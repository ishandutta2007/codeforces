#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> adj(n);
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    
    int id = 0;
    vector<int> vis(n), par(n);
    
    auto dfs = [&] (auto &self, int u) -> void {
        vis[u] = id;
        for (int v : adj[u])
            if (v != s) {
                if (!vis[v]) {
                    par[v] = u;
                    self(self, v);
                } else if (vis[v] != id) {
                    vector<int> a, b;
                    int x = v;
                    while (x != s) {
                        a.push_back(x);
                        x = par[x];
                    }
                    a.push_back(s);
                    x = u;
                    b.push_back(v);
                    while (x != s) {
                        b.push_back(x);
                        x = par[x];
                    }
                    b.push_back(s);
                    reverse(a.begin(), a.end());
                    reverse(b.begin(), b.end());
                    cout << "Possible\n";
                    cout << a.size() << "\n";
                    for (int i=0; i<(int)a.size(); i++)
                        cout << a[i] + 1 << " \n"[i==(int)a.size()-1];
                    cout << b.size() << "\n";
                    for (int i=0; i<(int)b.size(); i++)
                        cout << b[i] + 1 << " \n"[i==(int)b.size()-1];
                    exit(0);
                }
            }
    };
    
    for (int v : adj[s]) {
        if (vis[v]) {
            vector<int> a, b;
            int x = v;
            while (x != s) {
                a.push_back(x);
                x = par[x];
            }
            a.push_back(s);
            b = {v, s};
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            cout << "Possible\n";
            cout << a.size() << "\n";
            for (int i=0; i<(int)a.size(); i++)
                cout << a[i] + 1 << " \n"[i==(int)a.size()-1];
            cout << b.size() << "\n";
            for (int i=0; i<(int)b.size(); i++)
                cout << b[i] + 1 << " \n"[i==(int)b.size()-1];
            exit(0);
        }
        id++;
        par[v] = s;
        dfs(dfs, v);
        // for (int i=0; i<n; i++)
            // cerr << vis[i] << " ";
        // cerr << "\n";
    }
    cout << "Impossible\n";
    
    return 0;
}