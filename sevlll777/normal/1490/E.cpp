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
    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        B.pb({A[i], i});
    }
    if (n == 1) {
        cout << "1\n1\n";
        return;
    }
    sort(all(B));
    int pr = B[0].first;
    int ai = 1;
    for (int i = 1; i < n - 1; i++) {
        pr += B[i].first;
        if (pr < B[i + 1].first) {
            ai = i + 1;
        }
    }
    if (ai == 1) {
        if (B[0].first == B[1].first) {
            ai = 0;
        }
    }
    vector<int> ans;
    for (int i = ai; i < n; i++) ans.pb(B[i].second);
    sort(all(ans));
    cout << ans.size() << '\n';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
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