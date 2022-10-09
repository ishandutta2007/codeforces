#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> pos;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                pos.push_back(i);
            }
        }
        if (pos.size() % 2) {
            cout << -1 << '\n';
        } else if (pos.size() == 2 && pos[0] + 1 == pos[1]) {
            cout << min(x, 2 * y) << '\n';
        } else {
            cout << pos.size() / 2 * y << '\n';
        }
    }
}