#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
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
        vector<int> B(n);
        for (int i = 0; i < n; i++) cin >> B[i];
        map<int, int> heh;
        heh[B[0]] = 1;
        int dobavka = 0;
        int s = 1;
        for (int i = 1; i < n; i++) {
            int s2 = 2 * s - heh[-dobavka];
            s2 += M;
            s2 %= M;
            heh[-dobavka] = s;
            dobavka += B[i];
            s = s2;
        }
        int ans = 0;
        for (auto x : heh) {
            ans += x.second;
            ans %= M;
        }
        ans %= M;
        cout << ans << '\n';
    }

}