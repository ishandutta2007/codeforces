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
vector<int> all[N], adj[N];
int p[N], mark[N], es[N], et[N];
void dfs(int v, int col = 1) {
    if (mark[v]) {
        if (mark[v] != col) {
            cout << "NO\n";
            exit(0);
        }
        return;
    }
    mark[v] = col;
    for (int e : adj[v]) {
        int u = es[e] ^ et[e] ^ v;
        int nx = ((col - 1) ^ p[e] ^ 1) + 1;
        dfs(u, nx);
    }
}
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    for (int j = 0; j < m; ++j)
        cin >> p[j];
    for (int j = 0; j < n; ++j) {
        int k;
        cin >> k;
        while (k--) {
            int e;
            cin >> e;
            e--;
            all[e].push_back(j);
            adj[j].push_back(e);    
        }
    }
    for (int j = 0; j < m; ++j) {
        if (all[j].size() < 2) continue;
        es[j] = all[j][0], et[j] = all[j][1];
    }
    for (int j = 0; j < n; ++j)
        if (!mark[j]) {
            dfs(j);
        }
    cout << "YES\n";
}