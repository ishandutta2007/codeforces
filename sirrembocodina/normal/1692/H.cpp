#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        }

        vector<int> cnt(n);
        vector<int> opt_l(n);
        vector<int> opt_dif(n);
        int ans = 0;
        int ans_l = 0, ans_r = 0;
        for (int i = 0; i < n; i++) {
            int cand = 2 * cnt[a[i]] - i;
            if (opt_dif[a[i]] > cand) {
                opt_dif[a[i]] = cand;
                opt_l[a[i]] = i;
            }
            cnt[a[i]]++;

            cand = 2 * cnt[a[i]] - (i + 1) - opt_dif[a[i]];
            if (ans < cand) {
                ans = cand;
                ans_r = i + 1;
                ans_l = opt_l[a[i]];
            }
        }

        cout << b[a[ans_l]] << ' ' << ans_l + 1 << ' ' << ans_r << '\n';
    }
}