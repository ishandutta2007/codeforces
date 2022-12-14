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
const int N = (int) 2e5 + 5, mod = 0;
int n, k, cnt[N], sz[N];
vector<int> adj[N];
int dfs(int v, int p = -1) {
    sz[v] = cnt[v];
    int res = 0;
    for (int u : adj[v])
        if (u != p)
            res += dfs(u, v), sz[v] += sz[u];
    return res + min(sz[v], 2 * k - sz[v]);
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < 2 * k; ++i) {
        int p;
        cin >> p;
        --p;
        cnt[p]++;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(0) << endl;


}