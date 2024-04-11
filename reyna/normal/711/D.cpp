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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 1e9 + 7;
int pw(int a, int b) { return b != 0? pw(a * a % mod, b >> 1) * (b & 1? a: 1) % mod: 1; }
int mark[N], h[N], sz[N], f[N];
vector<int> adj[N];
int dfs(int v, int ep = -1) {
    sz[v] = 1;
    int res = 0;
    for (int e : adj[v]) {
        int u = f[e] ^ v ^ e;
        if (e != ep) {
            if (!mark[u]++) {
                h[u] = h[v] + 1;
                res = max(res, dfs(u, e));
                sz[v] += sz[u];
            } else {
                res = max(res, abs(h[u] - h[v]) + 1);
            }
        }
    }
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int res = 1;
    for (int i = 0; i < n; ++i) {
        int &j = f[i];
        cin >> j; --j;
        adj[i].push_back(i);
        adj[j].push_back(i);
    }
    for (int v = 0; v < n; ++v) 
        if (!mark[v]) {
            mark[v] = 1;
            int x = dfs(v);
            res = res * pw(2, (sz[v] - x)) % mod * ((pw(2, x) - 2 + mod) % mod) % mod;
        }
    cout << res;




}