#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, d, w;
        cin >> m >> d >> w;
        if (d == 1) {
            cout << "0\n";
            continue;
        }
        int g = __gcd(w, d - 1);
        w /= g;
        int n = min(m, d);
        cout << n * (n / w) - (n / w) * (n / w + 1) / 2 * w << '\n';
    }
    return 0;
}