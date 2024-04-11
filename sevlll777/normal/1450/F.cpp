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
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            cnt[A[i]]++;
        }
        int ans = 0;
        vector<int> c2(n + 1);
        vector<int> k = {A[0]};
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) {
                k.pb(A[i]);
                ans++;
            }
        }
        k.pb(A[n - 1]);
        int m = 0, col = 0;
        for (int i = 1; i < k.size(); i++) {
            if (k[i - 1] == k[i]) {
                c2[k[i]]++;
                if (m < c2[k[i]]) {
                    m = c2[k[i]];
                    col = k[i];
                }
            }
        }
        int s = (int) k.size() - 1;
        for (int i = 1; i < k.size(); i++) {
            if (k[i] == col || k[i - 1] == col) s--;
        }
        ans += max(0LL, m-1-s);
        for (auto x : cnt) {
            if (x > (n + 1) / 2) {
                ans = -1;
                break;
            }
        }
        cout << ans << '\n';
    }
}
/*
 * 1
13
1 1 3 1 1 2 3 2 3 2 3 1 1
 */