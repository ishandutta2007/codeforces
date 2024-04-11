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

const int N = 200001, L = 19, MOD = 998244353;
vector<int> g[N][2];
int r[N][2], d[N][2], d2[L][N];

ll pw(ll x, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1)
            r = r * x % MOD;
        x = x * x % MOD;
        k >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    rep(i, m) {
        cin >> u >> v;
        u--; v--;
        g[u][0].push_back(v);
        g[v][1].push_back(u);
    }
    rep(i, n)
        r[i][0] = d[i][0] = r[i][1] = d[i][1] = N;
    r[0][0] = 0;
    d[0][0] = 0;
    set<vector<int>> q;
    q.insert({0, 0, 0});
    while (!q.empty()) {
        int v = (*q.begin())[2], t = (*q.begin())[0] % 2, tt = t ^ 1;
        // cout << v << ' ' << d[v][t] << '\n';
        q.erase(q.begin());
        for (int u : g[v][t])
            if (r[u][t] > r[v][t] || r[u][t] == r[v][t] && d[u][t] > d[v][t] + 1) {
                q.erase({r[u][t], d[u][t], u});
                r[u][t] = r[v][t];
                d[u][t] = d[v][t] + 1;
                q.insert({r[u][t], d[u][t], u});
            }
        for (int u : g[v][tt])
            if (r[u][tt] > r[v][t] + 1 || r[u][tt] == r[v][t] + 1 && d[u][tt] > d[v][t] + 1) {
                q.erase({r[u][tt], d[u][tt], u});
                r[u][tt] = r[v][t] + 1;
                d[u][tt] = d[v][t] + 1;
                q.insert({r[u][tt], d[u][tt], u});
            }
    }
    if (r[n - 1][0] >= L && r[n - 1][1] >= L) {
        if (r[n - 1][0] < r[n - 1][1] || r[n - 1][0] == r[n - 1][1] && d[n - 1][0] < d[n - 1][1])
            cout << (pw(2, r[n - 1][0]) + d[n - 1][0] - 1) % MOD;
        else
            cout << (pw(2, r[n - 1][1]) + d[n - 1][1] - 1) % MOD;
        return 0;
    }
    rep(i, L)
        rep(j, n)
            d2[i][j] = MOD;
    d2[0][0] = 0;
    queue<pair<int, int>> qq;
    qq.push({0, 0});
    while (!qq.empty()) {
        int cr = qq.front().first;
        v = qq.front().second;
        qq.pop();
        int t = cr % 2, tt = t ^ 1;
        for (int u : g[v][t])
            if (d2[cr][u] == MOD) {
                d2[cr][u] = d2[cr][v] + 1;
                qq.push({cr, u});
            }
        if (cr < L - 1)
            for (int u : g[v][tt])
                if (d2[cr + 1][u] == MOD) {
                    d2[cr + 1][u] = d2[cr][v] + 1;
                    qq.push({cr + 1, u});
                }
    }
    int ans = MOD;
    rep(i, L)
        if (d2[i][n - 1] < MOD)
            ans = min(ans, (1 << i) - 1 + d2[i][n - 1]);
    cout << ans;
}