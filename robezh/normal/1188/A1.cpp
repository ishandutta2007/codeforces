#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 50;

int n;
vector<int> G[N];

int main() {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        if(G[i].size() == 2) return cout << "NO" << endl, 0;
    }
    return cout << "YES" << endl, 0;
}