#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;
vector<ll> h, p, reach, bad;
bool good = true;

void dfs1(int s = 1, int par = 0) {
    reach[s] = p[s];
    for(auto v : adj[s])
        if(v != par) {
            dfs1(v, s);
            reach[s] += reach[v];
        }
}

void dfs2(int s = 1, int par = 0) {
    // G + B = reach, G - B = h, B = (reach - h)/2
    ll ass = reach[s] - h[s];
    if(ass % 2 || ass < 0 || ass > 2LL * reach[s]) {
        good = false;
        return;
    }
    ass /= 2;
    bad[s] = ass;
    ll su = 0;
    for(auto v : adj[s]) {
        if(v != par) {
            dfs2(v, s);
            su += bad[v];
        }
    }
    if(su + p[s] < bad[s]) {
        good = false;
        return;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    h.resize(n + 1);
    p.resize(n + 1);
    reach.assign(n + 1, 0);
    bad.assign(n + 1, 0);
    adj.assign(n + 1, vector<int>());
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1();
    good = true;
    //for(int i = 1; i <= n; i++)
    //    cout << reach[i] << " ";
    //cout << '\n';
    dfs2();
    //for(int i = 1; i <= n; i++)
    //    cout << bad[i] << " ";
    //cout << '\n';
    cout << (good ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}