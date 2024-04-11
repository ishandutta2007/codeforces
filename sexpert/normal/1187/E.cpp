#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int sz[MAXN], big;
ll ans[MAXN], res;

void dfs(int s, int p = 0) {
    sz[s] = 1;
    for(auto v : adj[s]) {
        if(v == p) continue;
        dfs(v, s);
        sz[s] += sz[v];
        ans[s] += ans[v];
    }
    ans[s] += sz[s];
}

void calc(int s, ll cur, int p = 0) {
    res = max(res, cur);
    for(auto v : adj[s]) {
        if(v == p) continue;
        calc(v, cur + (big - 2*sz[v]), s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    res = ans[1];
    big = sz[1];
    calc(1, res);
    cout << res << endl;
}