#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        int s = 0;
        for (int i = 0; i < n - 1; i++) s += (abs(A[i] - A[i + 1]));
        int ans = s;
        for (int i = 0; i < n; i++) {
            int wl = 0;
            if (i >= 1 && i < n - 1) wl = abs(A[i + 1] - A[i - 1]);
            int ws = 0;
            if (i >= 1) {
                ws += abs(A[i] - A[i - 1]);
            }
            if (i < n - 1) {
                ws += abs(A[i] - A[i + 1]);
            }
            ans = min(ans, s + wl - ws);
        }
        cout << ans << '\n';
    }
}