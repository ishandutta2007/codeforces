#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <utility>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef long double ld;

void dfsda(int v, int cd, vector<int>& dista, const vector<vector<int>>& r) {
    if (dista[v] >= 0) {
        return;
    }
    dista[v] = cd;
    for (int i = 0; i < r[v].size(); ++i) {
        dfsda(r[v][i], cd + 1, dista, r);
    }
}

void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    --a;
    --b;
    vector<vector<int>> r(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        r[u].push_back(v);
        r[v].push_back(u);
    }

    if (db <= da * 2) {
        cout << "Alice\n";
        return;
    }

    vector<int> dista(n, -1);
    dfsda(a, 0, dista, r);
    if (dista[b] <= da) {
        cout << "Alice\n";
        return;
    }

    int mdi = 0;
    int md = 0;
    for (int i = 0; i < n; ++i) {
        if (dista[i] > md) {
            mdi = i;
            md = dista[i];
        }
    }
    vector<int> diam(n, -1);
    dfsda(mdi, 0, diam, r);
    for (int i = 0; i < n; ++i) {
        md = max(md, diam[i]);
    }

    if (md <= da * 2) {
        cout << "Alice\n";
        return;
    }

    cout << "Bob\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int q = 0; q < t; ++q) {
        solve();
    }

    return 0;
}