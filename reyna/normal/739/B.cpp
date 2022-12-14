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
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
vector<pair<int, int>> adj[N];
int a[N], res[N], h[N];
vector<int> par;
int dfs(int v) {
    par.push_back(v);
    int &sum = res[v];
    for (auto e : adj[v]) {
        int u = e.first, w = e.second;
        h[u] = h[v] + w;
        sum += dfs(u);
    }
    int bl = -1, br = (int) par.size();
    while (bl < br - 1) {
        int bm = bl + br >> 1;
        int u = par[bm];
        if (h[v] - h[u] <= a[v]) {
            br = bm;
        } else {
            bl = bm;
        }
    }
    if (bl >= 0) {
        res[par[bl]]--;
    }
    par.pop_back();
    return sum + 1;
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int p, w; cin >> p >> w; --p;
        adj[p].push_back(make_pair(i, w));
    }
    dfs(0);
    for (int i = 0; i < n; ++i)
        cout << res[i] << ' ';
}