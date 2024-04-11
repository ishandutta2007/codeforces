#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j != 0) cout << " ";
            cout << ((j & 1) * (1LL << (i + j)));
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        int x = 0, y = 0;
        vector<pair<int, int>> ans = {{0, 0}};
        for (int i = 0; i < 2 * (n - 1); ++i) {
            if (x == n - 1) {
                y++;
                ans.emplace_back(x, y);
                continue;
            }
            if (y == n - 1) {
                x++;
                ans.emplace_back(x, y);
                continue;
            }
            if (((k >> (i + 1)) & 1) == (y & 1)) {
                ++x;
            } else ++y;
            ans.emplace_back(x, y);
        }
        for (auto elem : ans) cout << elem.first + 1 << " " << elem.second + 1 << endl;
    }
    return 0;
}