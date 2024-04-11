#include <bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double
using namespace std;
const int M = 998244353;

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
        reverse(A.begin(), A.end());
        for (auto x : A) cout << x << ' ';
        cout << '\n';
    }
}