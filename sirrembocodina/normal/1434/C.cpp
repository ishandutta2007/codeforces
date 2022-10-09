#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int f(int a, int b, int c, int d, int k) {
    if (k * d > c || k < 0) {
        return -1;
    }
    return a * (k + 1) - b * d * k * (k + 1) / 2;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        /*a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        c = rand() % 10 + 1;
        d = rand() % 10 + 1;*/
        if (a > b * c) {
            cout << -1 << endl;
            continue;
        }
        /*int mx = 0, cnt = 0, cur = 0;
        for (int i = 0; i <= c; i++) {
            cur -= cnt * b;
            if (i % d == 0) {
                cur += a;
                cnt++;
            }
            mx = max(mx, cur);
            cerr << cur << ' ';
        }
        cerr << endl;*/
        int ans = 0;
        ans = max(ans, f(a, b, c, d, 0));
        ans = max(ans, f(a, b, c, d, c / d));
        ans = max(ans, f(a, b, c, d, (2 * a - b * d) / (2 * b * d)));
        ans = max(ans, f(a, b, c, d, (2 * a - b * d) / (2 * b * d) + 1));
        cout << ans << endl;
    }
}