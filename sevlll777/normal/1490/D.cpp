#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;
vector<int> ans;

void f(vector<int> a, int cnt) {
    if (a.empty()) {
        return;
    }
    int m = 0;
    for (auto x : a) m = max(m, x);
    for (int i = 0; i < (int) a.size(); i++) {
        if (a[i] == m) {
            vector<int> b, c;
            for (int j = 0; j < i; j++) b.pb(a[j]);
            for (int j = i + 1; j < (int) a.size(); j++) c.pb(a[j]);
            ans[a[i]] = cnt;
            f(b, cnt + 1);
            f(c, cnt + 1);
            return;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    ans.assign(n + 1, 0);
    f(A, 0);
    for (int i = 0; i < n; i++) cout << ans[A[i]] << ' ';
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