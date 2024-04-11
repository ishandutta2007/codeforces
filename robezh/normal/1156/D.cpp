#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e5 + 50;
typedef long long ll;

struct edge{
    int to, color;
};

int n;
vector<edge> G[N];
int dp[2][N], tdp[2][N];

void dfs(int v, int p) {
    for(const auto &e: G[v]) {
        if(e.to == p) continue;
        dfs(e.to, v);
        dp[e.color][v] += dp[e.color][e.to] + 1;
    }
}

void dfs2(int v, int p, int pd0, int pd1) {
    tdp[0][v] += pd0 + 1 + dp[0][v];
    tdp[1][v] += pd1 + 1 + dp[1][v];
    for(const auto &e : G[v]) {
        if(e.to == p) continue;
        tdp[e.color][v] -= dp[e.color][e.to] + 1;
        if(e.color == 0) dfs2(e.to, v, tdp[0][v], -1);
        else dfs2(e.to, v, -1, tdp[1][v]);
        tdp[e.color][v] += dp[e.color][e.to] + 1;
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--, b--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    dfs(0, -1);
    dfs2(0, -1, -1, -1);

    ll alt = 0, mon = 0;
    
    for(int i = 0; i < n; i++) {
        alt += 1LL * tdp[0][i] * tdp[1][i];
        mon += tdp[0][i] + tdp[1][i];
    }
    cout << alt + mon << endl;
}