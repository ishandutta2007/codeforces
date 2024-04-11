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
        vector<int> B;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                B.pb(A[j/2]);
            } else {
                B.pb(A[n-1-j/2]);
            }
            cout << B[j] << ' ';
        }
        cout << '\n';
    }
}