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
        vector<int> cnt(n + 1);
        for (auto x : A) cnt[x]++;
        vector<bool> ans(n + 1, false);
        ans[1] = true;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                ans[1] = false;
            }
        }
        int l = 0, r = n - 1;
        for (int el = 1; el <= n; el++) {
            if (cnt[el] == 0) {
                break;
            }
            if (A[l] == A[r] && A[l] == el) {
                ans[n+1-el] = true;
                break;
            }
            if (cnt[el] != ((A[l] == el) + (A[r] == el))) {
                ans[n+1-el] = true;
                break;
            }
            if (A[l] == el) {
                ans[n+1-el] = true;
                l++;
            } else if (A[r] == el) {
                ans[n+1-el] = true;
                r--;
            }
        }
        for (int i = 1; i <= n; i++) cout << ans[i];
        cout << '\n';
    }
}