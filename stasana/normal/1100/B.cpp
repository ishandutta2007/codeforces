// Megumin top

#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n);
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        --x;
        a[x].emplace_back(i);
    }
    for (int i = 0; i < n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vector<int> result(m);
    for (int i = 0;; ++i) {
        int mx = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j].size() <= i) {
                mx = -1;
                break;
            }
            mx = max(mx, a[j][i]);
        }
        if (mx == -1) {
            break;
        }
        result[mx] = 1;
    }
    for (auto i : result) {
        cout << i;
    }
}

int main() {
    start();
    solve();
    return 0;
}