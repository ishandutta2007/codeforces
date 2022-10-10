#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> adj[100000];
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    for (int i=0; i<n; i++)
        if (adj[i].size() == 2) {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;

    return 0;
}