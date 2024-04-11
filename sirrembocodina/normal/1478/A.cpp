#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cnt(101);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int mx = 0;
        for (int i = 0; i < cnt.size(); i++) {
            mx = max(mx, cnt[i]);
        }
        cout << mx << endl;
    }
}