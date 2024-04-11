#include "bits/stdc++.h"

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int a, n;
        cin >> a >> n;
        vector<int> cnt(100);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            sum += x;
            int p = 0;
            while (x > 1) {
                p++;
                x /= 2;
            }
            cnt[p]++;
        }
        if (sum < a) {
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 0; i < 61; i++) {
            if (a & ((long long)(1) << i)) {
                if (cnt[i] == 0) {
                    while (cnt[i] == 0) {
                        i++;
                        ans++;
                    }
                    cnt[i]--;
                    i--;
                    continue;
                } else {
                    cnt[i]--;
                }
            }
            cnt[i + 1] += cnt[i] / 2;
        }
        cout << ans << endl;
    }
}