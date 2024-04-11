#include <bits/stdc++.h>

#define pb push_back
// #define int long long
#define ld long double
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        set<int> A;
        while (n--) {
            int x;
            cin >> x;
            A.insert(x);
        }
        int ans = 0;
        while (m--) {
            int y;
            cin >> y;
            if (A.find(y) != A.end()) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
}