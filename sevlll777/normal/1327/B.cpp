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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> can(n, true);
        int a = -1, b = -1;
        bool clown = false;
        for (int _ = 0; _ < n; _++) {
            int k;
            cin >> k;
            bool f = false;
            for (int __ = 0; __ < k; __++) {
                int x;
                cin >> x;
                x--;
                if (!f && can[x] == true) {
                    can[x] = false;
                    f = true;
                }
            }
            if (!f) {
                a = _+1;
            }
        }
        if (a != -1) {
            for (int g = 0; g < n; g++) {
                if (can[g]) {
                    b = g + 1;
                    clown = true;
                    break;
                }
            }
        }
        if (clown) {
            cout << "IMPROVE\n" << a << ' ' << b << '\n';
        } else {
            cout << "OPTIMAL\n";
        }
    }
}