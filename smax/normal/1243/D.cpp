#include <bits/stdc++.h>
using namespace std;

set<int> nodes;
unordered_set<int> edges[100000];

void dfs(int u) {
    nodes.erase(u);
    int v = 0;
    auto it = nodes.upper_bound(v);
    while (it != nodes.end()) {
        v = *it;
        if (!edges[u].count(v))
            dfs(v);
        it = nodes.upper_bound(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a-1].insert(b-1);
        edges[b-1].insert(a-1);
    }

    for (int i=0; i<n; i++)
        nodes.insert(i);

    int ret = 0;
    for (int i=0; i<n; i++)
        if (nodes.count(i)) {
            ret++;
            dfs(i);
        }

    cout << ret - 1 << "\n";

    return 0;
}