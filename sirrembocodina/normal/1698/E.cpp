#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int mod = 998244353;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n), b(n);
        vector<int> wa(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            wa[a[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] > 0) {
                b[i]--;
            }
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = b[wa[i]];
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (p[i] != -1 && i > p[i] + s) {
                ok = false;
            }
        }
        if (!ok) {
            cout << "0\n";
            continue;
        }
        vector<bool> was(n);
        for (int i = 0; i < n; i++) {
            if (p[i] != -1) {
                was[p[i]] = true;
            }
        }
        vector<int> skipped;
        for (int i = 0; i < n; i++) {
            if (!was[i]) {
                skipped.push_back(i);
            }
        }
        vector<int> emp(n + 1);
        for (int i = 0; i < n; i++) {
            emp[i + 1] = emp[i] + (p[i] == -1);
        }
        int ans = 1;
        for (int i = 0; i < skipped.size(); i++) {
            if (emp[min(n, skipped[i] + s + 1)] < i + 1) {
                ans = 0;
            } else {
                (ans *= emp[min(n, skipped[i] + s + 1)] - i) %= mod;
            }
        }
        cout << ans << '\n';
    }
}