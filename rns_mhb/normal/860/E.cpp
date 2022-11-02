#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, root;
    cin >> n;
    vector <vector <int> > f(n+1, vector<int>(20,0));
    vector <vector <int> > adj(n+1), g(n);
    vector <int> d(n+1, 0);
    for(int i = 1, x; i <= n; i ++) {
        cin >> x;
        if(!x) root = i, f[i][0] = i;
        else f[i][0] = x, adj[x].push_back(i);
    }
    function <void(int)> dfs = [&](int x) {
        g[d[x]].push_back(x);
        for(auto y : adj[x]) d[y] = d[x]+1, dfs(y);
    };
    dfs(root);
    for(int i = 1; i < 20; i ++) for(int j = 1; j <= n; j ++) f[j][i] = f[f[j][i-1]][i-1];
    auto lca = [&] (int x, int y) {
        for(int i = 19; i >= 0; i --) if(f[x][i] != f[y][i]) x=f[x][i], y=f[y][i];
        return f[x][0];
    };
    vector <long long> ans(n+1, 0);
    vector <int> q(n+1), b(n+1), c(n+1);
    auto solve = [&] (int k) {
        long long sum = 0;
        int m = 1;
        q[1] = g[k][0];
        b[1] = c[1] = 0;
        for(int i = 0; i < g[k].size(); i ++) {
            int x = g[k][i];
            for(;; m --) {
                int y = lca(q[m], x);
                if(b[m] <= d[y]) {
                    q[++ m] = x;
                    b[m] = d[y] + 1;
                    c[m] = i;
                    break;
                }
                sum -= 1ll*(c[m]-c[m-1]) * b[m];
            }
            sum += 1ll * (c[m]-c[m-1]) * b[m];
            ans[x] += sum;
        }
    };
    for(int i = 1; i < n && g[i].size(); i ++) {
        for(auto x : g[i]) ans[x] = ans[f[x][0]] + i;
        solve(i);
        reverse(g[i].begin(), g[i].end());
        solve(i);
    }
    for(int i = 1; i <= n; i ++) cout << ans[i] << ' ';
    cout << endl;
}