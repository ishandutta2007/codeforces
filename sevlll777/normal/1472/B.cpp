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
        int a = 0, b = 0;
        while (n--) {
            char x;
            cin >> x;
            a += (x == '1');
            b += (x == '2');
        }
        if (a % 2 == 0) {
            if (b % 2 == 0 || a >= 2) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        } else {
            cout << "NO";
        }
        cout << '\n';
    }

}