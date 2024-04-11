#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int maxd = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxd = max(maxd, a[i]);
        if (a[i] == x) {
            ans = -1;
        }
    }
    if (ans == -1) {
        cout << "1\n";
        return;
    }
    ans = x / maxd;
    if (x % maxd > 0) {
        if (ans == 0) {
            ++ans;
        }
        ++ans;
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}