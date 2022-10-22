#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k, n, m;
    cin >> k >> n >> m;

    vector <int> a(n), b(m);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> b[j];
    }
    vector <int> res;
    int i = 0, j = 0;
    while (i < n || j < m) {
        if (i < n && (!a[i] || a[i] <= k)) {
            k += (a[i] == 0);
            res.push_back(a[i++]);
            continue;
        }
        if (j < m && (!b[j] || b[j] <= k)) {
            k += (b[j] == 0);
            res.push_back(b[j++]);
            continue;
        }
        cout << "-1\n";
        return;
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}