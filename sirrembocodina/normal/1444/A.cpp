#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int old_b = b;
        vector<int> p;
        for (int i = 2; i * i <= b; i++) {
            if (b % i) {
                continue;
            }
            p.push_back(i);
            while (b % i == 0) {
                b /= i;
            }
        }
        if (b > 1) {
            p.push_back(b);
        }
        b = old_b;
        int ans = 1;
        for (auto pr: p) {
            int cur = a;
            while (cur % b == 0) {
                cur /= pr;
            }
            ans = max(ans, cur);
        }
        cout << ans << endl;
    }
}