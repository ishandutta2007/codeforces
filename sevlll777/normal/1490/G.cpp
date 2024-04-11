#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1), P(n + 1), MAXP(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
        MAXP[i] = max(MAXP[i - 1], P[i]);
        mx = max(mx, P[i]);
    }
    int sum = P[n];
    while (m--) {
        int x;
        cin >> x;
        if (x > mx && sum <= 0) {
            cout << "-1\n";
        } else if (x <= mx) {
            int l = (int) (lower_bound(all(MAXP), x) - MAXP.begin());
            cout << l - 1 << '\n';
        } else {
            int w = (x - mx + sum - 1) / sum;
            int ans = n * w;
            x -= sum * w;
            int l = (int) (lower_bound(all(MAXP), x) - MAXP.begin());
            ans += l - 1;
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}