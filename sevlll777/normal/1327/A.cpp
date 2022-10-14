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
        int n, k;
        cin >> n >> k;
        if (k*k > n) {
            cout << "NO\n";
        } else {
            int j = n - k * k;
            if (j % 2 == 1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
}