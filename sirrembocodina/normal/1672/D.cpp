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
        vector<int> a(n), b(n);
        for (int& x: a) {
            cin >> x;
        }
        for (int& x: b) {
            cin >> x;
        }
        vector<int> cnt(n + 1);
        int j = n - 1;
        int last = -1;
        bool ok = true;
        for (int i = n - 1; i >= 0; i--) {
            while (j >= 0 && b[j] != a[i] && b[j] == last) {
                cnt[b[j]]++;
                j--;
            }
            if (j >= 0 && b[j] == a[i]) {
                last = a[i];
                j--;
                continue;
            }
            if (cnt[a[i]]) {
                cnt[a[i]]--;
                last = a[i];
                continue;
            }
            ok = false;
            break;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}