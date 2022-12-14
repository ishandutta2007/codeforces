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

const int N = (int) 1e5 + 5, mod = 0;

vector<int> adj[N];
int col[N];

void dfs(int v, int c = 1) {
    if (col[v] && col[v] != c) {
        cout << -1 << endl;
        exit(0);
    }
    if (col[v]) return;
    col[v] = c;
    for (int u : adj[v])
        dfs(u, 3 - c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int e = 0; e < m; ++e) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
        if (!col[i])
            dfs(i);
    int part = 0;
    for (int i = 0; i < n; ++i) {
        part += (col[i] == 1);
    }
    cout << part << '\n';
    for (int i = 0; i < n; ++i)
        if (col[i] == 1)
            cout << i + 1 << ' ';
    cout << '\n';
    cout << n - part << '\n';
    for (int i = 0; i < n; ++i)
        if (col[i] == 2)
            cout << i + 1 << ' ';
    cout << '\n';
}