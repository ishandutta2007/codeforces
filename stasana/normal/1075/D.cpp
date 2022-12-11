// Yunyun loli

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef int64_t ll;

void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    int n1;
    cin >> n1;
    vector<int> a1(n1);
    for (int i = 0; i < n1; ++i) {
        cin >> a1[i];
        --a1[i];
    }
    int n2;
    cin >> n2;
    vector<int> a2(n2);
    for (int i = 0; i < n2; ++i) {
        cin >> a2[i];
        --a2[i];
    }
    vector<int> dist(n, 1e5);
    queue<int> q;
    cout << "B " << a2.back() + 1 << endl;
    int v;
    cin >> v;
    --v;
    q.push(v);
    dist[v] = 0;
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (auto u : tree[v]) {
            if (dist[u] > dist[v] + 1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    v = a1.back();
    for (auto u : a1) {
        if (dist[u] < dist[v]) {
            v = u;
        }
    }
    cout << "A " << v + 1 << endl;
    int u = v;
    cin >> v;
    --v;
    for (auto i : a2) {
        if (i == v) {
            cout << "C " << u + 1 << endl;
            return;
        }
    }
    cout << "C " << -1 << endl;
}

int main() {
    // start();

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}