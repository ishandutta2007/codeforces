#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int x = 1;
        int p = 0;
        while (x <= 1e16) {
            x *= k;
            p++;
        }
        vector<int> pows = {1};
        for (int i = 0; i < p; i++) pows.pb(k * pows.back());
        vector<int> lol(p+1);
        string ans = "YES\n";
        for (auto w : A) {
            for (int i = p; i >= 0; i--) {
                if (w >= pows[i]) {
                    w -= pows[i];
                    lol[i]++;
                    if (lol[i] >= 2) ans = "NO\n";
                }
            }
            if (w != 0) ans = "NO\n";
        }
        cout << ans;
    }
}