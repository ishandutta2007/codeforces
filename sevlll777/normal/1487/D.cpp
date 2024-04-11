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
        int n;
        cin >> n;
        int ans = 0;
        for (int c = 3; c <= 100500; c += 2) {
            int x = c * c / 2;
            if (x <= n - 1) {
                ans++;
            } else {
                break;
            }
        }
        cout << ans << '\n';
    }

}