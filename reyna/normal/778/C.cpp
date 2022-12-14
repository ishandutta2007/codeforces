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

const int N = (int) 1e6 + 6, mod = (int) 0;
vector<pair<int, char>> adj[N];
int nxt[N][26];
int n, cnt, sz[N], h[N], res[N];
void dfs_fix(int v, int p = -1) {
    sz[v] = 1;
    for (auto e : adj[v]) {
        int u = e.first;
        char c = e.second;
        if (u != p) {
            h[u] = h[v] + 1;
            nxt[v][c - 'a'] = u;
            dfs_fix(u, v);      
            sz[v] += sz[u];
        }
    }
}
int same = 0;
int make_new(int v) {
    int u = cnt++;
    memcpy(nxt[u], nxt[v], sizeof nxt[v]);
    return u;
}
int add_trie(int root, int cur) {
    int v = make_new(root);
    same++;
    for (int c = 0; c < 26; ++c) {
        if (nxt[v][c] && nxt[cur][c]) {
            nxt[v][c] = add_trie(nxt[v][c], nxt[cur][c]);
        } else if (nxt[cur][c]) {
            int nw = cnt++;
            memset(nxt[nw], 0, sizeof nxt[nw]);
            same--;
            nxt[v][c] = add_trie(nw, nxt[cur][c]);
        }
    }
    return v;
}
void dfs_res(int v, int p = -1) {
    int mx = -1;
    for (int c = 0; c < 26; ++c) {
        if (nxt[v][c]) {
            int u = nxt[v][c];
            if (mx == -1 || sz[mx] < sz[u])
                mx = u;
            dfs_res(u, v);
        }
    }
    if (mx == -1) return;
    same = 0;
    cnt = n;
    int root = mx;
    for (int c = 0; c < 26; ++c) {
        if (nxt[v][c] && nxt[v][c] != mx) {
            root = add_trie(root, nxt[v][c]);
        }
    }
    res[h[v]] += same + 1;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int j = 1; j < n; ++j) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        --u, --v;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    dfs_fix(0);
    dfs_res(0);
    int pos = -1, mx = 0;
    for (int j = 0; j <= n; ++j)
        if (res[j] != 0) {
            if (pos == -1 || mx < res[j]) {
                pos = j;
                mx = res[j];
            }
        }
    cout << n - mx << '\n' << pos + 1 << '\n';
}