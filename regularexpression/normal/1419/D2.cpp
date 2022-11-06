#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    int l = 0, r = (n - 1) / 2 + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<int> aa, bb;
        for (int i = 0; i < m; ++i) aa.push_back(a[i]);
        for (int i = n - 1; i >= n - m - 1; --i) bb.push_back(a[i]);
        reverse(bb.begin(), bb.end());
        bool ok = 1;
        for (int i = 0; i < m; ++i) ok &= aa[i] < bb[i];
        ok &= aa.back() < bb.back();
        if (ok) l = m; else r = m;
    }
    cout << l << '\n';
    if (l == 0) {
        for (auto elem : a) cout << elem << " ";
    } else {
        vector<int> aa, bb;
        for (int i = 0; i < l; ++i) aa.push_back(a[i]);
        for (int i = n - 1; i >= n - l - 1; --i) bb.push_back(a[i]);
        reverse(bb.begin(), bb.end());
        for (int i = 0; i < l; ++i) {
            cout << bb[i] << " " << aa[i] << " ";
        }
        cout << bb.back() << " ";
        for (int i = l; i < n - l - 1; ++i) cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}