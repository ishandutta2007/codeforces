#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (s.find(a[i] + k) != s.end()) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}