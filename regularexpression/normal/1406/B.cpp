#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18 + 239;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> pos, neg;
        bool zero = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a < 0) neg.push_back(-a);
            if (a > 0) pos.push_back(a);
            if (a == 0) zero = 1;
        }
        int ans = zero ? 0 : -INF;
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        for (int i = 0; i <= 5 && i <= pos.size(); ++i) {
            int j = 5 - i;
            if (j > neg.size()) continue;
            int cur = 1;
            if (j & 1) {
                cur = -1;
                for (int k = 0; k < i; ++k) cur *= pos[k];
                for (int k = 0; k < j; ++k) cur *= neg[k];
            } else {
                for (int k = 0; k < i; ++k) cur *= pos[(int)pos.size() - k - 1];
                for (int k = 0; k < j; ++k) cur *= neg[(int)neg.size() - k - 1];
            }
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
    return 0;
}