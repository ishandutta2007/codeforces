#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int max_n = 2000;
    vector<bool> can(max_n);
    for (int i = 0; 11 * i < max_n; i++) {
        for (int j = 0; 11 * i + 111 * j < max_n; j++) {
            for (int k = 0; 11 * i + 111 * j + 1111 * k < max_n; k++) {
                can[11 * i + 111 * j + 1111 * k] = true;
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << (x >= max_n || can[x] ? "YES\n" : "NO\n");
    }
}