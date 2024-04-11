#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
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
        map<int, int> cnt;
        for (auto x : A) cnt[x]++;
        vector<int> C;
        for (auto p : cnt) C.pb(p.second);
        sort(all(C));
        int s = 0, ans = (int) 1e9;
        for (int i = 0; i < (int) C.size(); i++) {
            ans = min(ans, s + (n - s - C[i]) - C[i] * ((int) C.size() - 1 - i));
            s += C[i];
        }
        cout << ans << '\n';
    }
}