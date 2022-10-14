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
        cin >> n;
        k = 2;
        m = 3;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        int r = 0;
        int ans = 0;
        for (int l = 0; l < n; l++) {
            while (r < A.size() && A[r] <= k + A[l]) {
                r++;
            }
            int num = r - l - 1;
            ans += num * (num - 1) / 2;
        }
        cout << ans << '\n';
    }
}