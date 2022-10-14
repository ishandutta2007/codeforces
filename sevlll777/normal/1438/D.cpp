#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    if (n % 2 == 0) {
        int xr = 0;
        for (auto y : A) xr ^= y;
        if (xr != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << n-2 << '\n';
            for (int x = 2; x < n; x+=2) {
                cout << "1 " << x << ' ' << x + 1 << '\n';
            }
            for (int x = 2; x < n; x+=2) {
                cout << "1 " << x << ' ' << x + 1 << '\n';
            }
        }
    } else {
        cout << "YES\n";
        cout << n-1 << '\n';
        for (int x = 2; x <= n; x+=2) {
            cout << "1 " << x << ' ' << x + 1 << '\n';
        }
        for (int x = 2; x <= n; x+=2) {
            cout << "1 " << x << ' ' << x + 1 << '\n';
        }
    }
}