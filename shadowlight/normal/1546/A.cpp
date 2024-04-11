#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> b(n);

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    int sum2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum2 += b[i];
    }
    if (sum != sum2) {
        cout << "-1\n";
        return;
    }

    vector <pair <int, int>> res;
    for (int i = 0; i < n; ++i) {
        while (a[i] != b[i]) {
            for (int j = 0; j < n; ++j) {
                if (a[j] == b[j]) continue;
                if ((a[i] > b[i]) != (a[j] > b[j])) {
                    if (a[i] < b[i]) {
                        ++a[i], --a[j];
                        res.push_back({j, i});
                    } else {
                        --a[i], ++a[j];
                        res.push_back({i, j});
                    }
                    break;
                }
            }
        }
    }
    cout << res.size() << "\n";
    for (auto [i, j] : res) {
        cout << i + 1 << " " << j + 1 << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
}