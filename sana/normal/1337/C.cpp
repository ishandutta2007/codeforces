#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

vector<long long> val;

long long dfs(int v, int p, int d, vector<vector<int>> &g) {
    long long subtreeSize = 1;
    for (int x : g[v]) if (x != p) {
        subtreeSize += dfs(x,v,d+1,g);
    }
    val.push_back(d - subtreeSize);
    return subtreeSize;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,k; cin >> n >> k;
    vector< vector<int> > g(n);

    for (int i = 0; i < n-1; i++) {
        int u,v; cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    dfs(0, -1, 0, g);
    sort(val.begin(), val.end());
    long long answer = 0;
    for (int i = n-1; i > n-1-k; i--) answer += val[i];

    cout << answer+k << '\n';
    return 0;
}