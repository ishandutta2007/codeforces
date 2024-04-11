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
        sort(A.begin(), A.end());
        int s = 0;
        for (auto x : A) s += x;
        int ans = 0;
        if (s % (n - 1)) {
            ans += (n - 1 - (s % (n - 1)));
            s += (n - 1 - (s % (n - 1)));
        }
        ans += max(0LL, (n - 1) * A[n - 1] - s);
        cout << ans;
        cout << '\n';
    }
}