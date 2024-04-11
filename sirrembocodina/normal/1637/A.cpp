#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i && a[i] < a[i - 1]) {
                ok = false;
            }
        }
        cout << (!ok ? "YES\n" : "NO\n");
    }
    return 0;
}