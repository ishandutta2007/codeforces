#include <bits/stdc++.h>
using namespace std;

bool D = false;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int64_t ans = 0;
    for (int &x : a)
        cin >> x;
    vector<int> dif(n + 2, 0);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += dif[i];
        if (a[i] > 1 && a[i] + i < n) dif[a[i] + i + 1]--;
        if (a[i] > 1) dif[i + 2]++;
        int x = max(0, tot - a[i] + 1);
        dif[i + 1] += x;
        dif[i + 2] -= x;
        ans += max(0, a[i] - tot - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
#ifdef SERT
    freopen("../a.in", "r", stdin);
    D = true;
#endif
    cin >> t;
    while (t--)
        solve();
}