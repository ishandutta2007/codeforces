#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

const int N = 1e5 + 13;

vector<int> g[N];

int dp[N], dp1[N];
bool b[N];

void dfs(int v, int p) {
//    cout << v << endl;
    dp[v] = (b[v] ? 0 : -1e9);
    for(auto u : g[v]) {
        if(p != u) {
            dfs(u, v);
            if(dp[u] != -1)
                dp[v] = max(dp[v], dp[u] + 1);
        }
    }

//    cout << v << ' ' << dp[v] << endl;
}

int ans = 0, d;

void dfs2(int v, int p) {
//    cout << v << ' ' << dp1[v] << ' ' << dp[v] << endl;
    int mx1 = -1e9, mx2 = -1e9;
    ans += (dp[v] <= d && dp1[v] <= d);
    for(auto u : g[v])
        if(u != p) {
            if(dp[u] > mx1) {
                mx2 = mx1;
                mx1 = dp[u];
            } else if(dp[u] > mx2) {
                mx2 = dp[u];
            }
        }

    for(auto u : g[v]) {
        if(u != p) {
//            cout << u << ' ' << dp[u] << ' ' << mx1 << ' ' << mx2 << endl;
            if(dp[u] > mx2) {
                dp1[u] = max(b[v] ? 1 : -1000000000, max(dp1[v] + 1, mx2 + 2));
            } else
                dp1[u] = max(b[v] ? 1 : -1000000000, max(dp1[v] + 1, mx1 + 2));

            dfs2(u, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m >> d;

    for(int i = 0; i < m; i++) {
        int p;
        cin >> p;

        b[p - 1] = true;
    }

    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;

        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    dfs(0, -1);
    dp1[0] = -1e9;
//    cout << endl;
    dfs2(0, -1);
    cout << ans;
}