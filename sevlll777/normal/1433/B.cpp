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
        int n;
        cin >> n;
        vector<char> A(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            ans += (A[i] == '0');
        }
        int p = 0, s = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] == '0') {
                p++;
            } else {
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (A[i] == '0') {
                s++;
            } else {
                break;
            }
        }
        ans -= (p + s);
        cout << ans << '\n';
    }
}