#include <bits/stdc++.h>
using namespace std;

int a[100000];
vector<pair<int, int>> adj[100000];

pair<int, int> dfs(int u, long long d) {
    // p.first -> number of leaves to remove
    // p.second -> subtree size
    pair<int, int> ret = {0, 1};
    for (auto e : adj[u]) {
        auto p = dfs(e.first, max(0LL, d) + e.second);
        ret.first += p.first;
        ret.second += p.second;
    }
    if (d > a[u])
        ret.first = ret.second;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];
    for (int i=1; i<n; i++) {
        int p, c;
        cin >> p >> c;
        adj[p-1].emplace_back(i, c);
    }

    cout << dfs(0, 0).first << "\n";

    return 0;
}