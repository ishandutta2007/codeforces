#include <bits/stdc++.h>
using namespace std;

int c[2000], subsize[2000], ret[2000];
vector<int> adj[2000], order[2000];

void add(vector<int> &a, vector<int> &b) {
    for (int i : b)
        a.push_back(i);
}

void dfs(int u) {
    subsize[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        subsize[u] += subsize[v];
        add(order[u], order[v]);
    }
    if (c[u] > subsize[u] - 1) {
        cout << "NO\n";
        exit(0);
    }
    order[u].insert(order[u].begin() + c[u], u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, root;
    cin >> n;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p >> c[i];
        if (p != 0)
            adj[p-1].push_back(i);
        else
            root = i;
    }

    dfs(root);

    cout << "YES\n";
    for (int i=0; i<n; i++)
        ret[order[root][i]] = i + 1;
    for (int i=0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}