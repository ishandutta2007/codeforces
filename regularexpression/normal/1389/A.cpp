#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (l * 2 > r) cout << "-1 -1\n"; else cout << l << " " << l * 2 << '\n';
    }
    return 0;
}