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
        vector<int> A(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        vector<int> cnt(n + 1), sas(n + 1);
        for (int i = 0; i < n - 1; i++) {
            if (A[i] == A[i + 1]) sas[A[i]]++;
        }
        for (auto x : A) cnt[x]++;
        int ans = 1e9;
        for (int x = 1; x <= n; x++) {
            if (cnt[x] != 0) {
                ans = min(ans, 1+cnt[x] - (x == A[0]) - (x == A[n-1]) - sas[x]);
            }
        }
        cout << ans;
        cout << '\n';
    }


}