#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> A;
    vector<pair<int, vector<int>>> huh;
    for (int j = 0; j < m; j++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        vector<int> bek(n);
        for (int i = 0; i < n; i++) {
            bek[i] = max(0, 1 + min(i + k - 1, r) - max(i, l));
        }
        huh.pb({l + r, bek});
    }
    sort(huh.begin(), huh.end());
    for (auto p : huh) A.pb(p.second);
    int ans = 0;
    vector<int> S(n), R(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            R[j] += A[i][j];
        }
    }
    for (auto x : R) ans = max(ans, x);
    for (int b = 0; b < m; b++) {
        int ss = 0, rr = 0;
        for (int j = 0; j < n; j++) {
            S[j] += A[b][j];
            R[j] -= A[b][j];
            ss = max(ss, S[j]);
            rr = max(rr, R[j]);
        }
        ans = max(ans, ss + rr);
    }
    cout << ans << '\n';
}