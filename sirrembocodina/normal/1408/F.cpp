#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int p = 1;
    while (p * 2 <= n) {
        p *= 2;
    }
    vector<pair<int, int>> ans;
    for (int l = 2; l <= p; l *= 2) {
        for (int s = 0; s < p; s += l) {
            forn (i, l / 2) {
                ans.push_back({s + i, s + i + l / 2});
            }
        }
    }
    if (p < n) {
        cout << 2 * ans.size() << endl;
    } else {
        cout << ans.size() << endl;
    }
    forn (i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    if (p < n) {
        forn (i, ans.size()) {
            cout << ans[i].first + 1 + n - p << " " << ans[i].second + 1 + n - p << endl;
        }
    }
}