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
    int t0;
    cin >> t0;
    while (t0--) {
        int n, d;
        cin >> n >> d;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.begin(), A.end());
        if (A[n - 1] <= d || A[0] + A[1] <= d) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}