#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b; cin >> a >> b;
        vector<int> diff(n);
        for (int i = 0; i < n; ++i) diff[i] = (a[i] != b[i] ? 1 : 0);
        int diffsum = accumulate(begin(diff), end(diff), 0);
        if (diffsum != 0 && diffsum != n) {
            cout << "NO\n"; continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') ans.emplace_back(i, i);
        }
        // init diff is 0 and we do even ops
        // init diff is 1 and we do odd ops
        if ((diffsum == 0) == (ans.size() % 2 == 0)) {
            // do nothing
        } else {
            ans.emplace_back(0, n-1);
            ans.emplace_back(0, 0);
            ans.emplace_back(1, n-1);
        }
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto [l, r] : ans) cout << l + 1 << " " << r + 1 << "\n";
    }
}