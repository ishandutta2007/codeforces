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
        bool is_pow = false;
        for (int i = 1, cur = 2; i <= 50; i++, cur *= 2) {
            if (cur == n) {
                is_pow = true;
                break;
            }
        }
        if (is_pow) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}