#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l == r) {
            cout << k - 1 << '\n';
        } else if (l + 1 == r) {
            cout << A[r] - 2 + k - A[l] - 1 << '\n';
        } else {
            int ans = -2 * (r - l + 1) + 1;
            ans -= A[l];
            ans += k + A[r];
            cout << ans << '\n';
        }
    }

}