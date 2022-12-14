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
const int N = (int) 1e7 + 7, mod = (int) 0;
int cur[N], q[N], t;
vector<int> adj[N];
void add(int v) {
    cur[v] ^= 1;
    q[t++] = v;
}

void dfs(int v, int p = 0) {
    add(v);
    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
    for (int u : adj[v])
        if (u != p && cur[u]) {
            add(u);
            add(v);
        }
    if (v) add(p);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> cur[i], cur[i] = (cur[i] == -1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    cur[0] ^= 1;
    dfs(0);
    if (cur[0] == 1) t--;
    for (int i = 0; i < t; ++i)
        cout << q[i] + 1 << ' ';




}