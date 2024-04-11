#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ul = unsigned long long;
using ld = long double;

const int N = 200001;
vector<int> g[N];
ll dp[N][2], ans = 1e18;
ll t[N], h[N];

void dfs(int v, int p) {
    ll cs = t[v] * g[v].size(), ci = 0;
    vector<ll> di;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        if (h[u] < h[v]) {
            cs += dp[u][0];
            ci++;
        }
        else if (h[u] > h[v]) {
            cs += dp[u][1];
            ci--;
        }
        else {
            cs += dp[u][0];
            ci++;
            di.push_back(dp[u][1] - dp[u][0]);
        }
    }
    sort(rall(di));
    dp[v][0] = dp[v][1] = 1e18;
    while (1) {
        if (v == 0) {
            ans = min(ans, cs + t[v] * abs(ci));
        }
        if (ci == 0) {
            dp[v][0] = min(dp[v][0], cs + t[v]);
            dp[v][1] = min(dp[v][1], cs + t[v]);
        }
        else if (ci > 0) {
            dp[v][0] = min(dp[v][0], cs + t[v] * (ci - 1));
            dp[v][1] = min(dp[v][1], cs + t[v] * (ci + 1));
        }
        else {
            dp[v][0] = min(dp[v][0], cs + t[v] * (-ci + 1));
            dp[v][1] = min(dp[v][1], cs + t[v] * (-ci - 1));
        }
        if (di.empty())
            break;
        ci -= 2;
        cs += di.back();
        di.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, u, v;
    cin >> n;
    rep(i, n)
        cin >> t[i];
    rep(i, n)
        cin >> h[i];
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans / 2;
}