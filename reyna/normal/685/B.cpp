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

const int N = (int) 5e5 + 5, L = 20, mod = 0;

int n, q, par[N], h[N], sz[N], anc[N][L], res[N];
vector<int> adj[N];

void init(int v) {
    sz[v] = 1;
    for (int u : adj[v])
        init(u), sz[v] += sz[u];
}

void dfs(int v, int p = 0) {
    anc[v][0] = par[v];
    h[v] = h[p] + 1;
    for (int i = 1; i < L; ++i)
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    for (int u : adj[v])
        dfs(u, v);
    int u = v;
    p = v;
    for (int i = L - 1; i >= 0; --i)
        if (sz[v] * 2 >= sz[anc[p][i]])
            p = anc[p][i];
    if (sz[v] * 2 >= n)
        p = 0;
    for (int i = L - 1; i >= 0; --i)
        if (h[anc[u][i]] >= h[p] && res[anc[u][i]])
            u = anc[u][i];
    if (res[u])
        u = anc[u][0];
/*    p = u;
    for (int i = L - 1; i >= 0; --i)
        if (sz[v] * 2 <= sz[anc[p][i]])
            p = anc[p][i]; */
//    cout << " hi " << v << ' ' << u << ' ' << p << ' ' << sz[v] << endl;
    while (!res[u] && sz[v] * 2 >= sz[u]) {
 //       cout << v << ' ' << u << endl;
        res[u] = v + 1;
        if (u == 0) break;
        u = par[u];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        cin >> par[i];
        par[i]--;
        adj[par[i]].push_back(i);
    }
    init(0);
    dfs(0);
   while (q--) {
        int v;
        cin >> v;
        v--;
        cout << res[v] << '\n';
   }




}