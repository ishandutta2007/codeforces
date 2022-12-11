#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0);
    if (sum == 0) {
        cout << "NO\n";
        return;
    }
    sort(a.begin(), a.end());
    if (sum > 0) reverse(a.begin(), a.end());
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef SERT
    freopen("a.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
        solve();
}