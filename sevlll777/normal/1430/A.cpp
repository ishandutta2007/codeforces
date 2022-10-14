#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define ld long double
using namespace std;
const int M = 1000000007;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n < 3 || n == 4) {
            cout << -1;
        } else if (n % 3 == 0) {
            cout << n / 3 << " 0 0";
        } else if (n % 3 == 1) {
            cout << n/3-2 << ' ' << 0 << ' ' << 1;
        } else {
            cout << n/3-1 << ' ' << "1 0";
        }
        cout << '\n';
    }
}