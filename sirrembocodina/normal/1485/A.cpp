#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 2e9;
        for (int i = 0; i <= 31; i++, b++) {
            if (b == 1) {
                continue;
            }
            int cnt = 0;
            int a_copy = a;
            while (a_copy > 0) {
                a_copy /= b;
                cnt++;
            }
            ans = min(ans, i + cnt);
        }
        cout << ans << endl;
    }
}