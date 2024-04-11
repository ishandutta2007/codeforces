#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int ma = 0, mb = 0;
    for (int i = 0; i < k1; ++i) {
        int a;
        cin >> a;
        ma = max(ma, a);
    }
    for (int i = 0; i < k2; ++i) {
        int b;
        cin >> b;
        mb = max(mb, b);
    }
    if (ma > mb) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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