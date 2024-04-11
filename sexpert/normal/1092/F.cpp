#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 3;
ll treewt[MAXN], wt[MAXN], mx, initial;
vector<int> adj[MAXN];

ll dfs(int s, int p = 0) {
    treewt[s] = wt[s];
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        treewt[s] += dfs(v, s);
    }
    if(p != 0)
        initial += treewt[s];
    return treewt[s];
}

void findmax(int s, int p = 0, ll cur = initial) {
    ll val = cur;
    if(p != 0)
        val += treewt[1] - 2*treewt[s];
    mx = max(mx, val);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        findmax(v, s, val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> wt[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    findmax(1);
    cout << mx << endl;
}