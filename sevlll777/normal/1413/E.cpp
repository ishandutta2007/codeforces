#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244853;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int e = (c + d - 1) / d;
        if (a > b * c) {
            cout << "-1\n";
        } else {
            int l = a * (e + 1);
            int r = b * (d * e * (e - 1) / 2 + c);
            int ANS = max(0LL, l - r);
            l = -1;
            r = e;
            int x = min(a / (b * d), e - 1);
            for (int ep = -10; ep <= 10; ep++) {
                if (x + ep >= 0 && x + ep < e) {
                    ANS = max(ANS, a * ((x + ep) + 1) - b * d * ((x + ep) * ((x + ep) + 1) / 2));
                }
            }
            cout << ANS << '\n';
        }
    }
}