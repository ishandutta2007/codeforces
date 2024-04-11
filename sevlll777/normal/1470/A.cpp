#include <bits/stdc++.h>

#define pb push_back
#define int long long
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
        int n, m;
        cin >> n >> m;
        vector<int> K(n);
        for (int i = 0; i < n; i++) {
            cin >> K[i];
            K[i]--;
        }
        vector<int> C(m);
        for (int i = 0; i < m; i++) {
            cin >> C[i];
        }
        sort(K.rbegin(), K.rend());
        int ans = 0, u = 0;
        for (auto x : K) {
            if (u <= x) {
                ans += C[u];
                u++;
            } else {
                ans += C[x];
            }
        }
        cout << ans;
        cout << '\n';
    }
}