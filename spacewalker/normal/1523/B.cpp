#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    vector<tuple<int, int, int>> ans;
    for (int i = 0; i < n; i += 2) {
        vector<int> MAGIC{1, 2, 1, 1, 2, 1};
        for (int v : MAGIC) {
            ans.emplace_back(v, i, i + 1);
        }
    }
    printf("%lu\n", ans.size());
    for (auto [t, i, j] : ans) printf("%d %d %d\n", t, i + 1, j + 1);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) solve();
}