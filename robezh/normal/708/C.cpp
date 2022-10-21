#include <bits/stdc++.h>
using namespace std;

const int N = 400050;
int sub[N];
int res[N];

int n;
vector<int> G[N];

int dfs1(int v, int p){
    sub[v] = 1;
    for(int nxt : G[v])
        if(nxt != p)
            sub[v] += dfs1(nxt, v);
    return sub[v];
}

int dfs2(int v, int p, int nn){
    for(int nxt : G[v]){
        if(nxt != p && sub[nxt] > nn/2) return dfs2(nxt, v, nn);
    }
    return v;
}

int solve(int v, int p, int dec) {
    int cur = n - sub[v] - dec;
    res[v] = cur <= n / 2;
    for(int nxt : G[v]) {
        if(nxt != p) solve(nxt, v, dec);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(0, -1);
    int centroid = dfs2(0, -1, sub[0]);
    dfs1(centroid, -1);
    int mx[2] = {0, 0};
    for(int nxt : G[centroid]) {
        int x = sub[nxt];
        for(int i = 0; i < 2; i++) if(x > mx[i]) swap(mx[i], x);
    }
    res[centroid] = 1;
    for(int nxt : G[centroid]) {
        int dec = (mx[0] == sub[nxt] ? mx[1] : mx[0]);
        if(n - sub[nxt] <= n / 2) dec = max(dec, n - sub[nxt]);
        solve(nxt, centroid, dec);
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";
}