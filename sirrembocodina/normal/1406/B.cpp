#include <bits/stdc++.h>
#define int int64_t

using namespace std;

bool cmp(int a, int b) {
    return abs(a) < abs(b);
}

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
        if (n == 5) {
            cout << a[0] * a[1] * a[2] * a[3] * a[4] << endl;
            continue;
        }
        sort(a.begin(), a.end(), cmp);
        reverse(a.begin(), a.end());
        int ans = a[0] * a[1] * a[2] * a[3] * a[4];
        if (ans >= 0) {
            cout << ans << endl;
            continue;
        }
        bool was_pos = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                was_pos = true;
            }
        }
        if (!was_pos) {
            reverse(a.begin(), a.end());
            cout << a[0] * a[1] * a[2] * a[3] * a[4] << endl;
            continue;
        }
        int mx_pos = -1;
        int mx_neg = -1;
        for (int i = 5; i < n; i++) {
            if (a[i] < 0) {
                mx_neg = max(mx_neg, -a[i]);
            }
            if (a[i] > 0) {
                mx_pos = max(mx_pos, a[i]);
            }
        }
        int mn_pos = 2e9;
        int mn_neg = 2e9;
        for (int i = 0; i < 5; i++) {
            if (a[i] < 0) {
                mn_neg = min(mn_neg, -a[i]);
            }
            if (a[i] > 0) {
                mn_pos = min(mn_pos, a[i]);
            }
        }
        int ans_final = ans;
        if (a.back() == 0) {
            ans_final = 0;
        }
        if (mn_pos < 2e9 && mx_neg > -1) {
            ans_final = max(ans_final, -ans / mn_pos * mx_neg);
        }
        if (mn_neg < 2e9 && mx_pos > -1) {
            ans_final = max(ans_final, -ans / mn_neg * mx_pos);
        }
        cout << ans_final << endl;
    }
}