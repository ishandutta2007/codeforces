#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN = 2e5 + 10;
int md, mv, ond[MAXN], deg[MAXN];
vector<int> pa, di, di2, diam, adj[MAXN];
array<int, 2> ex;

void dfs(int s, int p, vector<int> &par, vector<int> &dis) {
    par[s] = p;
    dis[s] = p ? dis[p] + 1 : 0;
    if(dis[s] > md) {
        md = dis[s];
        mv = s;
    }
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s, par, dis);
}

void get_diam() {
    dfs(1, 0, pa, di);
    int u = mv;
    md = 0;
    dfs(u, 0, pa, di);
    int v = mv;
    ex = {u, v};
    do {
        diam.push_back(v);
        ond[v] = 1;
        v = pa[v];
    } while(v != u);
    diam.push_back(u);
    ond[u] = 1;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    di.resize(n + 1);
    di2.resize(n + 1);
    pa.resize(n + 1);
    get_diam();
    dfs(ex[1], 0, pa, di2);
    vector<int> rem;
    for(int u = 1; u <= n; u++) {
        if(!ond[u] && deg[u] == 1)
            rem.push_back(u);
    }
    ll res = 0;
    vector<array<int, 3>> ans;
    while(rem.size()) {
        int u = rem.back(); rem.pop_back();
        int d0 = di[u], d1 = di2[u];
        if(d0 >= d1) {
            res += d0;
            ans.push_back({ex[0], u, u});
        }
        else {
            res += d1;
            ans.push_back({ex[1], u, u});
        }
        for(auto v : adj[u]) {
            deg[v]--;
            if(!ond[v] && deg[v] == 1)
                rem.push_back(v);
        }
    }
    for(int i = 0; i + 1 < diam.size(); i++) {
        res += i + 1;
        ans.push_back({diam[i], ex[0], diam[i]});
    }
    cout << res << '\n';
    for(auto a : ans)
        cout << a[0] << " " << a[1] << " " << a[2] << '\n';
}