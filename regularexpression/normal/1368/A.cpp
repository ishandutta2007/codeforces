#include<bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, n;
        cin >> a >> b >> n;
        int aa = a, bb = b;
        int ans1 = 0;
        bool f = 0;
        while (a <= n && b <= n) {
            if (f) {
                a += b;
            } else {
                b += a;
            }
            f = !f;
            ans1++;
        }
        int ans2 = 0;
        f = 1;
        a = aa;
        b = bb;
        while (a <= n && b <= n) {
            if (f) {
                a += b;
            } else {
                b += a;
            }
            f = !f;
            ans2++;
        }
        cout << min(ans1, ans2) << '\n';
    }
    return 0;
}