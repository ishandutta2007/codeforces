#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        map<int, int> sum;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            while (a > 0 && a % 2 == 0) {
                a /= 2;
            }
            while (true) {
                sum[a]--;
                if (a == 0) {
                    break;
                }
                a /= 2;
            }
        }
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            while (true) {
                sum[b]++;
                if (b == 0) {
                    break;
                }
                b /= 2;
            }
        }
        bool ok = true;
        for (auto kv: sum) {
            if (kv.second < 0) {
                ok = false;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}