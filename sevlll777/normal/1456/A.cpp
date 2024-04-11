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
        int n, p, k, x, y;
        string a;
        cin >> n >> p >> k >> a >> x >> y;
        vector<vector<int>> heh(k);
        for (int r = 0; r < k; r++) {
            heh[r] = {0};
            for (int i = r; i < n; i += k) {
                heh[r].pb(heh[r].back() + (a[i] == '0'));
            }
        }
        int ans = 1e18;
        for (int i = p-1; i < n; i++) {
            int cost = (i - p+1) * y;
            int r = i % k;
            int l = i / k;
            cost += x * (heh[r].back() - heh[r][l]);
            ans = min(ans, cost);
        }
        cout << ans << '\n';
    }
}