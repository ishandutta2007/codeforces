#include <bits/stdc++.h>
#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> cnt(n); //   -  
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x--;
            if (i < l) {
                cnt[x]++;
            } else {
                cnt[x]--;
            }
        }
        int sum_l = 0, sum_r = 0, odd_l = 0, odd_r = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] == 0) {
                continue;
            }
            if (cnt[i] > 0) {
                sum_l += cnt[i];
                if (cnt[i] % 2 == 1) {
                    odd_l++;
                }
            } else {
                cnt[i] *= -1;
                sum_r += cnt[i];
                if (cnt[i] % 2 == 1) {
                    odd_r++;
                }
            }
        }
        int ans = (sum_l + sum_r) / 2;
        int odd_pairs = min(odd_l, odd_r);
        odd_l -= odd_pairs;
        odd_r -= odd_pairs;
        sum_l -= odd_pairs;
        sum_r -= odd_pairs;
        if (odd_l > 0 && sum_r < odd_l) {
            ans += (odd_l - sum_r) / 2;
        }
        if (odd_r > 0 && sum_l < odd_r) {
            ans += (odd_r - sum_l) / 2;
        }
        cout << ans << endl;
    }
}