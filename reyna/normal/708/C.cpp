// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; ++i)

const int N = (int) 1e6 + 6, mod = 0;
int sz[N], n, par[N], up[N], dw[N];
vector<int> adj[N];

void dfs_sz(int v, int p = -1) {
    par[v] = p;
    sz[v] = 1;
    for (int u : adj[v])
        if (u != p)
            dfs_sz(u, v), sz[v] += sz[u];
}

void dfs_down(int v, int p = -1) {
    dw[v] = (sz[v] <= n / 2? sz[v]: 0);
    for (int u : adj[v])
        if (u != p)
            dfs_down(u, v), dw[v] = max(dw[v], dw[u]);
}

void dfs_up(int v, int val = 0, int p = -1) {
    up[v] = max((n - sz[v] <= n / 2? n - sz[v]: 0), val);
    int mx0 = 0, mx1 = 0;
    for (int u : adj[v])
        if (u != p) {
            if (dw[u] >= mx0)
                mx1 = mx0, mx0 = dw[u];
            else if (dw[u] >= mx1)
                mx1 = dw[u];
        }
    for (int u : adj[v])
        if (u != p) {
            dfs_up(u, max(up[v], mx0 == dw[u]? mx1: mx0), v);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(0);
    dfs_down(0);
    dfs_up(0);
    for (int v = 0; v < n; ++v) {
        int flag = 1;
        for (int u : adj[v]) {
            if (u == par[v]) {
                if (n - sz[v] - up[v] > n / 2)
                    flag = 0;
            } else {
                if (sz[u] - dw[u] > n / 2)
                    flag = 0;
            }
        }
        cout << flag << ' ';
    }





}