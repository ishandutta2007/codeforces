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

const int N = (int) 1e5 + 5, mod = (int) 0;
vector<int> adj[N];
int n, res[N], sz[N], pfen[N], mfen[N];
void dfs_sack(int, int);
void dfs_init(int v, int p = -1) {
    sz[v] = 1;
    for (int u : adj[v])
        dfs_init(u, v), sz[v] += sz[u];
}

void update(int fen[N], int m, int x) { m++;
    while (m < N)
        fen[m] += x, m += m & -m;
}
int query(int m, int fen[N]) { m++;
    int res = 0;
    while (m > 0)
        res += fen[m], m -= m & -m;
    return res;
}
vector<int> plist;
void call(int u, int v) {
    plist.push_back(v);
    update(pfen, sz[v], -1);
    dfs_sack(u, v);
    update(pfen, sz[v], 1);
    plist.pop_back();
}
void dfs_clear(int v, int p = -1) {
    update(pfen, sz[v], 1);
    update(mfen, sz[v], -1);
    for (int u : adj[v])
        dfs_clear(u, v);
}
void dfs_add(int v, int z = 0, int p = -1) {
    if (!z) update(pfen, sz[v], -1);
    if (z) update(mfen, sz[v], 1);
    for (int u : adj[v])
        dfs_add(u, z, v);
}
void dfs_sack(int v, int p = -1) {
    int ind = -1, mn = 1e9, mx0 = -1e9, mx1 = -1e9;
    for (int u : adj[v]) {
        mn = min(mn, sz[u]);
        if (mx0 < sz[u])
            mx1 = mx0, mx0 = sz[u];
        else if (mx1 < sz[u])
            mx1 = sz[u];
        if (ind == -1 || sz[u] > sz[ind]) {
            ind = u;
        }
    }
    if (ind == -1) {
        res[v] = n - 1;
        update(pfen, sz[v], -1);
        update(mfen, sz[v], 1);
        return;
    }
    if (p != -1) mn = min(mn, n - sz[v]);
    if (p != -1) {
        if (mx0 < n - sz[v])
            mx1 = mx0, mx0 = n - sz[v];
        else if (mx1 < n - sz[v])
            mx1 = n - sz[v];
    }
    for (int u : adj[v]) if (u != ind) {
        call(u, v);
        dfs_clear(u, v);
    }
    call(ind, v);
    for (int u : adj[v]) if (u != ind) {
        dfs_add(u, 0, v);
    }
    update(pfen, sz[v], -1);
    int bl = mn - 1, br = 1e5 + 1;
    while (bl < br - 1) {
        int lim = bl + br >> 1;
        int ok = 1;
        int most_use = lim - mn;
        int less_use = mx0 - lim;
        if (less_use > most_use) {
            bl = lim;
        } else if (mx0 == n - sz[v]) {           
            if (query(most_use, pfen) - query(less_use - 1, pfen) > 0) {
                br = lim;
                ok = 1;
            } else {
                ok = 0;
            }
            if (ok) continue;
            int pl = -1, pr = (int) plist.size();
            while (pl < pr - 1) {
                int pm = pl + pr >> 1;
                if (sz[plist[pm]] - sz[v] >= less_use) {
                    pl = pm;
                } else {
                    pr = pm;
                }
            }
            if (pl != -1 && sz[plist[pl]] - sz[v] <= most_use) {
                br = lim;
            } else {
                bl = lim;
            }
        } else {
            if (query(most_use, mfen) - query(less_use - 1, mfen) > 0) {
                br = lim;
            } else {
                bl = lim;
            }
        }
    }
    for (int u : adj[v]) if (u != ind) {
        dfs_add(u, 1, v);
    }
    res[v] = max(mx1, br);
    res[v] = min(res[v], mx0);
    if (p == -1 && adj[v].size() == 1) res[v] = n - 1;
    update(mfen, sz[v], 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int root = 0;
    for (int j = 0; j < n; ++j) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if (u == -1) {
            root = v;
        } else {
            adj[u].push_back(v);
        }
    }
    dfs_init(root);
    for (int j = 0; j < n; ++j)
        update(pfen, sz[j], 1);
    dfs_sack(root);
    for (int j = 0; j < n; ++j)
        cout << res[j] << ' ';
}