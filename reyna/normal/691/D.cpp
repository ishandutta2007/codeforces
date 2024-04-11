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

int mark[N], res[N], p[N];
vector<int> comp, adj[N];

void dfs(int v) {
    if (mark[v]++)
        return;
    for (int u : adj[v])
        dfs(u);
    comp.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) if (!mark[i]) {
        dfs(i);
        vector<int> val;
        for (auto x : comp)
            val.push_back(p[x]);
        sort(comp.begin(), comp.end());
        sort(val.begin(), val.end());
        reverse(val.begin(), val.end());
        for (int j = 0; j < (int) val.size(); ++j)
            res[comp[j]] = val[j];
        comp.clear();
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << ' ';



}