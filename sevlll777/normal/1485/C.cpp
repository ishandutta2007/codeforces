#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        int b = (int) ceil(sqrt(x + 2));
        b = min(b, y+1);
        int ans = 0;
        ans += (b - 1) * b / 2 - (b - 1);
        for (int num = 1; num < b - 1; num++) {
            int r = x / num;
            int l = 0;
            if (x % (1 + num) == 0) {
                l = x / (1 + num) + 1;
            } else {
                l = (x + num) / (1 + num);
            }
            l = max(l, 1 + b);
            r = min(r, 1 + y);
            if (r >= l) {
                ans += (r - l + 1) * num;
            }
        }
        cout << ans << '\n';
    }

}