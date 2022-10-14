#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cnt[A[i] % 3]++;
    }
    int ans = 0;
    for (int _ = 0; _ < 22; _++) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i] > n / 3) {
                cnt[(i + 1) % 3] += cnt[i] - n / 3;
                ans += cnt[i] - n / 3;
                cnt[i] = n / 3;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}