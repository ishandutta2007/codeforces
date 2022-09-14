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

const int N = 100001;
vector<int> g[N], li[N];
int d0[N], d1[N], mv[N], f[N], num[N], ans[N];

void dfs(int v, int p) {
    mv[v] = -1;
    for (int u : g[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        d1[v] += min(d1[u], d0[u]);
        if (d1[u] < d0[u])
            f[v] = 1;
        if (!f[v] && (mv[v] == -1 || d1[u] - d0[u] < d1[mv[v]] - d0[mv[v]]))
            mv[v] = u;
    }
    d0[v] = d1[v];
    if (!f[v]) {
        if (mv[v] == -1)
            d0[v] = N;
        else
            d0[v] += d1[mv[v]] - d0[mv[v]];
    }
    else
        mv[v] = -1;
    d1[v]++;
}

void rec(int v, int ip, int p) {
    if (ip)
        num[v] = num[p];
    else
        num[v] = v;
    li[num[v]].push_back(v);
    for (int u : g[v])
        if (u != p)
            rec(u, d1[u] < d0[u] || !ip && mv[v] == u, v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, u, v;
    cin >> n;
    rep(i, n - 1) {
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    cout << d0[0] * 2 << '\n';
    rec(0, 0, -1);
    rep(i, n)
        rep(j, li[i].size())
            ans[li[i][j]] = li[i][(j + 1) % li[i].size()];
    rep(i, n)
        cout << ans[i] + 1 << ' ';
}