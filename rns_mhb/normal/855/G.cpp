#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector <int> dt(n+1), ft(n+1), sz(n+1), p(n+1), f(n+1), w(n+1, 1);
    vector <long long> v(n+1);
    vector <vector<int> > adj(n+1);
    for(int i = 1, x, y; i < n; i ++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int T = 0;
    function <void(int, int)> dfs = [&](int x, int pa) {
        p[x] = pa, sz[x] = 1, v[x] = 0;
        dt[x] = ++ T;
        for(auto y : adj[x]) {
            if(y == pa) continue;
            dfs(y, x);
            sz[x] += sz[y];
            v[x] += 1ll * sz[y] * (sz[y]-1);
        }
        ft[x] = T;
    };
    dfs(1, 0);
    for(int i = 1; i <= n; i ++) f[i] = i;
    function <int(int)> find_rt = [&](int x) {return x == f[x] ? x : f[x] = find_rt(f[x]);};
    auto val = [&](int x) {return w[x]*(v[x]+1ll*(n-sz[x])*(n-sz[x]-1));};
    long long tot = 1ll * n * (n-1) * (n-2), bad = 0;
    for(int i = 1; i <= n; i ++) bad += val(i);
    cout << tot - bad << endl;
    int q;
    cin >> q;
    while(q --) {
        int x, y;
        cin >> x >> y;
        x = find_rt(x), y = find_rt(y);
        int z = x;
        vector <int> pv;
        while(dt[z] > dt[y] || ft[z] < dt[y]) {
            pv.push_back(z);
            z = find_rt(p[z]);
        }
        while(y != z) {
            pv.push_back(y);
            y = find_rt(p[y]);
        }
        bad -= val(z);
        for(auto u : pv) {
            bad -= val(u);
            f[u] = z;
            w[z] += w[u];
            v[z] += v[u] - 1ll * sz[u] * (sz[u]-1);
        }
        bad += val(z);
        cout << tot - bad << endl;
    }
}