#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> k >> m;
        vector<int> B(m);
        for (int i = 0; i < m; i++) cin >> B[i];
        if ((n - m) % (k - 1)) {
            cout << "NO\n";
        } else {
            vector<bool> hh(n + 1);
            for (auto x : B) hh[x] = true;
            int cnt = 0;
            vector<int> C;
            for (int i = 1; i <= n; i++) {
                if (!hh[i]) {
                    cnt++;
                } else {
                    C.pb(cnt);
                    cnt = 0;
                }
            }
            if (cnt) C.pb(cnt);
            k -= 1;
            k /= 2;
            int sum = n-m, s = 0;
            for (auto x : C) {
                s += x;
                if (s >= k) {
                    if (sum-s >= k) {
                        cout << "YES\n";
                    } else {
                        cout << "NO\n";
                    }
                    break;
                }
            }
        }
    }

}