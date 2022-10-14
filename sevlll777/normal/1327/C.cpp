#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fro for
#define pb push_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string ans = "";
    for (int i = 0; i < m; i++) {
        fro (int _ = 0; _ < n - 1; _++) {
            if (i %2 == 0) {
                ans += 'D';
            } else {
                ans += 'U';
            }
        }
        if (i != m - 1) {
            ans += 'R';
        }
    }
    for (int i = 0; i < m; i++) {
        fro (int _ = 0; _ < n - 1; _++) {
            if (i %2 == 0) {
                ans += 'U';
            } else {
                ans += 'D';
            }
        }
        if (i != m - 1) {
            ans += 'L';
        }
    }
    cout << ans.size() << '\n' << ans;
}