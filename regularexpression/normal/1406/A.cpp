#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 107;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(N, 0);
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ++cnt[a];
        }
        int pos = 0;
        while (cnt[pos] > 0) {
            --cnt[pos];
            ++pos;
        }
        int ans = pos;
        pos = 0;
        while (cnt[pos] > 0) ++pos;
        ans += pos;
        cout << ans << '\n';
    }
    return 0;
}