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
        int c1, c2, c3;
        int a1, a2, a3, a4, a5;
        cin >> c1 >> c2 >> c3 >> a1 >> a2 >> a3 >> a4 >> a5;
        c1 -= a1;
        c2 -= a2;
        c3 -= a3;
        if (min({c1, c2, c3}) < 0) {
            cout << "NO\n";
        } else {
            a4 -= c1;
            a5 -= c2;
            if (max(0LL,a4)+max(0LL,a5)<=c3) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}