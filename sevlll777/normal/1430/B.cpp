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
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        sort(A.rbegin(), A.rend());
        int s = 0;
        for (int i = 0; i <= k; i++) {
            s += A[i];
        }
        cout << s;
        cout << '\n';
    }
}