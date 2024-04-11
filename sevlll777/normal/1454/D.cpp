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
        int n;
        cin >> n;
        map<int, int> prim;
        while (n % 2 == 0) {
            n /= 2;
            prim[2]++;
        }
        int p = 3;
        while (p * p <= n) {
            while (n % p == 0) {
                n /= p;
                prim[p]++;
            }
            p += 2;
        }
        if (n != 1) {
            prim[n]++;
        }
        int ans = 0;
        for (auto x : prim) ans = max(ans, x.second);
        vector<int> h(ans, 1);
        for (auto x : prim) {
            for (int i = ans - 1; i >= ans - x.second; i--) h[i] *= x.first;
        }
        cout << ans << '\n';
        for (auto x : h) cout << x << ' ';
        cout << '\n';
    }


}